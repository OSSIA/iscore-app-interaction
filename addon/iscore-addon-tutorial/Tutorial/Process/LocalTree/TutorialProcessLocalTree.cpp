#include "TutorialProcessLocalTree.hpp"
#include <Tutorial/Process/TutorialProcessModel.hpp>
#include <Engine/LocalTree/Property.hpp>

namespace Tutorial
{

LocalTreeProcessComponent::LocalTreeProcessComponent(
        const Id<iscore::Component>& id,
        ossia::net::node_base& parent,
        Tutorial::ProcessModel& proc,
        Engine::LocalTree::DocumentPlugin& sys,
        QObject* parent_obj):
    Engine::LocalTree::ProcessComponent_T<Tutorial::ProcessModel>{parent, proc, sys, id, "TutorialComponent", parent_obj}
{
    m_bananaProperty = Engine::LocalTree::add_property<int>(
                node(), "bananas", &proc,
                &Tutorial::ProcessModel::bananas,
                &Tutorial::ProcessModel::setBananas,
                &Tutorial::ProcessModel::bananasChanged,
                this);
}

LocalTreeProcessComponent::~LocalTreeProcessComponent()
{

}

}
