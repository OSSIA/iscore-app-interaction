#include "Connection.hpp"

using namespace connection;

Connection::Connection(std::string device_name):
    mDevice(std::make_unique<ossia::net::local_protocol>(), device_name)
{

}

Connection::~Connection()
{

}

std::vector<ossia::value> Connection::sendInteraction(const std::string interaction)
{
    mDevice.getProtocol().update(mDevice);
    std::vector<ossia::value> data_list;
    ossia::net::node_base * node_interac = net::find_node(mDevice, "/interaction");
    if (node_interac)
    {
        if (ossia::net::address_base * addr = node_interac->getAddress())
        {
            addr->pushValue(interaction);
            addr->add_callback([&data_list] (const ossia::value& val)
            {
                data_list.push_back(val);
            });
        }
    }
    return data_list;
}

