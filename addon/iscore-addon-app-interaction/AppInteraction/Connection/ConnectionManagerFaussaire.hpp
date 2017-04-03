#pragma once

#include "ConnectionFaussaire.hpp"



namespace connectionFaussaire
{

class ConnectionManagerFaussaire  final : public QObject
{

    Q_OBJECT
private:
    std::vector<ConnectionFaussaire*> connectedDevices;


public:
    ConnectionManagerFaussaire ();
    ~ConnectionManagerFaussaire ();

    /*!
     * \brief getNumConnections gives the number of connected devices.
     * \return
     */
    int getNumConnections() const;

    /*!
     * \brief closeConnection
     * \param c
     */
    void closeConnection(ConnectionFaussaire *c);

    /*!
     * \brief getDevices
     * \return
     */
    std::vector<ConnectionFaussaire*> getDevices() const;
};
}
