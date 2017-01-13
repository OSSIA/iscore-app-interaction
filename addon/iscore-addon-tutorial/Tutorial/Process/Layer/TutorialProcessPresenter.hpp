#pragma once
#include <Process/LayerPresenter.hpp>
#include <Tutorial/Process/Layer/TutorialProcessLayer.hpp>
#include <QPoint>

#include <Process/ZoomHelper.hpp>
#include <iscore/model/Identifier.hpp>
#include <Process/Focus/FocusDispatcher.hpp>

namespace Tutorial
{
class TutorialView;
//! The Presenter should update the view with the data of the model
//! and create commands to react to user actions in the view.
class TutorialPresenter final :
        public Process::LayerPresenter
{
    public:
        explicit TutorialPresenter(
                const Layer& model,
                TutorialView* view,
                const Process::ProcessPresenterContext& ctx,
                QObject* parent);

        // All the following functions are automatically called
        // by i-score when something is resize in the UI.
        void setWidth(qreal width) override;
        void setHeight(qreal height) override;

        void putToFront() override;
        void putBehind() override;

        void on_zoomRatioChanged(ZoomRatio) override;

        void parentGeometryChanged() override;

        const Process::LayerModel& layerModel() const override;
        const Id<Process::ProcessModel>& modelId() const override;

    private:
        void on_doubleClicked();

        const Layer& m_layer;
        TutorialView* m_view{};
};
}
