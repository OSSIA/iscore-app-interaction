#include "MobileDevicesWidget.hpp"
#include <QComboBox>
#include <QHBoxLayout>
#include <iscore/widgets/MarginLess.hpp>
#include <iscore/widgets/SignalUtils.hpp>
#include <qvariant.h>


namespace State
{

MobileDevicesWidget::MobileDevicesWidget( QWidget* parent, const iscore::DocumentContext& context) : QWidget{parent}
{

    m_layout = new iscore::MarginLess<QHBoxLayout>{this};
    m_combobox = new QComboBox{this};
    m_layout->addWidget(m_combobox);

    auto* m_connectionManager = context.plugin<AppInteraction::DocumentPlugin>().connectionManager();

    MobileList=m_connectionManager->getDevices();



    // Fill combobox. (To be filled with the vector of connected devices recieved from "Connection")
    m_combobox->addItem(tr("None"));
    for(int i=0; i<m_connectionManager->getNumConnections();++i)
    {
        m_combobox->addItem(tr(MobileList[i]->getDeviceName().c_str()));
    }

    // Signals
    connect(
                m_combobox, SignalUtils::QComboBox_currentIndexChanged_int(), this,
                [=](int i) {
        setMobileDevice(i);
        emit mobileDeviceChanged(i); //causes AppInteractionProcessInspector::on_mobileDevicesChange
    });
}
void MobileDevicesWidget::setMobileDevice(int i)
{
    QSignalBlocker b(this);
    m_combobox->setCurrentIndex(i); //modify current menu index --> set on i
}
}
