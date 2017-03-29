#include "ConnectionFaussaire.hpp"
using namespace connectionFaussaire;

ConnectionFaussaire::ConnectionFaussaire(std::string device_name):
    mDevice(std::make_unique<ossia::net::local_protocol>(), device_name)
{
    qDebug("New Connection named %s created.", device_name.c_str());
}


ConnectionFaussaire::~ConnectionFaussaire(){
}

std::string ConnectionFaussaire::getDeviceName() const
{
    qDebug("GetDeviceName : ");
    qDebug("Device name : %s", mDevice.getName());
    return mDevice.getName();
}

void ConnectionFaussaire::sendInteraction(const std::string interaction){
    qDebug("SendInteraction:");
    qDebug("Interaction msg : %s", interaction.c_str());

    //qDebug("Interaction sent to : %s", mDevice.getName()); /* SEGFAULT */

    int duration = std::stoi(interaction.substr(interaction.find_first_of(':')+1 , interaction.find_last_of(':')-interaction.find_first_of(':')-1));
    int type =  std::stoi(interaction.substr(interaction.find_last_of(':')+1));
    qDebug("Duration : %d", duration);
    qDebug("Type wanted : %d.",type);

    //    for(int i=0; i<5;i++)
    //    {
    //        mRetValues.push_back(std::abs(qrand()) % 100);
    //    } /* SEGFAULT */


    //    emit interactionValueReturned(mRetValues[0]); /* SEGFAULT */

    qDebug("SendInteraction : end.");
}


std::vector<ossia::value>  ConnectionFaussaire::getMRetValues (){
    return mRetValues;
}

ossia::net::generic_device& ConnectionFaussaire::getMDevice(){
    return mDevice;
}
