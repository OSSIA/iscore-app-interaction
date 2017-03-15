#pragma once
//#include <algorithm>

//#include <ossia/ossia.hpp>

//#if ISCORE_ZEROCONF
//    #include <KDNSSD/DNSSD/publicservice.h>
//#endif

using namespace ossia;
using namespace std;

namespace connection
{

class ConnectionFaussaire final
{
private:
   // ossia::net::generic_device mDevice;

public:
   ConnectionFaussaire(std::string device_name);
    ~ConnectionFaussaire();

    /*!
     * \brief sendInteraction
     * \param interaction
     * \return
     */
    //std::vector<ossia::value>
    void sendInteraction(const std::string interaction);

};
}
