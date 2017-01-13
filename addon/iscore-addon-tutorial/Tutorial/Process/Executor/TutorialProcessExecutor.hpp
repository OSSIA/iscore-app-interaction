#pragma once
#include <Engine/Executor/ProcessComponent.hpp>

namespace Device
{
class DeviceList;
}
/**
 * These classes provide execution components to a process.
 * I.E. what happens once the score plays.
 *
 * Please refer to the Engine::Execution documentation.
 */
namespace Tutorial
{
class ProcessModel;
//! The class that does the actual execution, in the execution thread
class ProcessExecutor final :
        public ossia::time_process
{
    public:
        ProcessExecutor(const Device::DeviceList&);

        void start() override;
        void stop() override;
        void pause() override;
        void resume() override;

        ossia::state_element offset(ossia::time_value) override;
        ossia::state_element state() override;

    private:
        const Device::DeviceList& m_devices;
};

//! Component and bridge between the GUI / Edition thread and the execution thread.
class ProcessExecutorComponent final :
        public Engine::Execution::ProcessComponent_T<
            Tutorial::ProcessModel,
            Tutorial::ProcessExecutor>
{
        COMPONENT_METADATA("4797971b-54cd-43e5-8514-e2e941303d1a")
    public:
        ProcessExecutorComponent(
                Engine::Execution::ConstraintComponent& parentConstraint,
                ProcessModel& element,
                const Engine::Execution::Context& ctx,
                const Id<iscore::Component>& id,
                QObject* parent);
};


using ProcessExecutorComponentFactory =
    Engine::Execution::ProcessComponentFactory_T<ProcessExecutorComponent>;

}
