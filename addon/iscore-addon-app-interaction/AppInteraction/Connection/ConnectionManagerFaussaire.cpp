#include "ConnectionManagerFaussaire.hpp"

using namespace connectionFaussaire;

ConnectionManagerFaussaire::ConnectionManagerFaussaire(){

}

ConnectionManagerFaussaire::~ConnectionManagerFaussaire()
{

}

int ConnectionManagerFaussaire::getNumConnections(){
    return connectedDevices.size();
}

//ossia::net::generic_device * ConnectionManagerFaussaire::openConnection(){}
void ConnectionManagerFaussaire::openConnection(){
    std::string device_name = "Co n°1";
    ConnectionFaussaire co = ConnectionFaussaire(device_name);
    connectedDevices.insert(connectedDevices.end(), co);
    qDebug("Connection name \"Co n°1\" opened.");
}

void ConnectionManagerFaussaire::closeConnection(ConnectionFaussaire c)
{
    connectedDevices.erase(connectedDevices.begin(),connectedDevices.end());
    qDebug("Connection closed.");
}

size_t ConnectionManagerFaussaire::findDevice(std::string name){
    return 0;
}


std::vector<ConnectionFaussaire> ConnectionManagerFaussaire::getDevices(){    
    return connectedDevices;
}
