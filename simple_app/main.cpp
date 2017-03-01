#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QFile>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QJsonArray>
#include <QQmlContext>
#include <QTextObject>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQmlProperty>
#include <QTimer>

#define INFINITE 1000

/*void readJson()
   {
      QString val;
      QFile file;
      file.setFileName("interactions.json");
      file.open(QIODevice::ReadOnly); //| QIODevice::Text);
      val = file.readAll();
      file.close();
      //qWarning() << val;
      QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
      QJsonObject sett2 = d.object();
      //QJsonValue value = sett2.value(QString("iscoreApp"));
      //qWarning() << value;
      //QJsonObject item = value.toObject();
      //qWarning() << tr("QJsonObject of description: ") << item;
      QVariant t = QVariant(val);

      //ECRITURE VERS QML
      QQmlEngine engine;
      QQmlComponent component(&engine, "qrc:/InteractionsMenu.qml");
      QObject *object = component.create();
      QQmlProperty::write(object, "passJson", t);

      qDebug() << "Property value:" << object->property("passJson").toString();
      //object->setProperty("someNumber", 100);
   }*/

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    /*QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/Principal.qml")));*/
    //engine.load(QUrl(QStringLiteral("qrc:/mainmw.qml")));
    //readJson();
    /*QString val;
    QFile file;
    file.setFileName("interactions.json");
    file.open(QIODevice::ReadOnly); //| QIODevice::Text);
    val = file.readAll();
    file.close();
    //qWarning() << val;
    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject sett2 = d.object();
    //QJsonValue value = sett2.value(QString("iscoreApp"));
    //qWarning() << value;
    //QJsonObject item = value.toObject();
    //qWarning() << tr("QJsonObject of description: ") << item;
    QVariant t = QVariant(val);*/

    //ECRITURE VERS QML
    /*int length = 42;
    QQmlEngine wengine;
    QQmlComponent wcomponent(&wengine, "qrc:/InteractionsMenu.qml");
    QObject *wobject = wcomponent.create();
    QQmlProperty::write(wobject, "jsonLength", length);

    qDebug() << "Property value:" << wobject->property("jsonLength").toInt();
    //object->setProperty("someNumber", 100);*/

    //LECTURE DU QML
    QQmlEngine rengine;
    QQmlComponent rcomponent(&rengine, "qrc:/Principal.qml");
    QObject *robject = rcomponent.create();
    QString entered;
    int i;
    for(i=0;i<INFINITE;i++)
    {
        QTimer::singleShot(500*i, &app, SLOT(quit()));
        app.exec();
        entered = QQmlProperty::read(robject, "login").toString();
        qDebug() << "Login value:" << entered;
    }
    printf("Coucou\n");
    return app.exec();

}
