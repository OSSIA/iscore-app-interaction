#include "serial_protocol.hpp"
#include <ossia-qt/serial/serial_address.hpp>
#include <ossia-qt/serial/serial_device.hpp>
#include <ossia-qt/serial/serial_node.hpp>
#include <sstream>
#include <iomanip>
#include <QDebug>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQmlContext>

namespace ossia
{
namespace net
{
serial_protocol::serial_protocol(
    const QByteArray& code,
    const QSerialPortInfo& bot):
  mEngine{new QQmlEngine},
  mComponent{new QQmlComponent{mEngine}},
  mSerialPort{bot},
  mCode{code}
{
  connect(mComponent, &QQmlComponent::statusChanged,
          this, [=] (QQmlComponent::Status status)
  {
    qDebug() << status;
    if(!mDevice)
      return;

    switch(status)
    {
      case QQmlComponent::Status::Ready:
      {
        auto item = mComponent->create();
        item->setParent(mEngine->rootContext());

        QVariant ret;
        QMetaObject::invokeMethod(item, "createTree", Q_RETURN_ARG(QVariant, ret));
        qt::create_device<serial_device, serial_node, serial_protocol>(*mDevice, ret.value<QJSValue>());

        return;
      }
      case QQmlComponent::Status::Loading:
        return;
      case QQmlComponent::Status::Null:
      case QQmlComponent::Status::Error:
        qDebug() << mComponent->errorString();
        return;
    }
  }
  );
}

bool serial_protocol::pull(address_base&)
{
  return false;
}

bool serial_protocol::push(const ossia::net::address_base& addr)
{
  auto& ad = dynamic_cast<const serial_address&>(addr);
  auto str = ad.data().request;
  switch(addr.getValueType())
  {
    case ossia::val_type::FLOAT:
      str.replace("$0", QString::number(ad.getValue().get<float>(), 'g', 4));
      break;
    case ossia::val_type::INT:
      str.replace("$0", QString::number(ad.getValue().get<int32_t>()));
      break;
    case ossia::val_type::IMPULSE:
      break;
    default:
      throw;
  }

  str += '\n';
  qDebug() << str;
  mSerialPort.write(str.toUtf8());
  return false;
}

bool serial_protocol::observe(address_base&, bool)
{
  return false;
}

bool serial_protocol::update(node_base& node_base)
{
  return true;
}

void serial_protocol::setDevice(device_base& dev)
{
  if(auto htdev = dynamic_cast<serial_device*>(&dev))
  {
    mDevice = htdev;
    mComponent->setData(mCode, QUrl{});
  }
}


serial_protocol::~serial_protocol()
{

}


}
}
