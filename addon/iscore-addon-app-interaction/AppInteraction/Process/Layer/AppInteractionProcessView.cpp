#include "AppInteractionProcessView.hpp"
#include "AppInteraction/Process/State/Widgets/InteractionTypeWidget.hpp"
#include <Process/Style/ScenarioStyle.hpp>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QPainter>
#include <QFont>
#include <Process/Style/ProcessFonts.hpp>

namespace AppInteraction
{

AppInteractionView::AppInteractionView(
        QGraphicsItem* parent):
    LayerView{parent}
{
    setText("AppInteraction");

    auto f = iscore::Skin::instance().SansFont;
    f.setPointSize(8);

    m_textcache.setFont(f);
    m_textcache.setCacheEnabled(true);
}

void AppInteractionView::setText(const QString& txt)
{
    m_text = txt;
    update();
}

void AppInteractionView::setDisplayedName(const QString& s)
{
  m_textcache.setText(s);

  m_textcache.beginLayout();
  QTextLine line = m_textcache.createLine();
  line.setPosition(QPointF{0., 0.});

  m_textcache.endLayout();

  update();
}

void AppInteractionView::paint_impl(QPainter* painter) const
{
    auto font = iscore::Skin::instance().MonoFont;
    font.setPointSize(15);
    painter->setFont(font);
    painter->setPen(Qt::white);

    painter->drawText(QPointF{5., height() / 2.}, m_text);

    m_textcache.draw(painter, QPointF{5., 10});
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
