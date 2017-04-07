#pragma once

#include "MockConnection.hpp"



namespace mockConnection
{

class MockConnectionManager  final : public QObject
{

    Q_OBJECT
private:
    std::vector<MockConnection*> connectedDevices;


public:
    MockConnectionManager ();
    ~MockConnectionManager ();

    int getNumConnections() const;
    void closeConnection(MockConnection *c);
    std::vector<MockConnection*> getDevices() const;
};
}
