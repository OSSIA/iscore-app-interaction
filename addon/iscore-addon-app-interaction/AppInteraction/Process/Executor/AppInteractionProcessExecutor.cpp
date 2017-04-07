#include "AppInteractionProcessExecutor.hpp"
#include <AppInteraction/Process/AppInteractionProcessModel.hpp>

#include <Device/Protocol/DeviceList.hpp>
#include <Explorer/DocumentPlugin/DeviceDocumentPlugin.hpp>
#include <ossia/editor/state/state_element.hpp>
#include <AppInteraction/DocumentPlugin/AppInteractionDocumentPlugin.hpp>
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
    m_duration{element.duration().sec()},
    m_min{element.min()},
    m_max{element.max()}
{
    if(m_mobileDevice != 0)
    {
        std::vector<mockConnection::MockConnection*> m_connections = m_connectionManager->getDevices();
        QObject::connect(
                    m_connections[m_mobileDevice-1], &mockConnection::MockConnection::interactionValueReturned,
                [=] (const auto& val) { this->interactionValueReceived(val); }); // activated when new ossia value received from app
    }
}

ProcessExecutor::~ProcessExecutor()
{
    if (m_mobileDevice != 0)
    {
        std::vector<mockConnection::MockConnection*> m_connections = m_connectionManager->getDevices();
        QObject::disconnect(m_connections[m_mobileDevice-1], &mockConnection::MockConnection::interactionValueReturned,
                NULL, (void**)0);
    }
}

void ProcessExecutor::start()
{
    if (m_interaction == 0)
    {
        qDebug("No interaction type chosen.");
        return;
    }

    std::string interaction = fmt::format("{:d}:{:f}", m_interaction-1, m_duration);

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
    if(auto res = Engine::iscore_to_ossia::message(m_msg, m_devices))
    {
        if(unmuted())
            return *res;
        return {};
    }
    else
        return {};
}

void ProcessExecutor::interactionValueReceived(const ossia::value& val){
    ossia::value m_val = val;

    if (m_min == m_max) //only send the received value
    {
        qDebug("Min and max ignored because min = max");
        return;
    }

     //Use of the min/max values :
    if (val.getType() == ossia::val_type::FLOAT && 0<=val.get<float>() && val.get<float>()<=1)
        m_val = ossia::value(val.get<float>()*(m_max-m_min)+m_min);
    else if (val.getType() == ossia::val_type::BOOL)
    {qDebug("Min and max ignored because boolean received from app");}
    else if (val.getType() == ossia::val_type::CHAR)
    {qDebug("Min and max ignored because char received from app");}
    else if (val.getType() == ossia::val_type::DESTINATION)
    {qDebug("Min and max ignored because destination received from app");}
    else if (val.getType() == ossia::val_type::IMPULSE)
    {qDebug("Min and max ignored because impulse received from app");}
    else if (val.getType() == ossia::val_type::INT)
    {qDebug("Min and max ignored because int received from app");}
    else if (val.getType() == ossia::val_type::STRING)
    {qDebug("Min and max ignored because string received from app");}
    else if (val.getType() == ossia::val_type::TUPLE)//std::vector<ossia::value>&
    {qDebug("Min and max ignored because tuple received from app");}
    else if (val.getType() == ossia::val_type::VEC2F
             && val.get<std::array<float,2>>()[0]>=0
             && val.get<std::array<float,2>>()[1]>=0
             && val.get<std::array<float,2>>()[0]<=1
             && val.get<std::array<float,2>>()[1]<=1)
    {
        m_val = ossia::value(std::array<float, 2>{{(float)(val.get<std::array<float,2>>()[0]*(m_max-m_min)+m_min),
                                                   (float)(val.get<std::array<float,2>>()[1]*(m_max-m_min)+m_min)}});
    }
    else if (val.getType() == ossia::val_type::VEC3F
             && val.get<std::array<float,3>>()[0]>=0
             && val.get<std::array<float,3>>()[1]>=0
             && val.get<std::array<float,3>>()[2]>=0
             && val.get<std::array<float,3>>()[0]<=1
             && val.get<std::array<float,3>>()[1]<=1
             && val.get<std::array<float,3>>()[2]<=1)
    {
        m_val = ossia::value(std::array<float, 3>{{(float)(val.get<std::array<float,3>>()[0]*(m_max-m_min)+m_min),
                                                   (float)(val.get<std::array<float,3>>()[1]*(m_max-m_min)+m_min),
                                                   (float)(val.get<std::array<float,3>>()[2]*(m_max-m_min)+m_min)}});
    }
    else if (val.getType() == ossia::val_type::VEC4F
             && val.get<std::array<float,4>>()[0]>=0
             && val.get<std::array<float,4>>()[1]>=0
             && val.get<std::array<float,4>>()[2]>=0
             && val.get<std::array<float,4>>()[3]>=0
             && val.get<std::array<float,4>>()[0]<=1
             && val.get<std::array<float,4>>()[1]<=1
             && val.get<std::array<float,4>>()[2]<=1
             && val.get<std::array<float,4>>()[3]<=1)
    {
        m_val = ossia::value(std::array<float, 4>{{(float)(val.get<std::array<float,4>>()[0]*(m_max-m_min)+m_min),
                                                   (float)(val.get<std::array<float,4>>()[1]*(m_max-m_min)+m_min),
                                                   (float)(val.get<std::array<float,4>>()[2]*(m_max-m_min)+m_min),
                                                   (float)(val.get<std::array<float,4>>()[3]*(m_max-m_min)+m_min)}});
    }
    else
        qDebug("Non-Recognized type or float out of [0,1] received from app --> values sent without using the ratio.");

    State::Value value = State::Value::fromValue(State::fromOSSIAValue(m_val));
    m_msg.address = m_address;
    m_msg.value = value;
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
