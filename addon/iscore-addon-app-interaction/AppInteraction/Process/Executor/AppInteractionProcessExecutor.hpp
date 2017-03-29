#pragma once
#include <Engine/Executor/ProcessComponent.hpp>
#include <AppInteraction/Connection/ConnectionManagerFaussaire.hpp>
#include <State/Address.hpp>
#include <qobject.h>

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
namespace AppInteraction
{
class ProcessModel;
//! The class that does the actual execution, in the execution thread
class ProcessExecutor final :
        public ossia::time_process
{
public:
    ProcessExecutor(AppInteraction::ProcessModel& element, const Device::DeviceList&, const iscore::DocumentContext& context);

    void start() override;
    void stop() override;
    void pause() override;
    void resume() override;

    ossia::state_element offset(ossia::time_value) override;
    ossia::state_element state() override;

    ossia::state_element interactionValueReceived(const ossia::value&);

private:

    const Device::DeviceList& m_devices;
    int m_mobileDevice;
    connectionFaussaire::ConnectionManagerFaussaire m_connectionManager;
    ::State::AddressAccessor m_address;
};

//! Component and bridge between the GUI / Edition thread and the execution thread.
class ProcessExecutorComponent final :
        public Engine::Execution::ProcessComponent_T<
        AppInteraction::ProcessModel,
        AppInteraction::ProcessExecutor>
{
    COMPONENT_METADATA("4797971b-54cd-43e5-8514-e2e941303d1a")

    public:
        ProcessExecutorComponent(
            Engine::Execution::ConstraintComponent& parentConstraint,
            ProcessModel& element,
            const Engine::Execution::Context& ctx,
            //                const iscore::DocumentContext& context,
            const Id<iscore::Component>& id,
            QObject* parent);
};


using ProcessExecutorComponentFactory =
Engine::Execution::ProcessComponentFactory_T<ProcessExecutorComponent>;

}
