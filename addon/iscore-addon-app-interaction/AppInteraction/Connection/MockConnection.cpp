#include "MockConnection.hpp"
#include <State/Value.hpp>

using namespace mockConnection;

MockConnection::MockConnection(const std::string device_name):
    mDevice(std::make_unique<ossia::net::local_protocol>(), device_name),
    mDeviceName(device_name)
{
    qDebug("New Connection named %s opened.", mDeviceName.c_str());
}


MockConnection::~MockConnection(){
}

const std::string MockConnection::getDeviceName() const
{
    return mDeviceName;
}

void MockConnection::sendInteraction(const std::string interaction){

    qDebug("Interaction msg : %s, sent to %s. ", interaction.c_str(),mDeviceName.c_str());

    int index = std::stoi(interaction.substr(0, interaction.find_last_of(':')));
    float duration = std::stoi(interaction.substr(interaction.find_last_of(':')+1));

    qDebug("Interaction index : %d, Interaction duration : %f", index,duration);

    const ossia::value val = ossia::value(std::array<float,3>{{0.8, 0.4, 0.9}});

    emit interactionValueReturned(val);

    return;
}

ossia::net::generic_device& MockConnection::getMDevice(){
    return mDevice;
}
