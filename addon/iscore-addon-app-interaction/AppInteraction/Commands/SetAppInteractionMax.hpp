#pragma once
#include <AppInteraction/Commands/AppInteractionCommandFactory.hpp>
#include <iscore/command/PropertyCommand.hpp>

#include <State/Unit.hpp>

namespace AppInteraction
{
class ProcessModel;
class SetMax final : public iscore::PropertyCommand
{
  ISCORE_COMMAND_DECL(CommandFactoryName(), SetMax, "Set AppInteraction maximum")
public:
  SetMax(Path<ProcessModel>&& path, double newval)
      : iscore::PropertyCommand{std::move(path), "max", newval}
  {
  }
};
}

