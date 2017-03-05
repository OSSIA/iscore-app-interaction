#pragma once
#include "AppInteraction/Commands/AppInteractionCommandFactory.hpp"
#include <iscore/command/Command.hpp>
#include <iscore/model/path/Path.hpp>

struct DataStreamInput;
struct DataStreamOutput;

namespace AppInteraction
{
class ProcessModel;
class ChangeMobileDevice final : public iscore::Command
{
  ISCORE_COMMAND_DECL(CommandFactoryName(), ChangeMobileDevice, "ChangeMobileDevice")
public:
    ChangeMobileDevice(const ProcessModel&, int);

public:
  void undo() const override;
  void redo() const override;

protected:
  void serializeImpl(DataStreamInput&) const override;
  void deserializeImpl(DataStreamOutput&) override;

private:
  Path<ProcessModel> m_path;
  int m_old;
  int m_new;
};
}
