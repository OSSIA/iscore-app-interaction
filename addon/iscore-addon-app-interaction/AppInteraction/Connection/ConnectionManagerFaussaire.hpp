#pragma once

#include "ConnectionFaussaire.hpp"

//using namespace std;

namespace connection
{

class ConnectionManagerFaussaire  final
{
private:
    std::vector<ConnectionFaussaire> connectedDevices;


public:
    ConnectionManagerFaussaire ();
    ~ConnectionManagerFaussaire ();

    /*!
     * \brief getNumConnections gives the number of connected devices.
     * \return
     */
    int getNumConnections();

    /*!
     * \brief openConnection
     * \return
     */
 //   net::generic_device * openConnection();
    void openConnection();

    /*!
     * \brief closeConnection
     * \param c
     */
    void closeConnection(ConnectionFaussaire c);

    /*!
     * \brief findConnection
     * \param name
     * \return
     */
    size_t findDevice(std::string name);

    /*!
     * \brief getDevices
     * \return
     */
   std::vector<ConnectionFaussaire> getDevices();
};
}
