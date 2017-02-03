#include "AppInteractionProcessView.hpp"
#include <Process/Style/ScenarioStyle.hpp>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
namespace AppInteraction
{

AppInteractionView::AppInteractionView(
        QGraphicsItem* parent):
    LayerView{parent}
{

}

void AppInteractionView::setText(const QString& txt)
{
    m_text = txt;
    update();
}

void AppInteractionView::paint_impl(QPainter* painter) const
{
    auto font = iscore::Skin::instance().MonoFont;
    font.setPointSize(25);
    painter->setFont(font);
    painter->setPen(Qt::white);

    painter->drawText(QPointF{5., height() / 2.}, m_text);
}

void AppInteractionView::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
  // Necessary to get double click.
  event->accept();
}

void AppInteractionView::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event)
{
  emit doubleClicked();

  event->accept();
}
}
