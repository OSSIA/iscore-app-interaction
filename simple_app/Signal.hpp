#ifndef SIGNAl_HPP
#define SIGNAl_HPP

#include <QObject>
#include <QDebug>


class Signal : public QObject
{
    Q_OBJECT
//public:
  // explicit HandleTextField(QObject *parent = 0);

public slots:
    void handleSig(double val);
    void handleButtonConnect();
};

#endif // SIGNAl_HPP
