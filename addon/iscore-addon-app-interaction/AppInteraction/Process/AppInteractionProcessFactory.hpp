#pragma once
#include <Process/GenericProcessFactory.hpp>
#include <AppInteraction/Process/AppInteractionProcessModel.hpp>

namespace AppInteraction
{
using ProcessFactory =
    Process::GenericProcessModelFactory<
        AppInteraction::ProcessModel>;
}
