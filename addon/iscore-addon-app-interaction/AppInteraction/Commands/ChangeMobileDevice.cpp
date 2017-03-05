#include <Device/Node/DeviceNode.hpp>
#include <Explorer/Explorer/DeviceExplorerModel.hpp>
#include <QString>
#include <QStringList>
#include <algorithm>

#include "ChangeMobileDevice.hpp"
#include <ossia/editor/value/value_conversion.hpp>
#include "AppInteraction/Process/AppInteractionProcessModel.hpp"
#include <State/Value.hpp>
#include <State/ValueConversion.hpp>
#include <iscore/serialization/DataStreamVisitor.hpp>
#include <iscore/model/path/Path.hpp>
#include <iscore/model/path/PathSerialization.hpp>
#include <iscore/model/tree/TreeNode.hpp>

#include <ossia/editor/state/destination_qualifiers.hpp>

namespace AppInteraction
{

ChangeMobileDevice::ChangeMobileDevice(
    const ProcessModel& appinteract, int newval)
    : m_path{appinteract}
{
    {
  m_new = newval;
  m_old = appinteract.mobileDevice();
    }
}

void ChangeMobileDevice::undo() const
{
  auto& appinteract = m_path.find();

  {
    appinteract.setMobileDevice(m_old);
  }
}

void ChangeMobileDevice::redo() const
{
  auto& appinteract = m_path.find();

  {
    appinteract.setMobileDevice(m_new);
  }
}

void ChangeMobileDevice::serializeImpl(DataStreamInput& s) const
{
  s << m_path << m_old << m_new;
}

void ChangeMobileDevice::deserializeImpl(DataStreamOutput& s)
{
  s >> m_path >> m_old >> m_new;
}
}
