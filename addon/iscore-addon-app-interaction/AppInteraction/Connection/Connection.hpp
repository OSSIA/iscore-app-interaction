#pragma once
#include <algorithm>
#include <QObject>
#include <ossia/ossia.hpp>

namespace connection
{
/*!
 * \brief The Connection class describes a device that is connected to iscore.
 */
class Connection final : public QObject
{

    Q_OBJECT
private:
    ossia::net::generic_device mDevice;


public:
    Connection(std::string device_name);
    ~Connection();

    /*!
     * \brief sendInteraction sends a message to the connected device telling which interaction should be started.
     * \param interaction must be in the following format:
     *          TODO : describe the protocol
     */
    void sendInteraction(const std::string interaction);

    /*!
     * \brief getDeviceName returns the name of the device.
     * \return a std::string containing the device's name
     */
    std::string getDeviceName();

signals:
    /*!
     * \brief interactionValueReturned is emitted each time the device updates its interaction node.
     */
    void interactionValueReturned(const ossia::value&);
};
}
