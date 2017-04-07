#include "MockConnectionManager.hpp"

using namespace mockConnection;

MockConnectionManager::MockConnectionManager(){
    MockConnection* co1 = new MockConnection("first connection");
    MockConnection* co2 = new MockConnection("second connection");
    connectedDevices.insert(connectedDevices.end(), co1);
    connectedDevices.insert(connectedDevices.end(), co2);
}

MockConnectionManager::~MockConnectionManager()
{
qDebug("ConnectionManager destroyed.");
}


int MockConnectionManager::getNumConnections() const
{
    return connectedDevices.size();
}

void MockConnectionManager::closeConnection(MockConnection* c)
{
    connectedDevices.erase(connectedDevices.begin(),connectedDevices.end());
    qDebug("All connections closed.");
}


std::vector<MockConnection*> MockConnectionManager::getDevices() const
{
    return connectedDevices;
}
