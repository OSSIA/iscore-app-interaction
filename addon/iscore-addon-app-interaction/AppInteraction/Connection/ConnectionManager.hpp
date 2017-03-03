#pragma once

#include "Connection.hpp"

using namespace std;

namespace connection
{

class ConnectionManager final
{
private:
    int nConnections;
    std::vector<Connection> * connectedDevices;

public:
    ConnectionManager();
    ~ConnectionManager();

    void openConnection();
    void closeConnection(Connection c);

};
}
