#pragma once

#include <AppInteraction/Connection/Connection.hpp>
#include <ossia/network/zeroconf/zeroconf.hpp>

namespace connection
{
/*!
 * \brief The ConnectionManager class keeps track of all the connected devices.
 * Instanciate this class once and it will automatically publish the service on the network and handle new connections.
 */
class ConnectionManager final : public QObject
{
    Q_OBJECT
private:
    std::vector<Connection*> m_connectedDevices;
    ossia::net::zeroconf_server m_zeroconfServ;
    QTcpServer* m_Serv;

public:
    ConnectionManager();
    ~ConnectionManager();

    /*!
     * \brief getNumConnections gives the number of connected devices.
     * \return an int.
     */
    int getNumConnections() const;

    /*!
     * \brief closeConnection
     * \param c
     */
    void closeConnection(Connection*);

    /*!
     * \brief getDevices returns the list of currently connected devices.
     * \return a std::vector<Connection>.
     */
    std::vector<Connection*> getDevices() const;

public slots:
    void openConnection();
};
}
