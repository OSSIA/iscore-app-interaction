#include "AppInteractionProcessInspector.hpp"
#include "AppInteraction/Process/AppInteractionProcessModel.hpp"
#include "AppInteraction/Commands/ChangeAddress.hpp"
#include "AppInteraction/Commands/ChangeInteractionType.hpp"
#include "AppInteraction/Commands/ChangeMobileDevice.hpp"
#include "AppInteraction/Commands/SetAppInteractionMax.hpp"
#include "AppInteraction/Commands/SetAppInteractionMin.hpp"
#include "AppInteraction/DocumentPlugin/AppInteractionDocumentPlugin.hpp"

#include <iscore/document/DocumentContext.hpp>
#include <Explorer/Widgets/AddressAccessorEditWidget.hpp>
#include <Explorer/DocumentPlugin/DeviceDocumentPlugin.hpp>
#include <Inspector/InspectorWidgetBase.hpp>
#include <ossia/detail/logger.hpp>
#include <QFormLayout>
#include <QLabel>
#include <QSpinBox>
#include <iscore/widgets/SpinBoxes.hpp>
//#include <QPushButton>
#include <QWidget>
#include "AppInteraction/Process/State/Widgets/InteractionTypeWidget.hpp"
#include "AppInteraction/Process/State/Widgets/MobileDevicesWidget.hpp"
#include <string.h>
#include <AppInteraction/Connection/ConnectionManagerFaussaire.hpp>
#include <AppInteraction/Connection/ConnectionFaussaire.hpp>

namespace AppInteraction
{

InspectorWidget::InspectorWidget(
        const AppInteraction::ProcessModel& object,
        const iscore::DocumentContext& context,
        QWidget* parent):
    InspectorWidgetDelegate_T {object, parent},
    m_dispatcher{context.commandStack}
{
    using namespace Explorer;

    // Here we create the GUI for the inspector with Qt widgets.
    auto lay = new QFormLayout{this};

    // Address:
    m_lineEdit = new AddressAccessorEditWidget{
            context.plugin<DeviceDocumentPlugin>().explorer(), this};

    m_lineEdit->setAddress(process().address());
    con(process(), &ProcessModel::addressChanged, m_lineEdit,
        &AddressAccessorEditWidget::setAddress);

    connect(
                m_lineEdit, &AddressAccessorEditWidget::addressChanged, this,
                &InspectorWidget::on_addressChange);

    lay->addRow(tr("Address"), m_lineEdit);


    //InteractionType:
    m_itw = new State::InteractionTypeWidget{this};
    con(process(), &ProcessModel::interactionTypeChanged, m_itw,
        &State::InteractionTypeWidget::setInteractionType);

    m_itw->setInteractionType(process().interactionType());

    connect(
                m_itw, &State::InteractionTypeWidget::interactionTypeChanged, this,
                &InspectorWidget::on_interactionTypeChange);

    lay->addRow(tr("Interaction Type"), m_itw);


    //MobileDevice:
    m_mdw = new State::MobileDevicesWidget{this, context};

    con(process(), &ProcessModel::mobileDeviceChanged, m_mdw,
        &State::MobileDevicesWidget::setMobileDevice);

    m_mdw->setMobileDevice(process().mobileDevice());

    connect(
                m_mdw, &State::MobileDevicesWidget::mobileDeviceChanged, this,
                &InspectorWidget::on_mobileDeviceChange);

    lay->addRow(tr("Mobile Devices"), m_mdw);

    //auto& m_plugin = context.plugin<AppInteraction::DocumentPlugin>().connectionManager();
    //  connectionManager->openConnection();
    //    for(auto interaction : connectionManager->interactions())
    //    {
    //            m_itw->addLine(interaction.name());
    //    }

    //Min/Max

        m_minsb = new iscore::SpinBox<float>{this};
        m_maxsb = new iscore::SpinBox<float>{this};


        con(process(), &ProcessModel::minChanged, m_minsb,
            &QDoubleSpinBox::setValue);
        con(process(), &ProcessModel::maxChanged, m_maxsb,
            &QDoubleSpinBox::setValue);

        m_minsb->setValue(process().min());
        m_maxsb->setValue(process().max());

        connect(
            m_minsb, &QAbstractSpinBox::editingFinished, this,
            &InspectorWidget::on_minValueChanged);
        connect(
            m_maxsb, &QAbstractSpinBox::editingFinished, this,
            &InspectorWidget::on_maxValueChanged);

        lay->addRow(tr("Min"), m_minsb);
        lay->addRow(tr("Max"), m_maxsb);
}

void InspectorWidget::on_addressChange(const Device::FullAddressAccessorSettings& newAddr)
{
    // Various checks
    if (newAddr.address == process().address())
        return;

    if (newAddr.address.address.path.isEmpty())
        return;

    auto cmd = new ChangeAddress{process(), newAddr};

    m_dispatcher.submitCommand(cmd);
}

void InspectorWidget::on_interactionTypeChange(int newType)
{
    //    qDebug("on_interactionTypeChange ... \n");
    // Various checks
    if (newType==0)
        return;

    //qDebug("actuel type : %d\n",process().interactionType());
    //qDebug("new type : %d\n",newType);
    if (newType == process().interactionType())
        return;

    auto cmd = new ChangeInteractionType{process(), newType};
    m_dispatcher.submitCommand(cmd);

    //qDebug("on_interactionTypeChange OK ! \n");
}

void InspectorWidget::on_mobileDeviceChange(int newDevice)
{
    // Various checks

    if (newDevice == process().mobileDevice())
        return;

    auto cmd = new ChangeMobileDevice{process(), newDevice};
    m_dispatcher.submitCommand(cmd);

}
void InspectorWidget::on_minValueChanged()
{
  auto newVal = m_minsb->value();
 /* qDebug(" newval %lf\n",newVal);
  qDebug("min %lf\n",process().min()); OK*/
  if (newVal != process().min())
  {
    auto cmd = new SetMin{process(), newVal};

    m_dispatcher.submitCommand(cmd);
  }
}

void InspectorWidget::on_maxValueChanged()
{
  auto newVal = m_maxsb->value();
  if (newVal != process().max())
  {
    auto cmd = new SetMax{process(), newVal};

    m_dispatcher.submitCommand(cmd);
  }
}

}
