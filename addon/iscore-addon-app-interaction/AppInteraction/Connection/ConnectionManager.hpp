#pragma once

#include <AppInteraction/Connection/Connection.hpp>
#include <ossia/network/zeroconf/zeroconf.hpp>

namespace connection
{
/*!
 * \brief The ConnectionManager class keeps track of all the connected devices.
 * Instanciate this class once and it will automatically publish the service on the network and handle new connections.
 */
class ConnectionManager final
{
private:
    std::vector<Connection> connectedDevices;
    ossia::net::zeroconf_server zServ;

public:
    ConnectionManager();
    ~ConnectionManager();

    /*!
     * \brief getNumConnections gives the number of connected devices.
     * \return an int.
     */
    int getNumConnections();

    /*!
     * \brief closeConnection
     * \param c
     */
    void closeConnection(Connection c);

    /*!
     * \brief findConnection
     * \param name
     * \return
     */
//    size_t findDevice(std::string name);

    /*!
     * \brief getDevices returns the list of currently connected devices.
     * \return a pointer to a std::vector<Connection>.
     */
    std::vector<Connection> * getDevices();
};
}
