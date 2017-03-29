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
    ossia::net::generic_device mDevice;/* = new ossia::net::generic_device(std::make_unique<ossia::net::local_protocol>(), "newName");*/
    //std::string mDevice;
    std::vector<ossia::value> mRetValues;

public:
    ConnectionFaussaire(std::string device_name);
    //ConnectionFaussaire(const ConnectionFaussaire&);
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
