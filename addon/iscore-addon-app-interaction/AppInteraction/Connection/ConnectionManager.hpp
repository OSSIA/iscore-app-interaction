#pragma once

#include "Connection.hpp"

class ConnectionManager
{
private:
    Connection * ConnectedDevices;

public:
    ConnectionManager();
    ~ConnectionManager();

    void openConnection();
    void closeConnection();

};
