#pragma once

#include "Connection.hpp"

#include <qlist.h>

namespace connection
{

class ConnectionManager final
{
private:
    int nConnections;
    QList<Connection> connectedDevices;

public:
    ConnectionManager();
    ~ConnectionManager();

    void openConnection();
    void closeConnection(Connection c);

};
}
