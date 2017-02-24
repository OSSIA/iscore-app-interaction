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
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/mainmw.qml")));
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
    QVariant t = QVariant(val);

    //ECRITURE VERS QML
    int length = 42;
    QQmlEngine wengine;
    QQmlComponent wcomponent(&wengine, "qrc:/InteractionsMenu.qml");
    QObject *wobject = wcomponent.create();
    QQmlProperty::write(wobject, "jsonLength", length);

    qDebug() << "Property value:" << wobject->property("jsonLength").toInt();
    //object->setProperty("someNumber", 100);

    //LECTURE DU QML
    QQmlEngine rengine;
    QQmlComponent rcomponent(&rengine, "qrc:/InteractionsMenu.qml");
    QObject *robject = rcomponent.create();
    QString entered = QQmlProperty::read(robject, "content").toString();

    qDebug() << "Property value:" << entered;*/
    return app.exec();

}
