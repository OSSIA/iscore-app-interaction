#pragma once
#include <ossia/ossia.hpp>
//#include <kdnssd/publicservice.h>

#include <QObject>

using namespace ossia;
using namespace std;
using namespace KDNSSD;

namespace connection
{

class Connection final
{
private:
// information on the connected device



public:
    Connection();
    ~Connection();

	void sendInteraction();
    void updateData();
    void closeConnection();
    void protocol();

};
}
