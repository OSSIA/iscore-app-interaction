#pragma once
//#include <algorithm>

#include <ossia/ossia.hpp>

//#if ISCORE_ZEROCONF
//    #include <KDNSSD/DNSSD/publicservice.h>
//#endif

namespace connectionFaussaire
{

class ConnectionFaussaire final
{
private:
    ossia::net::generic_device* mDevice = new ossia::net::generic_device(std::make_unique<ossia::net::local_protocol>(), "newName");
    //std::string mDevice;
    std::vector<ossia::value> mRetValues;

public:
   ConnectionFaussaire(std::string device_name);
//   ConnectionFaussaire(const connectionFaussaire::ConnectionFaussaire&);
    ~ConnectionFaussaire();

    /*!
     * \brief sendInteraction
     * \param interaction
     * \return
     */
    std::vector<ossia::value> sendInteraction(const std::string interaction);

};
}
