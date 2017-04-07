#include "ConnectionManagerFaussaire.hpp"

using namespace connectionFaussaire;

ConnectionManagerFaussaire::ConnectionManagerFaussaire(){
    ConnectionFaussaire* co1 = new ConnectionFaussaire("first connection");
    ConnectionFaussaire* co2 = new ConnectionFaussaire("second connection");
    connectedDevices.insert(connectedDevices.end(), co1);
    connectedDevices.insert(connectedDevices.end(), co2);
}

ConnectionManagerFaussaire::~ConnectionManagerFaussaire()
{
qDebug("ConnectionManager destroyed.");
}


int ConnectionManagerFaussaire::getNumConnections() const
{
    return connectedDevices.size();
}

void ConnectionManagerFaussaire::closeConnection(ConnectionFaussaire* c)
{
    connectedDevices.erase(connectedDevices.begin(),connectedDevices.end());
    qDebug("All connections closed.");
}


std::vector<ConnectionFaussaire*> ConnectionManagerFaussaire::getDevices() const
{
    return connectedDevices;
}
