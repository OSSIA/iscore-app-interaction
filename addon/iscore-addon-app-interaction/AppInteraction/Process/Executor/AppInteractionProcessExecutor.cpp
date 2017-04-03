#include "AppInteractionProcessExecutor.hpp"
#include <AppInteraction/Process/AppInteractionProcessModel.hpp>

#include <Device/Protocol/DeviceList.hpp>
#include <Explorer/DocumentPlugin/DeviceDocumentPlugin.hpp>
#include <Engine/iscore2OSSIA.hpp>
#include <ossia/editor/state/state_element.hpp>
#include <AppInteraction/DocumentPlugin/AppInteractionDocumentPlugin.hpp>

//#include <State/Value.hpp>
#include <State/ValueConversion.hpp>



namespace AppInteraction
{

ProcessExecutor::ProcessExecutor(AppInteraction::ProcessModel& element,
                                 const Device::DeviceList& devices,
                                 const iscore::DocumentContext& context):
    m_devices{devices},
    m_mobileDevice{element.mobileDevice()},
    m_connectionManager{context.plugin<AppInteraction::DocumentPlugin>().connectionManager()},
    m_address{element.address()},
    m_interaction{element.interactionType()},
    m_duration{element.duration().sec()}
{
    qDebug("ProcessExecutor : address : %s",m_address.toString().toStdString().c_str());

    m_newMessageCreated = false;

    if(m_mobileDevice != 0)
    {
        std::vector<connectionFaussaire::ConnectionFaussaire*> m_connections = m_connectionManager->getDevices();
        QObject::connect(
                    m_connections[m_mobileDevice-1], &connectionFaussaire::ConnectionFaussaire::interactionValueReturned,
                [=] (const auto& val) { this->interactionValueReceived(val); }); // activated when new ossia value received from app
    }
}

ProcessExecutor::~ProcessExecutor()
{
    std::vector<connectionFaussaire::ConnectionFaussaire*> m_connections = m_connectionManager->getDevices();
    QObject::disconnect(m_connections[m_mobileDevice-1], &connectionFaussaire::ConnectionFaussaire::interactionValueReturned,
            NULL, (void**)0);
}

void ProcessExecutor::start()
{
    if (m_interaction == 0)
    {
        qDebug("No interaction type chosen");
        return;
    }
    std::string interaction = fmt::format("{:d}:{:f}:{:d}", m_interaction-1, m_duration,1);

    if (m_mobileDevice>0)
        m_connectionManager->getDevices()[m_mobileDevice-1]->sendInteraction(interaction);
    else
        qDebug("No Mobile device selected -> no interaction sent.");
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
    if (m_newMessageCreated == true){
        m_newMessageCreated = false;

        State::Value value = State::Value::fromValue(State::fromOSSIAValue(m_val));
        State::Message m;
        m.address = m_address;
        m.value = value;
        qDebug("Ossia value : %f", m_val.get<float>());
        qDebug("Msg address : %s",m.address.toString().toStdString().c_str());

        if(auto res = Engine::iscore_to_ossia::message(m, m_devices))
        {
            if(unmuted())
            {
                qDebug("msg sent ok");
                return *res;
            }
            return {};
        }
        else
        {
            qDebug("error while sending msg");
            return {};
        }
    }
    return {};
}

void ProcessExecutor::interactionValueReceived(const ossia::value& val){
    m_newMessageCreated = true;
    m_val = val;
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
    m_ossia_process = std::make_shared<ProcessExecutor>(element, ctx.devices.list(), ctx.doc);
}

}
