#include "ConnectionFaussaire.hpp"

using namespace connectionFaussaire;

ConnectionFaussaire::ConnectionFaussaire(const std::string device_name):
    mDevice(std::make_unique<ossia::net::local_protocol>(), device_name),
    mDeviceName(device_name)/*,
    mRetValues({1,2,3})*/
{
    qDebug("New Connection named %s created.", mDeviceName.c_str());
}


ConnectionFaussaire::~ConnectionFaussaire(){
}

const std::string ConnectionFaussaire::getDeviceName() const
{
    qDebug("GetDeviceName : ");
    //qDebug("Device name : %s", mDevice.getName());
    //return mDevice.getName();
    return mDeviceName;
}

void ConnectionFaussaire::sendInteraction(const std::string interaction){
    qDebug("SendInteraction:");
    qDebug("Interaction msg : %s", interaction.c_str());

    //qDebug("Interaction sent to : %s", mDevice.getName()); /* SEGFAULT */
    qDebug("Interaction sent to %s. ", mDeviceName.c_str());

    int duration = std::stoi(interaction.substr(interaction.find_first_of(':')+1 , interaction.find_last_of(':')-interaction.find_first_of(':')-1));
    int type =  std::stoi(interaction.substr(interaction.find_last_of(':')+1));
    qDebug("Duration : %d", duration);
    qDebug("Type wanted : %d.",type);

//    for(int i=0; i<5;i++)
//    {
//        mRetValues.push_back(i);
//    }
//    qDebug("Print mRetValues : %d , %d , %d, %d, %d, %d, %d, %d",
//           mRetValues[0].get<int>(),
//            mRetValues[1].get<int>(),
//            mRetValues[2].get<int>(),
//            mRetValues[3].get<int>(),
//            mRetValues[4].get<int>(),
//            mRetValues[5].get<int>(),
//            mRetValues[6].get<int>(),
//            mRetValues[7].get<int>());

    for (int i=0; i<25;i++)
    {
        const ossia::value val = (float)i*10;
        emit interactionValueReturned(val); /* SEGFAULT Resolved (maybe)*/
        sleep(1);
    }

    qDebug("SendInteraction : end.");
}


//std::vector<ossia::value>  ConnectionFaussaire::getMRetValues (){
//    return mRetValues;
//}

ossia::net::generic_device& ConnectionFaussaire::getMDevice(){
    return mDevice;
}
