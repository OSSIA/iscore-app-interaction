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

    //QQmlEngine engine;
    //QQmlComponent component(&engine, "CountDown.qml");
    //QObject *object = component.create();
    //qDebug() << "Property value:" << QQmlProperty::read(object, "slidVal").toInt();
    /*QQmlProperty::write(object, "someNumber", 5000);
    qDebug() << "Property value:" << object->property("someNumber").toInt();
    object->setProperty("someNumber", 100);
    */


    
    //QQmlApplicationEngine engine;
    //engine.load(QUrl(QStringLiteral("qrc:/Principal.qml")));

    //QQmlApplicationEngine engin;
    //engin.load(QUrl(QStringLiteral("qrc:/main.qml")));

    //QApplication app(argc, argv);

    /*QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/main.qml"));
    viewer.showExpanded();



    QObject *obj = viewer.rootObject();
    qDebug() << obj->property("slidVal");

*/
    //return app.exec();
    struct datai* d = extract_data("123:45:");
    printf("id:%d\n",d->id);
    printf("duration:%d\n",d->duration);
    return 0;



}
