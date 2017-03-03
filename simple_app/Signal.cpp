
#include "Signal.hpp"

/*

Signal::HandleTextField(QObject *parent) :
    QObject(parent)
{
}
*/
void Signal::handleSig(double value)
{
    qDebug() << "c++: slider change" << value ;
}
