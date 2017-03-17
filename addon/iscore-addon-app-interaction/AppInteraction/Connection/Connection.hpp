#pragma once
#include <algorithm>
#include <QObject>
#include <ossia/ossia.hpp>

namespace connection
{

class Connection final : public QObject
{

    Q_OBJECT
private:
    ossia::net::generic_device mDevice;


public:
    Connection(std::string device_name);
    ~Connection();

    /*!
     * \brief sendInteraction
     * \param interaction
     */
    void sendInteraction(const std::string interaction);

signals:
    void interactionValueReturned(const ossia::value&);
};
}
