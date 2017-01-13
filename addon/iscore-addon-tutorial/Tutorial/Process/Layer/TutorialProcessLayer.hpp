#pragma once
#include <Tutorial/Process/TutorialProcessModel.hpp>
#include <Process/GenericProcessFactory.hpp>
#include <Process/ProcessMetadata.hpp>
#include <Process/LayerModel.hpp>

namespace Tutorial
{
//! Layers are the base component for displaying. Think the "ViewModel" in MVVM.
using Layer = Process::LayerModel_T<ProcessModel>;
}

LAYER_METADATA(
        ,
        Tutorial::Layer,
        "d5dc8583-3f7f-49ae-9664-fadda04f42fa",
        "TutorialLayer",
        "TutorialLayer"
        )
