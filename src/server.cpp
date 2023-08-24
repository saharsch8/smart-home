#include "server.hpp"

#include "session.hpp"

namespace sb {

Server::Server(boost::asio::io_context& a_io_context,
        tcp::endpoint const& a_sensor_endpoint, tcp::endpoint const& a_controler_endpoint)
: m_sensor_acceptor(a_io_context, a_sensor_endpoint)
, m_controler_acceptor(a_io_context, a_controler_endpoint)
{
    accept();
}

void Server::accept()
{
    m_sensor_acceptor.async_accept([this](boost::system::error_code ec, tcp::socket socket){
        if (!ec){
            std::make_shared<Session>(std::move(socket), m_subscribe_manager, true)->start();
        }//sensor state

        accept();});

    m_controler_acceptor.async_accept([this](boost::system::error_code ec, tcp::socket socket){
        if (!ec){
            std::make_shared<Session>(std::move(socket), m_subscribe_manager, false)->start();
        }//controller state

        accept(); });
}

}// namespace sb 
