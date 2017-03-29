#include "ConnectionManagerFaussaire.hpp"

using namespace connectionFaussaire;

ConnectionManagerFaussaire::ConnectionManagerFaussaire(){
    std::string device_name = "co";
    ConnectionFaussaire* co = new ConnectionFaussaire(device_name);
    connectedDevices.insert(connectedDevices.end(), co);
    qDebug("Connection name \"co\" opened.");
}

ConnectionManagerFaussaire::~ConnectionManagerFaussaire(){

}


int ConnectionManagerFaussaire::getNumConnections() const
{
    return connectedDevices.size();
}

void ConnectionManagerFaussaire::closeConnection(ConnectionFaussaire* c)
{
    connectedDevices.erase(connectedDevices.begin(),connectedDevices.end());
    qDebug("Connection closed.");
}


std::vector<ConnectionFaussaire*> ConnectionManagerFaussaire::getDevices() const{
    return connectedDevices;
}
