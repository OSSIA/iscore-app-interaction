#include "AppInteractionProcessExecutor.hpp"
#include <AppInteraction/Process/AppInteractionProcessModel.hpp>

#include <Device/Protocol/DeviceList.hpp>
#include <Explorer/DocumentPlugin/DeviceDocumentPlugin.hpp>
#include <Engine/iscore2OSSIA.hpp>
#include <ossia/editor/state/state_element.hpp>

namespace AppInteraction
{

ProcessExecutor::ProcessExecutor(AppInteraction::ProcessModel& element,
    const Device::DeviceList& devices):
  m_devices{devices}
{
    m_mobileDevice = element.mobileDevice();
}


void ProcessExecutor::start()
{
        qDebug("START");
}

void ProcessExecutor::stop()
{
        qDebug("STOP");
}

void ProcessExecutor::pause()
{
    qDebug("PAUSE");
}

void ProcessExecutor::resume()
{
        qDebug("RESUME");
}

ossia::state_element ProcessExecutor::offset(
    ossia::time_value off)
{
    qDebug("OFFSET");
  return {};
}

ossia::state_element ProcessExecutor::state()
{
    /* exemple d'envoi de messages (à processing par ex) */
  //qDebug("titi"); //pratique pour debugage
  State::Address address{"OSCdevice", {"particle", "density"}};

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
  m_ossia_process = std::make_shared<ProcessExecutor>(element, ctx.devices.list());
 }

}
