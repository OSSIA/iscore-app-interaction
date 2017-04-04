#include "ClientConnection.hpp"

ClientConnection::ClientConnection(const QHostAddress& addr)
{
    connect(&m_socket, &QTcpSocket::connected, this, &ClientConnection::onConnected);
    connect(&m_socket, &QTcpSocket::disconnected, this, &ClientConnection::closed);
    m_socket.connectToHost(addr, 9999);
    //faire un list_oscquery_devices() (cf. libossia/OSSIA/ossia/network/zeroconf.hpp), récupérer le vecteur de serveurs
    //et récupérer le serveur de nom iscore
   // ossia::net::ws_generic_client_address test


}

ClientConnection::~ClientConnection()
{

}

//cf. addon/iscore-addon-app-interaction/AppInteraction/Connection

void ClientConnection::onConnected()
{
    qDebug() << "Connected";
    connect(&m_socket, &QTcpSocket::readyRead,
            this, &ClientConnection::onDataReceived);
    m_socket.write("Hello World!");
}

void ClientConnection::onDataReceived()
{
    qint64 bytes = m_socket.bytesAvailable();
    char data[bytes+1];
    m_socket.read(data, bytes);
    data[bytes] = '\0';
    qDebug() << "Message received: " << data;
    m_socket.close();
}

void ClientConnection::closed()
{

}
