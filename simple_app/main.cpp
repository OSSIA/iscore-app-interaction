#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QFile>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QJsonArray>

void readJson()
   {
      QString val;
      QFile file;
      file.setFileName("interactions.json");
      file.open(QIODevice::ReadOnly | QIODevice::Text);
      val = file.readAll();
      file.close();
      //qWarning() << val;
      QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
      /*QJsonObject sett2 = d.object();
      QJsonValue value = sett2.value(QString("iscoreApp"));
      qWarning() << value;
      QJsonObject item = value.toObject();
      qWarning() << tr("QJsonObject of description: ") << item;*/
      QJsonObject t = d.object();
      qDebug() << t;

   }

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    readJson();
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
