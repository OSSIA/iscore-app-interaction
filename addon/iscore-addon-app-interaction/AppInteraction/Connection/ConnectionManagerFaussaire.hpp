#pragma once

#include "ConnectionFaussaire.hpp"



namespace connectionFaussaire
{

class ConnectionManagerFaussaire  final
{
private:
    std::vector<ConnectionFaussaire> connectedDevices;


public:
    ConnectionManagerFaussaire ();
    ConnectionManagerFaussaire(const ConnectionManagerFaussaire& cm);
    ~ConnectionManagerFaussaire ();

    /*!
     * \brief getNumConnections gives the number of connected devices.
     * \return
     */
    int getNumConnections() const;

    //    /*!
    //     * \brief openConnection
    //     * \return
    //     */
    //    //ossia::net::generic_device * openConnection();
    //    void openConnection();

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
    // size_t findDevice(std::string name);

    /*!
     * \brief getDevices
     * \return
     */
    std::vector<ConnectionFaussaire> getDevices() const;
};
}
