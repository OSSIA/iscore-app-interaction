#include <Device/Node/DeviceNode.hpp>
#include <Explorer/Explorer/DeviceExplorerModel.hpp>
#include <QString>
#include <QStringList>
#include <algorithm>

#include "ChangeInteractionType.hpp"
#include <ossia/editor/value/value_conversion.hpp>
#include <AppInteraction/Process/AppInteractionProcessModel.hpp>
#include <State/Value.hpp>
#include <State/ValueConversion.hpp>
#include <iscore/serialization/DataStreamVisitor.hpp>
#include <iscore/model/path/Path.hpp>
#include <iscore/model/path/PathSerialization.hpp>
#include <iscore/model/tree/TreeNode.hpp>

#include <ossia/editor/state/destination_qualifiers.hpp>

namespace AppInteraction
{

ChangeInteractionType::ChangeInteractionType(
    const ProcessModel& appinteract, int newval)
    : m_path{appinteract}
{
    {
  m_new = newval;
  m_old = appinteract.interactionType();
    }
}

void ChangeInteractionType::undo() const
{
  auto& appinteract = m_path.find();

  {
    appinteract.setInteractionType(m_old);
  }
}

void ChangeInteractionType::redo() const
{
  auto& appinteract = m_path.find();

  {
    appinteract.setInteractionType(m_new);
  }
}

void ChangeInteractionType::serializeImpl(DataStreamInput& s) const
{
  s << m_path << m_old << m_new;
}

void ChangeInteractionType::deserializeImpl(DataStreamOutput& s)
{
  s >> m_path >> m_old >> m_new;
}
}
