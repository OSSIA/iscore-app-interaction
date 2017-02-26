#include <AppInteraction/Process/Layer/AppInteractionProcessPresenter.hpp>
#include <AppInteraction/Process/Layer/AppInteractionProcessView.hpp>
#include <AppInteraction/Commands/AddEntity.hpp>
#include <iscore/command/Dispatchers/CommandDispatcher.hpp>


namespace AppInteraction
{
AppInteractionPresenter::AppInteractionPresenter(
        const Layer& layer,
        AppInteractionView* view,
        const Process::ProcessPresenterContext& ctx,
        QObject* parent):
    LayerPresenter{ctx, parent},
    m_layer{layer},
    m_view{view}
{
    const AppInteraction::ProcessModel& p = layer.processModel();

    // From view to model :
    connect(view, &AppInteractionView::doubleClicked,
            this, &AppInteractionPresenter::on_doubleClicked);
}

void AppInteractionPresenter::setWidth(qreal val)
{
    m_view->setWidth(val);
}

void AppInteractionPresenter::setHeight(qreal val)
{
    m_view->setHeight(val);
}

void AppInteractionPresenter::putToFront()
{
    m_view->setOpacity(1);
}

void AppInteractionPresenter::putBehind()
{
    m_view->setOpacity(0.2);
}

void AppInteractionPresenter::on_zoomRatioChanged(ZoomRatio)
{
}

void AppInteractionPresenter::parentGeometryChanged()
{
}

const Process::LayerModel& AppInteractionPresenter::layerModel() const
{
    return m_layer;
}

const Id<Process::ProcessModel>& AppInteractionPresenter::modelId() const
{
    return m_layer.processModel().id();
}

void AppInteractionPresenter::on_doubleClicked()
{
    const PolymorphicElementFactoryList& entity_list =
        m_context // Layer context
        .context  // Document context
        .app      // Application context
        .interfaces<PolymorphicElementFactoryList>();

    // If there are some factories available
    if(!entity_list.empty())
    {
      // Here we take the first one but of course
      // there are plenty of other ways : for instance
      // putting them all in a widget and displaying the list.

      auto factory_it = entity_list.begin(); // iterator<std::pair<key, value>>;

      //! This key will allow us to refer to this specific factory in the future.
      //! Objects inheriting from iscore::SerializableInterface also have a method that gives this key.
      auto factory_key = factory_it->concreteKey();

      CommandDispatcher<> disp{m_context.context.commandStack};

      disp.submitCommand<AddEntity>(
              m_layer.processModel(), // The object on which it is applied
              factory_key // The factory that we used.
      );

    }
}

}
