#pragma once
#include <ossia/ossia.hpp>
#include <QTcpSocket>
#include <QHostAddress>

class ClientConnection : public QObject
{
    Q_OBJECT
private:
    QTcpSocket m_socket;

public:
    ClientConnection(const QHostAddress&);
    ~ClientConnection();

public slots:
    void onConnected();
    void closed();
    void onDataReceived();
};
