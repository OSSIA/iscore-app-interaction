#include "MobileDevicesWidget.hpp"
#include <QComboBox>
#include <QHBoxLayout>
#include <iscore/widgets/MarginLess.hpp>
#include <iscore/widgets/SignalUtils.hpp>
#include <qvariant.h>


namespace State
{

  MobileDevicesWidget::MobileDevicesWidget( QWidget* parent) : QWidget{parent}
  {

    m_layout = new iscore::MarginLess<QHBoxLayout>{this};
    m_combobox = new QComboBox{this};
    m_layout->addWidget(m_combobox);
    //&connectionManager=new connection::ConnectionManagerFaussaire();
//TEMPORARY list for test
   MobileList={"Mobile Device n°1","Mobile Device n°2","Mobile Device n°3","Mobile Device n°4","Mobile Device n°5","Mobile Device n°6"};

 /*
  *   MobileList=connectionManagerFaussaire.getDevices();
  */


    // Fill combobox. (To be filled with the vector of connected devices recieved from "Connection")
    m_combobox->addItem(tr("None"));

    for(int i = 0; i < MobileList.size(); ++i)
{

        m_combobox->addItem(tr(MobileList[i]));
}


 /*
  *   for(int i=0; i<connectionManagerFaussaire.getNumConnections();++i)
  * {
  *  m_combobox->addItem(tr(MobileList[i].));
  * }
  */


    // Signals
       connect(
           m_combobox, SignalUtils::QComboBox_currentIndexChanged_int(), this,
           [=](int i) {
           setMobileDevice(i);
           emit mobileDeviceChanged(i); //déclenche AppInteractionProcessInspector::on_mobileDevicesChange
           });
 }
  void MobileDevicesWidget::setMobileDevice(int i)
  {
    QSignalBlocker b(this);
    m_combobox->setCurrentIndex(i);
  }
}
