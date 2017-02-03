#pragma once
#include <AppInteraction/Process/Layer/AppInteractionProcessLayer.hpp>
#include <AppInteraction/Process/Layer/AppInteractionProcessPresenter.hpp>
#include <AppInteraction/Process/Layer/AppInteractionProcessView.hpp>

#include <Process/LayerModelPanelProxy.hpp>

namespace AppInteraction
{
    using LayerFactory = Process::GenericLayerFactory<
    AppInteraction::ProcessModel,
    AppInteraction::Layer,
    AppInteraction::AppInteractionPresenter,
    AppInteraction::AppInteractionView,
    Process::GraphicsViewLayerModelPanelProxy>;
}
