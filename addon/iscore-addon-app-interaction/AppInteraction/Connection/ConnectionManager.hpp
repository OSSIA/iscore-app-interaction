#pragma once

#include <AppInteraction/Connection/Connection.hpp>

namespace connection
{

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
     * \return
     */
    int getNumConnections();

    /*!
     * \brief openConnection
     * \return
     */
    ossia::net::generic_device * openConnection();

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
     * \brief getDevices
     * \return
     */
    std::vector<Connection> * getDevices();
};
}
