#include "ConnectionManager.hpp"

using namespace connection;

ConnectionManager::ConnectionManager() : nConnections(0),
                                         connectedDevices(new QList<Connection>)
{

}

ConnectionManager::~ConnectionManager()
{

    delete[] ConnectedDevices;
}

ConnectionManager::openConnection()
{
    Connection c = new Connection();
    connectedDevices << c;
    nConnections++;
}

ConnectionManager::closeConnection(Connection c)
{
    connectedDevices.removeOne(c);
}
