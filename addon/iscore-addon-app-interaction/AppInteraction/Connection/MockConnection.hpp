#pragma once
#include <algorithm>
#include <QObject>
#include <ossia/ossia.hpp>

namespace mockConnection
{

class MockConnection final : public QObject
{

    Q_OBJECT
private:
    ossia::net::generic_device mDevice;
    const std::string mDeviceName;

public:
    MockConnection(const std::string device_name);
    ~MockConnection();

    ossia::net::generic_device& getMDevice();
    const std::string getDeviceName() const;

    void sendInteraction(const std::string interaction);

signals:
    /**
     * @brief interactionValueReturned : signal sent when there is a received value from the app
     */
    void interactionValueReturned(const ossia::value&);
};
}
