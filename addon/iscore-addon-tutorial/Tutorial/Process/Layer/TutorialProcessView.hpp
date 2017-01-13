#pragma once
#include <Process/LayerView.hpp>

namespace Tutorial
{
//! The View should only handle painting, and forwarding of
//! input events to the presenter. It will create a PolymorphicEntity on double click.
class TutorialView final : public Process::LayerView
{
    Q_OBJECT
    public:
        explicit TutorialView(QGraphicsItem* parent);

        void setText(const QString&);

    signals:
        void doubleClicked();

    private:
        void paint_impl(QPainter*) const override;
        void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
        void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) override;

        QString m_text;

};
}
