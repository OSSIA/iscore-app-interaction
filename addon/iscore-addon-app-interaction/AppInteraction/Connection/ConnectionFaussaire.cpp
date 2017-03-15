#include "ConnectionFaussaire.hpp"

using namespace connectionFaussaire;
using namespace std;


ConnectionFaussaire::ConnectionFaussaire(std::string device_name)
{
    mDevice = device_name;
    qDebug("New Connection named %s created.", device_name.c_str());

}

//ConnectionFaussaire::ConnectionFaussaire(const connectionFaussaire::ConnectionFaussaire&){
//    qDebug("Constructeur par recopie de ConnectionFaussaire");
//}

ConnectionFaussaire::~ConnectionFaussaire(){
}


std::vector<ossia::value> ConnectionFaussaire::sendInteraction(const std::string interaction){
    qDebug("Interaction %s sent to %s.", interaction.c_str(), mDevice.c_str());
    int duration = std::stoi(interaction.substr(interaction.find_first_of(':')+1 , interaction.find_last_of(':')-interaction.find_first_of(':')-1));
    int type =  std::stoi(interaction.substr(interaction.find_last_of(':')+1));
    qDebug("Duration : %d", duration);
    qDebug("Type wanted : %d.",type);
    for(int i=0; i<5;i++)
 {   mRetValues.push_back(std::abs(qrand()) % 100);
     qDebug("RetValue %d:",i);
}
    return mRetValues;

}
