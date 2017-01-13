#include "TutorialPanelDelegate.hpp"
#include <QFormLayout>
#include <QLabel>

namespace Tutorial
{

PanelDelegate::PanelDelegate(
        const iscore::GUIApplicationContext& ctx):
    iscore::PanelDelegate{ctx}
{
    m_widget = new QWidget;
    auto lay = new QFormLayout{m_widget};

    lay->addWidget(new QLabel{tr("This is a panel.")});
}

QWidget* PanelDelegate::widget()
{
    return m_widget;
}

const iscore::PanelStatus& PanelDelegate::defaultPanelStatus() const
{
    static const iscore::PanelStatus status{
        true,
        Qt::RightDockWidgetArea,
        10,
        QObject::tr("Tutorial"),
        QObject::tr("Ctrl+T")};

    return status;
}

void PanelDelegate::on_modelChanged(
        iscore::MaybeDocument oldm,
        iscore::MaybeDocument newm)
{

}

void PanelDelegate::setNewSelection(
        const Selection& s)
{
}


std::unique_ptr<iscore::PanelDelegate> PanelDelegateFactory::make(
        const iscore::GUIApplicationContext& ctx)
{
    return std::make_unique<PanelDelegate>(ctx);
}

}
