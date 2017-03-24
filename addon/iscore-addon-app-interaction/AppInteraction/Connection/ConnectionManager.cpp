#include <AppInteraction/Connection/ConnectionManager.hpp>

namespace connection
{
ConnectionManager::ConnectionManager():
    zServ(ossia::net::make_zeroconf_server(
              "iscoreInteraction",
              "iscoreInteraction",
              "iscore",
              6666,
              9999))
{

}

ConnectionManager::~ConnectionManager()
{

}

int ConnectionManager::getNumConnections()
{
    return connectedDevices.size();
}


void ConnectionManager::closeConnection(Connection c)
{

}

//size_t ConnectionManager::findDevice(std::string name)
//{
//    std::vector<Connection>::iterator it = std::find_if(
//                connectedDevices.begin(),
//                connectedDevices.end(),
//                [&name](const ossia::net::generic_device& dev) {
//        return dev.getName().compare(name) == 0;
//    });

//    return std::distance(connectedDevices.begin(), it);
//}

std::vector<connection::Connection> * ConnectionManager::getDevices()
{
    return &connectedDevices;
}
}
