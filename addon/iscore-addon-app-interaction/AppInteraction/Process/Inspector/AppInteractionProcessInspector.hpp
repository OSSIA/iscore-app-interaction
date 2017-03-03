#pragma once
#include <AppInteraction/Process/AppInteractionProcessModel.hpp>
#include <AppInteraction/Commands/ChangeAddress.hpp>
#include <Process/Inspector/ProcessInspectorWidgetDelegate.hpp>
#include <Process/Inspector/ProcessInspectorWidgetDelegateFactory.hpp>
#include <iscore/command/Dispatchers/CommandDispatcher.hpp>
#include "../State/Widgets/InteractionTypeWidget.hpp"
#include "../State/Widgets/MobileDevicesWidget.hpp"
#include <State/Unit.hpp>

namespace State
{
class UnitWidget;
}
namespace Device
{
struct FullAddressAccessorSettings;
}
namespace Explorer
{
class AddressAccessorEditWidget;
class DeviceExplorerModel;
}
namespace AppInteraction
{
class ProcessModel;
class PolymorphicEntity;

//! This is the widget that will be shown when clicking on a constraint
//! that has a AppInteraction::ProcessModel process.
class InspectorWidget final :
        public Process::InspectorWidgetDelegate_T<AppInteraction::ProcessModel>,
        public Nano::Observer // For automatic signal - slot destruction
{
    public:
        explicit InspectorWidget(
                const AppInteraction::ProcessModel& object,
                const iscore::DocumentContext& context,
                QWidget* parent);

    private:
    void on_addressChange(const Device::FullAddressAccessorSettings& newText);

    Explorer::AddressAccessorEditWidget* m_lineEdit{};
    State::InteractionTypeWidget* m_itw{};
    State::MobileDevicesWidget* m_mdw{};
    //State::UnitWidget* m_uw{};
    CommandDispatcher<> m_dispatcher;
};


class InspectorFactory final :
        public Process::InspectorWidgetDelegateFactory_T<ProcessModel, InspectorWidget>
{
        ISCORE_CONCRETE("41b2ea17-9bec-4688-b5e0-d7fbabfd1038")
};
}
