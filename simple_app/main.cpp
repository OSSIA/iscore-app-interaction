#include <QApplication>
//#include <QDeclarativeView>
#include <QQmlApplicationEngine>
#include <QtQuick/QQuickView>
#include <QQmlComponent>
//#include <QtDeclarative>
#include <QDebug>
#include <QObject>
#include "Signal.hpp"
#include "extract.hpp"
#include <ossia/ossia.hpp>

#include <iostream>
#include <memory>
#include <functional>





int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //QQmlApplicationEngine engin;
    //engin.load(QUrl(QStringLiteral("qrc:/main.qml")));
    QQmlEngine engine;
    QQmlComponent component(&engine,QUrl(QStringLiteral("qrc:/Principal.qml")));
    QObject *object = component.create();



    Signal s ;

    qDebug() << "Property value:" << object->property("slidVal").toReal();
    QObject::connect(object, SIGNAL(changeSlide(double)),
                         &s, SLOT(handleSig(double)));

    // qDebug() << "Property value:" << QQmlProperty::read(object, "lost").toInt();
    //delete object;

    /*QQmlEngine engine;
    QQmlComponent component(&engine, "CountDown.qml");
    QObject *object = component.create();
    qDebug() << "Property value:" << QQmlProperty::read(object, "slidVal").toInt();*/
    /*QQmlProperty::write(object, "someNumber", 5000);
    qDebug() << "Property value:" << object->property("someNumber").toInt();
    object->setProperty("someNumber", 100);*/



    
    /*QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/Principal.qml")));

    QQmlApplicationEngine engin;
    engin.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QApplication app(argc, argv);*/

    /*QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/main.qml"));
    viewer.showExpanded();



    QObject *obj = viewer.rootObject();
    qDebug() << obj->property("slidVal");

*/
  /*  return app.exec();
    struct datai* d = extract_data("123:45:");
    printf("id:%d\n",d->id);
    printf("duration:%d\n",d->duration);
    */
    auto local_proto_ptr = std::make_unique<ossia::net::local_protocol>();
      ossia::net::local_protocol& local_proto = *local_proto_ptr;

      ossia::net::generic_device device{std::move(local_proto_ptr), "B"};


    auto localTestNode = device.createChild("test");

     auto localImpulseNode = localTestNode->createChild("my_impulse");
     auto localImpulseAddress = localImpulseNode->createAddress(ossia::val_type::IMPULSE);
     //localImpulseAddress->add_callback(printValueCallback);

     auto localBoolNode = localTestNode->createChild("my_bool");
     auto localBoolAddress = localBoolNode->createAddress(ossia::val_type::BOOL);
     //localBoolAddress->add_callback(printValueCallback);

     auto localIntNode = localTestNode->createChild("my_int");
     auto localIntAddress = localIntNode->createAddress(ossia::val_type::INT);
     //localIntAddress->add_callback(printValueCallback);

     auto localFloatNode = localTestNode->createChild("my_float");
     auto localFloatAddress = localFloatNode->createAddress(ossia::val_type::FLOAT);
     //localFloatAddress->add_callback(printValueCallback);

     auto localStringNode = localTestNode->createChild("my_string");
     auto localStringAddress = localStringNode->createAddress(ossia::val_type::STRING);
   //  localStringAddress->add_callback(printValueCallback);

     // auto localDestinationNode = localTestNode->createChild("my_destination");
     // auto localDestinationAddress = localDestinationNode->createAddress(val_type::DESTINATION);
     // localDestinationAddress->addCallback(printValueCallback);

     auto localTupleNode = localTestNode->createChild("my_tuple");
     auto localTupleAddress = localTupleNode->createAddress(ossia::val_type::TUPLE);
 //    localTupleAddress->add_callback(printValueCallback);

     // update tree value
     //localImpulseAddress->pushValue(impulse{});
     localBoolAddress->pushValue(true);
     localIntAddress->pushValue(123);
     localFloatAddress->pushValue(0.5);
     //localStringAddress->pushValue("hello world !");
     // FIXME
     // Destination d(localFloatNode);
     // localDestinationAddress->pushValue(&d);

     localTupleAddress->pushValue(std::vector<ossia::value>{0., 1., 2.});
     auto service_list = ossia::net::list_minuit_devices() ;


     std::cerr << service_list.empty() << std::endl;


     // declare a distant program as a Minuit device
     local_proto.exposeTo(std::make_unique<ossia::net::minuit_protocol>("B", "192.168.21.194", 9999, 6668));


     return app.exec();



}
