#pragma once
#include <algorithm>
#include <QObject>
#include <ossia/ossia.hpp>



namespace connectionFaussaire
{

class ConnectionFaussaire final : public QObject
{

    Q_OBJECT
private:
    ossia::net::generic_device mDevice;
    const std::string mDeviceName;

public:
    ConnectionFaussaire(const std::string device_name);
    ~ConnectionFaussaire();

    ossia::net::generic_device& getMDevice();
    const std::string getDeviceName() const;
    /*!
     * \brief sendInteraction
     * \param interaction
     * \return
     */
    void sendInteraction(const std::string interaction);

signals:
    void interactionValueReturned(const ossia::value&);
};
}
