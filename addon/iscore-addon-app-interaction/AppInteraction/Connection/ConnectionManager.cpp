#include "ConnectionManager.hpp"

ConnectionManager::ConnectionManager()
{
    Connection * ConnectedDevices = new Connection[];
}

ConnectionManager::~ConnectionManager()
{

    delete[] ConnectedDevices;
}

ConnectionManager::openConnection()
{
    Connection c = new Connection();
}

ConnectionManager::closeConnection()
{

}
