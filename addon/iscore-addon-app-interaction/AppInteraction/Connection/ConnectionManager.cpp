#include <AppInteraction/Connection/ConnectionManager.hpp>

namespace connection
{
ConnectionManager::ConnectionManager():
    m_zeroconfServ(ossia::net::make_zeroconf_server(
              "iscoreInteraction",
              "iscoreInteraction",
              "iscore",
              9999,
              6666)),
    m_Serv(new QTcpServer())
{
    if (m_Serv->listen(QHostAddress::Any, 9999))
    {
        connect(m_Serv, &QTcpServer::newConnection,
                this, &ConnectionManager::openConnection);
    }
}

ConnectionManager::~ConnectionManager()
{
    for (Connection* co : m_connectedDevices)
    {
        delete co;
    }

    delete m_Serv;
}

int ConnectionManager::getNumConnections() const
{
    return m_connectedDevices.size();
}


void ConnectionManager::closeConnection(Connection* c)
{

}

std::vector<Connection*> ConnectionManager::getDevices() const
{
    return m_connectedDevices;
}

void ConnectionManager::openConnection()
{
    qDebug() << "connection detected";
    QTcpSocket* pSocket = m_Serv->nextPendingConnection();
    pSocket->write("hello this is iscore");
//    QHostAddress addr = pSocket->localAddress();
//    std::string str_addr = addr.toString().toStdString();
//    ossia::net::generic_address ossia_addr = ossia::net::generic_address();
//    ossia_addr.setValue(str_addr);

//    /* We create an osc server that will communicate with this specific device */
//    ossia::oscquery::oscquery_server_protocol* pServ =
//            new ossia::oscquery::oscquery_server_protocol(9999, 6666);
//    pServ->observe(ossia_addr, true);
//    /* We instanciate the Connection describing the device */
//    Connection* pCon = new Connection("hello");
//    m_connectedDevices.push_back(pCon);
//    pCon->setServer(pServ);
}
}
