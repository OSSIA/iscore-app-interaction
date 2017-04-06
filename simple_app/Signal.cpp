
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


void Signal::ThrowInteraction(int id){
    QQmlEngine wengine;
    QQmlComponent wcomponent(&wengine, QUrl(QStringLiteral("qrc:/mainmw.qml")));
    QObject *wobject = wcomponent.create();
    wobject->setProperty("ino", id);

}
