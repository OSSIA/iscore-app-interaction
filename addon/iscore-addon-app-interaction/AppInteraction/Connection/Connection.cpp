#include <AppInteraction/Connection/Connection.hpp>

namespace connection
{
Connection::Connection(std::string device_name):
    mDevice(std::make_unique<ossia::net::local_protocol>(), device_name)
{

}

Connection::Connection(const Connection &c):
    mDevice(std::make_unique<ossia::net::local_protocol>(), c.getDeviceName())
{

}

Connection::~Connection()
{

}

void Connection::sendInteraction(const std::string interaction)
{
    mDevice.getProtocol().update(mDevice);
    ossia::net::node_base * node_interac = ossia::net::find_node(mDevice, "/interaction");
    if (node_interac)
    {
        if (ossia::net::address_base * addr = node_interac->getAddress())
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
    return mDevice.getName();
}

}
