#pragma once
#include <AppInteraction/Process/AppInteractionProcessModel.hpp>
#include <AppInteraction/Commands/ChangeAddress.hpp>
#include <Process/Inspector/ProcessInspectorWidgetDelegate.hpp>
#include <Process/Inspector/ProcessInspectorWidgetDelegateFactory.hpp>
#include <iscore/command/Dispatchers/CommandDispatcher.hpp>
#include <AppInteraction/Process//State/Widgets/InteractionTypeWidget.hpp>
#include <AppInteraction/Process/State/Widgets/MobileDevicesWidget.hpp>
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
class QDoubleSpinBox;
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
    // Methods called when particular signals received :
    void on_addressChange(const Device::FullAddressAccessorSettings& newText);
    void on_interactionTypeChange(int);
    void on_mobileDeviceChange(int);
    void on_minValueChanged();
    void on_maxValueChanged();

    //Widgets used in the inspector:
    Explorer::AddressAccessorEditWidget* m_lineEdit{};
    State::InteractionTypeWidget* m_itw{};
    State::MobileDevicesWidget* m_mdw{};
    QDoubleSpinBox *m_minsb{}, *m_maxsb{};

    CommandDispatcher<> m_dispatcher;
};


class InspectorFactory final :
        public Process::InspectorWidgetDelegateFactory_T<ProcessModel, InspectorWidget>
{
        ISCORE_CONCRETE("37056044-9a01-4343-837d-1c26a973739d")
};
}
