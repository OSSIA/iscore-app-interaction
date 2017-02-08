#pragma once
#include <ossia/ossia.hpp>
//#include <kdnssd/publicservice.h>

#include <QObject>

using namespace ossia;
using namespace std;
using namespace KDNSSD;

class Connexion final
{
private:
// information on the connected device



public:
    Connexion();
    ~Connexion();

	void sendInteraction();
    void updateData();
    void closeConnexion();
    void protocol();

};
