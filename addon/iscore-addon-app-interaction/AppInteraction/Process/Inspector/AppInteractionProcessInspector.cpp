#include "AppInteractionProcessInspector.hpp"
#include "AppInteraction/Process/AppInteractionProcessModel.hpp"
#include "AppInteraction/Commands/ChangeAddress.hpp"

#include <iscore/document/DocumentContext.hpp>
#include <Explorer/Widgets/AddressAccessorEditWidget.hpp>
#include <Explorer/DocumentPlugin/DeviceDocumentPlugin.hpp>
#include <Inspector/InspectorWidgetBase.hpp>
#include <ossia/detail/logger.hpp>
#include <QFormLayout>
#include <QLabel>
//#include <QPushButton>
#include <QWidget>
#include <State/Widgets/UnitWidget.hpp>
#include "AppInteraction/Process/State/Widgets/InteractionTypeWidget.hpp"


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


    m_lineEdit = new AddressAccessorEditWidget{
        context.plugin<DeviceDocumentPlugin>().explorer(), this};

    m_lineEdit->setAddress(process().address());
    con(process(), &ProcessModel::addressChanged, m_lineEdit,
        &AddressAccessorEditWidget::setAddress);

    connect(
        m_lineEdit, &AddressAccessorEditWidget::addressChanged, this,
        &InspectorWidget::on_addressChange);

    lay->addRow(tr("Address"), m_lineEdit);


    m_itw = new State::InteractionTypeWidget{{}, this};

    lay->addRow(tr("Interaction Type"), m_itw);

        /*
    auto& connectionManager = ctx.plugin<AppInteractionDocumentPlugin>().connectionManager();
    for(auto interaction : connectionManager.interactions())
    {
            m_itw->addLine(interaction.name());
    }
    */
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


}
