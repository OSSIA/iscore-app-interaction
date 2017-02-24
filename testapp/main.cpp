#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQuick/QQuickView>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engin;
    engin.load(QUrl(QStringLiteral("qrc:/main.qml")));


    
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/LostConnection.qml")));

    QQuickView view;
    view.setSource(QUrl::fromLocalFile("LostConnection.qml"));
    view.show();
  /* QQuickView *view = new QQuickView;
   view->setSource(QUrl::fromLocalFile("main.qml"));
   view->show();*/
    //engine.load(QUrl(QStringLiteral("qrc:/maine.qml")));


    //QQmlEngine engine;
    //QQmlComponent component(&engine,QUrl::fromLocalFile("LostConnection.qml"));
    //QObject *object = component.create();
    return app.exec();
}
