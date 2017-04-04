#include <AppInteraction/Connection/Connection.hpp>

namespace connection
{
Connection::Connection(std::string device_name):
    m_Device(new ossia::net::generic_device(std::make_unique<ossia::net::local_protocol>(), device_name))
{

}

Connection::~Connection()
{
    delete m_Device;
    delete m_oscServ;
}

void Connection::sendInteraction(const std::string interaction)
{
    m_Device->getProtocol().update(*m_Device);
    ossia::net::node_base* node_interac = ossia::net::find_node(*m_Device, "/interaction");
    if (node_interac)
    {
        if (ossia::net::address_base* addr = node_interac->getAddress())
        {
            addr->pushValue(interaction);
            addr->add_callback([=] (const ossia::value& val)
            {
                emit interactionValueReturned(val);
            });
        }
    }
}

std::string Connection::getDeviceName() const
{
    return m_Device->getName();
}

void Connection::setServer(ossia::oscquery::oscquery_server_protocol* oscServ)
{
    m_oscServ = oscServ;
}
}
