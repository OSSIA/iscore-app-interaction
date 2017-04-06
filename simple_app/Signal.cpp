
#include "Signal.hpp"
#include "ClientConnection.hpp"

/*

Signal::HandleTextField(QObject *parent) :
    QObject(parent)
{
}
*/
void Signal::handleSig(double value)
{
    qDebug() << "c++: slider change" << value ;
}

void Signal::handleButtonConnect()
{
    qDebug() << "c++: pression on connect button change" ;
    ClientConnection* co = new ClientConnection(QHostAddress(QStringLiteral("192.168.21.194")));
}
