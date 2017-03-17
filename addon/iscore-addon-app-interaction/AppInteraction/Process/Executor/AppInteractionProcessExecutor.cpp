#include "AppInteractionProcessExecutor.hpp"
#include <AppInteraction/Process/AppInteractionProcessModel.hpp>

#include <Device/Protocol/DeviceList.hpp>
#include <Explorer/DocumentPlugin/DeviceDocumentPlugin.hpp>
#include <Engine/iscore2OSSIA.hpp>
#include <ossia/editor/state/state_element.hpp>
#include <AppInteraction/DocumentPlugin/AppInteractionDocumentPlugin.hpp>

#include <State/Value.hpp>
#include <State/ValueConversion.hpp>


namespace AppInteraction
{

ProcessExecutor::ProcessExecutor(AppInteraction::ProcessModel& element,
                                 const Device::DeviceList& devices, const Engine::Execution::Context& context):
    m_devices{devices}, m_connectionManager{context.doc.plugin<AppInteraction::DocumentPlugin>().connectionManager()}
{
    m_mobileDevice = element.mobileDevice();
}


void ProcessExecutor::start()
{
    qDebug("START ...");

    m_connectionManager.getDevices()[m_mobileDevice].sendInteraction("0:05:01");
//    State::Value value = State::fromOSSIAValue(vals.back());


//    State::Message m;
//    m.address = address;
//    m.value = value;

//    if(auto res = Engine::iscore_to_ossia::message(m, m_devices))
//    {
//        if(unmuted())
//            return *res;
//        return {};
//    }
//    else
//    {
//        return {};
//    }
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

//    State::Address address{"OSCdevice", {"particle", "density"}};

    //State::Value value = State::Value::fromValue(std::abs(qrand()) % 100);


    /*exemple d'envoie de messages à processing via un value reçu de ConnectionFaussaire*/

//    std::vector<ossia::value> vals= (*cf).sendInteraction("Hi!^^");
//    State::Value value = State::fromOSSIAValue(vals.back());


//    State::Message m;
//    m.address = address;
//    m.value = value;

//    if(auto res = Engine::iscore_to_ossia::message(m, m_devices))
//    {
//        if(unmuted())
//            return *res;
//        return {};
//    }
//    else
//    {
        return {};
//    }
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
    m_ossia_process = std::make_shared<ProcessExecutor>(element, ctx.devices.list(), ctx);
}

}
