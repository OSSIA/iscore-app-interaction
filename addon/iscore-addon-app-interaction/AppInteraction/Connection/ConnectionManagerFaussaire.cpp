#include "ConnectionManagerFaussaire.hpp"

using namespace connectionFaussaire;

ConnectionManagerFaussaire::ConnectionManagerFaussaire(){
    ConnectionFaussaire* co1 = new ConnectionFaussaire("co1");
    ConnectionFaussaire* co2 = new ConnectionFaussaire("co2");
    connectedDevices.insert(connectedDevices.end(), co1);
    connectedDevices.insert(connectedDevices.end(), co2);
    qDebug("Connections named \"co1\" and \"co2\" opened.");
}

ConnectionManagerFaussaire::~ConnectionManagerFaussaire()
{

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


std::vector<ConnectionFaussaire*> ConnectionManagerFaussaire::getDevices() const
{
    return connectedDevices;
}
