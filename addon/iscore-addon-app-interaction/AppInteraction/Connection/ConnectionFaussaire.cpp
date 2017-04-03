#include "ConnectionFaussaire.hpp"
#include <State/Value.hpp>

using namespace connectionFaussaire;

ConnectionFaussaire::ConnectionFaussaire(const std::string device_name):
    mDevice(std::make_unique<ossia::net::local_protocol>(), device_name),
    mDeviceName(device_name)
{
    qDebug("New Connection named %s created.", mDeviceName.c_str());
}


ConnectionFaussaire::~ConnectionFaussaire(){
}

const std::string ConnectionFaussaire::getDeviceName() const
{
    //qDebug("GetDeviceName : ");
    //qDebug("Device name : %s", mDevice.getName());
    //return mDevice.getName();
    return mDeviceName;
}

void ConnectionFaussaire::sendInteraction(const std::string interaction){
    qDebug("SendInteraction : generating and emitting ossia values ...");
//    qDebug("Interaction msg : %s", interaction.c_str());

    //qDebug("Interaction sent to : %s", mDevice.getName()); /* SEGFAULT */
//    qDebug("Interaction sent to %s. ", mDeviceName.c_str());

//    int duration = std::stoi(interaction.substr(interaction.find_first_of(':')+1 , interaction.find_last_of(':')-interaction.find_first_of(':')-1));
//    int type =  std::stoi(interaction.substr(interaction.find_last_of(':')+1));
//    qDebug("Duration : %d", duration);
//    qDebug("Type wanted : %d.",type);

    for (int i=0; i<1;i++)
    {
        const ossia::value val = ossia::value((float)1);
        //qDebug("Ossia val : %f", val.get<float>());
        emit interactionValueReturned(val); /* SEGFAULT Resolved (maybe)*/
        //sleep(2);

    }

    qDebug("SendInteraction : end.");
    return;
}

ossia::net::generic_device& ConnectionFaussaire::getMDevice(){
    return mDevice;
}
