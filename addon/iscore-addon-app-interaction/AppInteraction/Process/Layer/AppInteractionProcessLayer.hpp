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
        "14b2f6ce-cd47-4330-9134-b50e711cd561",
        "AppInteractionLayer",
        "AppInteractionLayer"
        )
