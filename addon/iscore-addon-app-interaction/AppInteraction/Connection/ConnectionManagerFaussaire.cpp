#include "ConnectionManagerFaussaire.hpp"

using namespace connectionFaussaire;

ConnectionManagerFaussaire::ConnectionManagerFaussaire(){
    ConnectionFaussaire* co = new ConnectionFaussaire("co");
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
