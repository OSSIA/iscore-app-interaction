#pragma once
#include <Engine/LocalTree/Scenario/ProcessComponent.hpp>
#include <Engine/LocalTree/LocalTreeComponent.hpp>

namespace AppInteraction
{
class ProcessModel;

class EffectComponent;
class EffectProcessComponent;
class EffectFactoryList;

//! This component displays informations about an object in the Device Explorer,
//! in the left panel.
class LocalTreeProcessComponent :
        public Engine::LocalTree::ProcessComponent_T<ProcessModel>
{
        COMPONENT_METADATA("b387ed01-831a-487d-8686-42094813f2a7")

    public:
       LocalTreeProcessComponent(
               const Id<iscore::Component>& id,
               ossia::net::node_base& parent,
               AppInteraction::ProcessModel& scenario,
               Engine::LocalTree::DocumentPlugin& doc,
               QObject* parent_obj);

    ~LocalTreeProcessComponent();

    private:
        std::unique_ptr<Engine::LocalTree::BaseProperty> m_bananaProperty;
};

using LocalTreeProcessComponentFactory = Engine::LocalTree::ProcessComponentFactory_T<LocalTreeProcessComponent>;
}
