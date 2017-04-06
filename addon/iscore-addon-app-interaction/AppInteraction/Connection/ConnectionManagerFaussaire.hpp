#pragma once

#include "ConnectionFaussaire.hpp"



namespace connectionFaussaire
{

class ConnectionManagerFaussaire  final : public QObject
{

    Q_OBJECT
private:
    std::vector<ConnectionFaussaire*> connectedDevices;


public:
    ConnectionManagerFaussaire ();
    ~ConnectionManagerFaussaire ();

    int getNumConnections() const;
    void closeConnection(ConnectionFaussaire *c);
    std::vector<ConnectionFaussaire*> getDevices() const;
};
}
