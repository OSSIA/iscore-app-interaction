#include <Device/Node/DeviceNode.hpp>
#include <Explorer/Explorer/DeviceExplorerModel.hpp>
#include <QString>
#include <QStringList>
#include <algorithm>

#include "ChangeAddress.hpp"
#include <ossia/editor/value/value_conversion.hpp>
#include "AppInteraction/Process/AppInteractionProcessModel.hpp"
//#include <Curve/Point/CurvePointModel.hpp>
#include <Device/Address/AddressSettings.hpp>
#include <Device/Address/Domain.hpp>
#include <State/Address.hpp>
#include <State/Value.hpp>
#include <State/ValueConversion.hpp>
#include <iscore/serialization/DataStreamVisitor.hpp>
#include <iscore/model/path/Path.hpp>
#include <iscore/model/path/PathSerialization.hpp>
#include <iscore/model/tree/TreeNode.hpp>

#include <ossia/editor/state/destination_qualifiers.hpp>
#include <ossia/network/domain/domain.hpp>

namespace AppInteraction
{

ChangeAddress::ChangeAddress(
    const ProcessModel& appinteract, const Device::FullAddressAccessorSettings& newval)
    : m_path{appinteract}
{
  m_new.address = newval.address;
  m_new.domain = newval.domain;

  m_old.address = appinteract.address();
}

void ChangeAddress::undo() const
{
  auto& appinteract = m_path.find();

  {
    appinteract.setAddress(m_old.address);
  }
}

void ChangeAddress::redo() const
{
  auto& appinteract = m_path.find();

  {
    appinteract.setAddress(m_new.address);
  }
}

void ChangeAddress::serializeImpl(DataStreamInput& s) const
{
  s << m_path << m_old << m_new;
}

void ChangeAddress::deserializeImpl(DataStreamOutput& s)
{
  s >> m_path >> m_old >> m_new;
}
}
