#pragma once
#include <algorithm>
#include<QObject>
#include <ossia/ossia.hpp>



namespace connectionFaussaire
{

class ConnectionFaussaire final : public QObject
{

      Q_OBJECT
private:
    ossia::net::generic_device mDevice;
    std::vector<ossia::value> mRetValues={(ossia::value)1};

public:
    ConnectionFaussaire(std::string device_name);
    ~ConnectionFaussaire();

    std::vector<ossia::value>  getMRetValues ();
    ossia::net::generic_device& getMDevice();
    std::string getDeviceName() const;
    /*!
     * \brief sendInteraction
     * \param interaction
     * \return
     */
    void sendInteraction(const std::string interaction);
signals:
    /*!
     * \brief interactionValueReturned is emitted each time the device updates its interaction node.
     */
    void interactionValueReturned(const ossia::value&);
};
}
