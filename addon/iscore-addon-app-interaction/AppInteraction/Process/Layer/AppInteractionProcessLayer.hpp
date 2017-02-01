#pragma once
#include <AppInteraction/Process/AppInteractionProcessModel.hpp>
#include <Process/GenericProcessFactory.hpp>
#include <Process/ProcessMetadata.hpp>
#include <Process/LayerModel.hpp>

namespace AppInteraction
{
//! Layers are the base component for displaying. Think the "ViewModel" in MVVM.
using Layer = Process::LayerModel_T<ProcessModel>;
}

LAYER_METADATA(
        ,
        AppInteraction::Layer,
        "d5dc8583-3f7f-49ae-9664-fadda04f42fa",
        "AppInteractionLayer",
        "AppInteractionLayer"
        )
