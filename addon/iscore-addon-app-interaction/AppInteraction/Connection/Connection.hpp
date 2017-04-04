#pragma once
#include <algorithm>
#include <QObject>
#include <ossia/ossia.hpp>
#include <ossia/network/oscquery/oscquery_server.hpp>
#include <QtWebSockets/QtWebSockets>
#include <QtWebSockets/QWebSocketServer>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

namespace connection
{
/*!
 * \brief The Connection class describes a device that is connected to iscore.
 */
class Connection final : public QObject
{
    Q_OBJECT
private:
    ossia::net::generic_device* m_Device;
    ossia::oscquery::oscquery_server_protocol* m_oscServ;

public:
    Connection(std::string);
    ~Connection();

    /*!
     * \brief sendInteraction sends a message to the connected device telling which interaction should be started.
     * \param interaction must be in the following format:
     *          TODO : describe the protocol
     */
    void sendInteraction(const std::string);

    /*!
     * \brief getDeviceName returns the name of the device.
     * \return a std::string containing the device's name
     */
    std::string getDeviceName() const;
    void setServer(ossia::oscquery::oscquery_server_protocol*);

signals:
    /*!
     * \brief interactionValueReturned is emitted each time the device updates its interaction node.
     */
    void interactionValueReturned(const ossia::value&);
};
}
