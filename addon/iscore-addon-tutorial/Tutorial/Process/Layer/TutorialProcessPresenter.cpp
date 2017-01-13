#include <Tutorial/Process/Layer/TutorialProcessPresenter.hpp>
#include <Tutorial/Process/Layer/TutorialProcessView.hpp>
#include <Tutorial/Commands/AddEntity.hpp>
#include <iscore/command/Dispatchers/CommandDispatcher.hpp>


namespace Tutorial
{
TutorialPresenter::TutorialPresenter(
        const Layer& layer,
        TutorialView* view,
        const Process::ProcessPresenterContext& ctx,
        QObject* parent):
    LayerPresenter{ctx, parent},
    m_layer{layer},
    m_view{view}
{
    const Tutorial::ProcessModel& p = layer.processModel();

    // From model to view :
    con(p, &ProcessModel::bananasChanged,
            this, [=] (int b) {
        m_view->setText("bananas: " + QString::number(b));
    });
    m_view->setText("bananas: " + QString::number(p.bananas()));

    // From view to model :
    connect(view, &TutorialView::doubleClicked,
            this, &TutorialPresenter::on_doubleClicked);
}

void TutorialPresenter::setWidth(qreal val)
{
    m_view->setWidth(val);
}

void TutorialPresenter::setHeight(qreal val)
{
    m_view->setHeight(val);
}

void TutorialPresenter::putToFront()
{
    m_view->setOpacity(1);
}

void TutorialPresenter::putBehind()
{
    m_view->setOpacity(0.2);
}

void TutorialPresenter::on_zoomRatioChanged(ZoomRatio)
{
}

void TutorialPresenter::parentGeometryChanged()
{
}

const Process::LayerModel& TutorialPresenter::layerModel() const
{
    return m_layer;
}

const Id<Process::ProcessModel>& TutorialPresenter::modelId() const
{
    return m_layer.processModel().id();
}

void TutorialPresenter::on_doubleClicked()
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
