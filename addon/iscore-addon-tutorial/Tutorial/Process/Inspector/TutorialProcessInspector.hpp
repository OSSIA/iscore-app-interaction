#pragma once
#include <Tutorial/Process/TutorialProcessModel.hpp>
#include <Process/Inspector/ProcessInspectorWidgetDelegate.hpp>
#include <Process/Inspector/ProcessInspectorWidgetDelegateFactory.hpp>
#include <iscore/command/Dispatchers/CommandDispatcher.hpp>

namespace Tutorial
{
class ProcessModel;
class PolymorphicEntity;

//! This is the widget that will be shown when clicking on a constraint
//! that has a Tutorial::ProcessModel process.
class InspectorWidget final :
        public Process::InspectorWidgetDelegate_T<Tutorial::ProcessModel>,
        public Nano::Observer // For automatic signal - slot destruction
{
    public:
        explicit InspectorWidget(
                const Tutorial::ProcessModel& object,
                const iscore::DocumentContext& context,
                QWidget* parent);

    private:
        void on_entityAdded(const PolymorphicEntity&);
        void on_entityRemoved(const PolymorphicEntity&);
        void addBanana();
        void rmBanana();
        CommandDispatcher<> m_dispatcher;
};


class InspectorFactory final :
        public Process::InspectorWidgetDelegateFactory_T<ProcessModel, InspectorWidget>
{
        ISCORE_CONCRETE("41b2ea17-9bec-4688-b5e0-d7fbabfd1038")
};
}
