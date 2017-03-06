#pragma once
#include <Process/LayerView.hpp>
#include <QString>
#include <QTextLayout>

namespace AppInteraction
{
//! The View should only handle painting, and forwarding of
//! input events to the presenter. It will create a PolymorphicEntity on double click.
class AppInteractionView final : public Process::LayerView
{
    Q_OBJECT
    public:
        explicit AppInteractionView(QGraphicsItem* parent);

        void setText(const QString&);
        void setDisplayedName(const QString& s);

    signals:
        void doubleClicked();

    private:
        void paint_impl(QPainter*) const override;
        void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
        void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) override;

        QString m_text;
        QTextLayout m_textcache;
};
}
