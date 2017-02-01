#include "AppInteractionProcessLocalTree.hpp"
#include <AppInteraction/Process/AppInteractionProcessModel.hpp>
#include <Engine/LocalTree/Property.hpp>

namespace AppInteraction
{

LocalTreeProcessComponent::LocalTreeProcessComponent(
        const Id<iscore::Component>& id,
        ossia::net::node_base& parent,
        AppInteraction::ProcessModel& proc,
        Engine::LocalTree::DocumentPlugin& sys,
        QObject* parent_obj):
    Engine::LocalTree::ProcessComponent_T<AppInteraction::ProcessModel>{parent, proc, sys, id, "AppInteractionComponent", parent_obj}
{
//    m_bananaProperty = Engine::LocalTree::add_property<int>(
//                node(), "bananas", &proc,
//                &AppInteraction::ProcessModel::bananas,
//                &AppInteraction::ProcessModel::setBananas,
//                &AppInteraction::ProcessModel::bananasChanged,
//                this);
}

LocalTreeProcessComponent::~LocalTreeProcessComponent()
{

}

}
