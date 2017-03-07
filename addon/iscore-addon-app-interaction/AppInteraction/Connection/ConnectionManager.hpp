#pragma once

#include "Connection.hpp"

using namespace std;

namespace connection
{

class ConnectionManager final
{
private:
    std::vector<Connection> connectedDevices;

public:
    ConnectionManager();
    ~ConnectionManager();

    int getNumConnections();
    void openConnections();
    void closeConnection(Connection c);

};
}
