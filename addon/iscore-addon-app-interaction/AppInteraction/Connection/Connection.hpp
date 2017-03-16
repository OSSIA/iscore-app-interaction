#pragma once
#include <algorithm>

#include <ossia/ossia.hpp>

#if ISCORE_ZEROCONF
    #include <KDNSSD/DNSSD/publicservice.h>
#endif

namespace connection
{

class Connection final
{
private:
    ossia::net::generic_device mDevice;


public:
    Connection(std::string device_name);
    ~Connection();

    /*!
     * \brief sendInteraction
     * \param interaction
     * \return
     */
    std::vector<ossia::value> sendInteraction(const std::string interaction);

};
}
