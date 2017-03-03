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
//ChangeAddress::ChangeAddress(
//    const ProcessModel& appinteract, const State::AddressAccessor& newval)
//    : m_path{appinteract}
//    , m_old{appinteract.address()/*, appinteract.min(), appinteract.max()*/}
//    , m_new(Explorer::makeFullAddressAccessorSettings(
//          newval, iscore::IDocument::documentContext(appinteract), 0., 1.))
//{
// //   Curve::CurveDomain c(m_new.domain.get(), m_new.value);
// //   m_new.domain.get() = ossia::net::make_domain(c.min, c.max);
//}


ChangeAddress::ChangeAddress(
    const ProcessModel& appinteract, const Device::FullAddressAccessorSettings& newval)
    : m_path{appinteract}
{
  m_new.address = newval.address;
  m_new.domain = newval.domain;



  m_old.address = appinteract.address();
//  m_old.domain = ossia::net::make_domain(appinteract.min(), appinteract.max());
}

void ChangeAddress::undo() const
{
  auto& appinteract = m_path.find();

  {
    //auto& dom = m_old.domain.get();
//    appinteract.setMin(dom.convert_min<double>());
//    appinteract.setMax(dom.convert_max<double>());

    appinteract.setAddress(m_old.address);
  }
}

void ChangeAddress::redo() const
{
  auto& appinteract = m_path.find();

  {
    //auto& dom = m_new.domain.get();
//    appinteract.setMin(dom.convert_min<double>());
//    appinteract.setMax(dom.convert_max<double>());
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
