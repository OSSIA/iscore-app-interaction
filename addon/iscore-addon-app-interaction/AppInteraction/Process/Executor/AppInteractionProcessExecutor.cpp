#include "AppInteractionProcessExecutor.hpp"
#include <AppInteraction/Process/AppInteractionProcessModel.hpp>

#include <Device/Protocol/DeviceList.hpp>
#include <Explorer/DocumentPlugin/DeviceDocumentPlugin.hpp>
#include <Engine/iscore2OSSIA.hpp>
#include <ossia/editor/state/state_element.hpp>

namespace AppInteraction
{

ProcessExecutor::ProcessExecutor(
    const Device::DeviceList& devices):
  m_devices{devices}
{
    qDebug("tutu");
}


void ProcessExecutor::start()
{
}

void ProcessExecutor::stop()
{
}

void ProcessExecutor::pause()
{
}

void ProcessExecutor::resume()
{
}

ossia::state_element ProcessExecutor::offset(
    ossia::time_value off)
{
  return {};
}

ossia::state_element ProcessExecutor::state()
{
    /* exemple d'envoi de messages (à processing par ex) */
    qDebug("titi");
  State::Address address{"OSCDevice", {"a", "banana"}};
  State::Value value = State::Value::fromValue(std::abs(qrand()) % 100);
  State::Message m;
  m.address = address;
  m.value = value;

  if(auto res = Engine::iscore_to_ossia::message(m, m_devices))
  {
    if(unmuted())
      return *res;
    return {};
  }
  else
  {
    return {};
  }
}



ProcessExecutorComponent::ProcessExecutorComponent(
    Engine::Execution::ConstraintComponent& parentConstraint,
    AppInteraction::ProcessModel& element,
    const Engine::Execution::Context& ctx,
    const Id<iscore::Component>& id,
    QObject* parent):
  ProcessComponent_T{
    parentConstraint, element, ctx, id, "AppInteractionExecutorComponent", parent}
{
  m_ossia_process = std::make_shared<ProcessExecutor>(ctx.devices.list());
}

}
