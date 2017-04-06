#ifndef SIGNAl_HPP
#define SIGNAl_HPP

#include <QObject>
#include <QDebug>
#include <QApplication>

#include <QQmlApplicationEngine>
#include <QtQuick/QQuickView>
#include <QQmlComponent>





class Signal : public QObject
{
    Q_OBJECT
//public:
  // explicit HandleTextField(QObject *parent = 0);

public slots:
    void handleSig(double val);
    void handleButtonConnect();
    void ThrowInteraction(int id);
};

#endif // SIGNAl_HPP
