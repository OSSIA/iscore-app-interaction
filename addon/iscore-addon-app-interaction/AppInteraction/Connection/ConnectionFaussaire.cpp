#include "ConnectionFaussaire.hpp"
#include <State/Value.hpp>

using namespace connectionFaussaire;

ConnectionFaussaire::ConnectionFaussaire(const std::string device_name):
    mDevice(std::make_unique<ossia::net::local_protocol>(), device_name),
    mDeviceName(device_name)
{
    qDebug("New Connection named %s opened.", mDeviceName.c_str());
}


ConnectionFaussaire::~ConnectionFaussaire(){
}

const std::string ConnectionFaussaire::getDeviceName() const
{
    return mDeviceName;
}

void ConnectionFaussaire::sendInteraction(const std::string interaction){

    qDebug("Interaction msg : %s, sent to %s. ", interaction.c_str(),mDeviceName.c_str());

    int index = std::stoi(interaction.substr(0, interaction.find_last_of(':')));
    float duration = std::stof(interaction.substr(interaction.find_first_of(':')+1 , interaction.find_last_of(':')-interaction.find_first_of(':')-1));
    int type =  std::stoi(interaction.substr(interaction.find_last_of(':')+1));

    qDebug("Interaction index : %d, Interaction duration : %f, Type wanted : %d",index,duration,type);

    const ossia::value val = ossia::value((float)0.1);
    emit interactionValueReturned(val);

    return;
}

ossia::net::generic_device& ConnectionFaussaire::getMDevice(){
    return mDevice;
}
