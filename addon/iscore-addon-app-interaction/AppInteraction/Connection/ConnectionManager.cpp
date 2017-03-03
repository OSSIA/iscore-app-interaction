#include "ConnectionManager.hpp"

using namespace connection;

ConnectionManager::ConnectionManager() : nConnections(0),
                                         connectedDevices(new std::vector<Connection>)
{

}

ConnectionManager::~ConnectionManager()
{

}

void ConnectionManager::openConnection()
{

}

void ConnectionManager::closeConnection(Connection c)
{
}
