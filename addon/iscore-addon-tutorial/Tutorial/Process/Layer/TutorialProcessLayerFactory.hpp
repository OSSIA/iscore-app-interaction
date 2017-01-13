#pragma once
#include <Tutorial/Process/Layer/TutorialProcessLayer.hpp>
#include <Tutorial/Process/Layer/TutorialProcessPresenter.hpp>
#include <Tutorial/Process/Layer/TutorialProcessView.hpp>

#include <Process/LayerModelPanelProxy.hpp>

namespace Tutorial
{
    using LayerFactory = Process::GenericLayerFactory<
    Tutorial::ProcessModel,
    Tutorial::Layer,
    Tutorial::TutorialPresenter,
    Tutorial::TutorialView,
    Process::GraphicsViewLayerModelPanelProxy>;
}
