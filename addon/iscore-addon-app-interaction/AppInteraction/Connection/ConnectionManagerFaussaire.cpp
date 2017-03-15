#include "ConnectionManagerFaussaire.hpp"

using namespace connection;

ConnectionManagerFaussaire::ConnectionManagerFaussaire(){

}

ConnectionManagerFaussaire::~ConnectionManagerFaussaire()
{

}

int ConnectionManagerFaussaire::getNumConnections(){
return connectedDevices.size();
}

//ossia::net::generic_device * ConnectionManagerFaussaire::openConnection(){}
void ConnectionManagerFaussaire::openConnection(){

  //  connectedDevices.insert(new ConnectionFaussaire("Name"));
}

void ConnectionManagerFaussaire::closeConnection(ConnectionFaussaire c)
{
//connectedDevices.erase("%d", std::distance(connectedDevices.begin(),find(connectedDevices.begin(),connectedDevices.end(),c)));
}

size_t findDevice(std::string name){
    return 0;
}


std::vector<ConnectionFaussaire> ConnectionManagerFaussaire::getDevices(){
return connectedDevices;
}
