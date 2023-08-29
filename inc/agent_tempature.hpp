#ifndef AGENT_TEMPATURE_HPP
#define AGENT_TEMPATURE_HPP

#include "protocol.hpp"
#include "agent_sensor.hpp"

#include <unordered_map>
#include <string>

#include <boost/asio.hpp>

using boost::asio::ip::tcp;

namespace sb {

class AgentTempature : public AgentSensor{
public: 
    AgentTempature(std::string const& a_file_name);

    ~AgentTempature() noexcept = default;
    AgentTempature(AgentTempature const& a_other) = default;
    AgentTempature(AgentTempature&& a_other) = default;
    AgentTempature& operator=(AgentTempature const& a_other) = default;
    AgentTempature& operator=(AgentTempature&& a_other) = default;

    tcp::endpoint endpoint() const override;
    bool check_event(Protocol const& a_event, Protocol& a_command) override;

    int event_type() const override;

private:
    tcp::endpoint m_endpoint;
};

}//namespace sb

#endif // AGENT_TEMPATURE_HPP
