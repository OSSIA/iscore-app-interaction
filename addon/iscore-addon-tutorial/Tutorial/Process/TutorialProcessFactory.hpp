#pragma once
#include <Process/GenericProcessFactory.hpp>
#include <Tutorial/Process/TutorialProcessModel.hpp>

namespace Tutorial
{
using ProcessFactory =
    Process::GenericProcessModelFactory<
        Tutorial::ProcessModel>;
}
