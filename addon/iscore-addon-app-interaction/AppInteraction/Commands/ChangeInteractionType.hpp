#pragma once
#include "AppInteraction/Commands/AppInteractionCommandFactory.hpp"
#include <iscore/command/Command.hpp>
#include <iscore/model/path/Path.hpp>

struct DataStreamInput;
struct DataStreamOutput;

namespace AppInteraction
{
class ProcessModel;
class ChangeInteractionType final : public iscore::Command
{
  ISCORE_COMMAND_DECL(CommandFactoryName(), ChangeInteractionType, "ChangeInteractionType")
public:
    ChangeInteractionType(const ProcessModel&, const char*);

public:
  void undo() const override;
  void redo() const override;

protected:
  void serializeImpl(DataStreamInput&) const override;
  void deserializeImpl(DataStreamOutput&) override;

private:
  Path<ProcessModel> m_path;
  const char* m_old;
  const char* m_new;
};
}
