#include "ConnectionManager.hpp"

using namespace connection;

ConnectionManager::ConnectionManager():
    zServ(ossia::net::make_zeroconf_server(
              "iscoreInteraction",
              "iscoreInteraction",
              "iscore",
              6666,
              9999))
{
    // TODO : link KDNSSD library

}

ConnectionManager::~ConnectionManager()
{

}

int ConnectionManager::getNumConnections()
{
    return connectedDevices.size();
}

ossia::net::generic_device * ConnectionManager::openConnection()
{
    // listen to the network
    return {};
}

void ConnectionManager::closeConnection(Connection c)
{

}

//size_t ConnectionManager::findDevice(std::string name)
//{
//    std::vector<Connection>::iterator it = std::find_if(
//                connectedDevices.begin(),
//                connectedDevices.end(),
//                [=](ossia::net::generic_device dev) {
//        return !dev.getName().compare(name);
//    });

//    return std::distance(connectedDevices.begin(), it);
//}

//std::vector<Connection> ConnectionManager::getDevices()
//{
//    return connectedDevices;
//}
