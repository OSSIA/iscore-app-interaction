#pragma once
#include <AppInteraction/Commands/AppInteractionCommandFactory.hpp>
#include <iscore/command/PropertyCommand.hpp>

#include <State/Unit.hpp>

namespace AppInteraction
{
class ProcessModel;
class SetMin final : public iscore::PropertyCommand
{
  ISCORE_COMMAND_DECL(CommandFactoryName(), SetMin, "Set AppInteraction minimum")
public:
  SetMin(Path<ProcessModel>&& path, double newval)
      : iscore::PropertyCommand{std::move(path), "min", newval}
  {
  }
};
}

