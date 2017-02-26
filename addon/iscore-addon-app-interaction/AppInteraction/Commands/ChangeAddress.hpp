#pragma once
#include "AppInteraction/Commands/AppInteractionCommandFactory.hpp"
#include <Device/Address/AddressSettings.hpp>
#include <iscore/command/Command.hpp>
#include <iscore/model/path/Path.hpp>

struct DataStreamInput;
struct DataStreamOutput;
namespace State
{
struct Address;
} // namespace iscore

namespace AppInteraction
{
class ProcessModel;
class ChangeAddress final : public iscore::Command
{
  ISCORE_COMMAND_DECL(CommandFactoryName(), ChangeAddress, "ChangeAddress")
public:
//  ChangeAddress(
//      const ProcessModel& appinteract, const State::AddressAccessor& newval);
//  ChangeAddress(
//      const ProcessModel& appinteract, Device::FullAddressAccessorSettings newval);
    ChangeAddress(
      const ProcessModel& appinteract, const Device::FullAddressSettings& newval);

public:
  void undo() const override;
  void redo() const override;

protected:
  void serializeImpl(DataStreamInput&) const override;
  void deserializeImpl(DataStreamOutput&) override;

private:
  Path<ProcessModel> m_path;
  Device::FullAddressAccessorSettings m_old, m_new;
};
}
