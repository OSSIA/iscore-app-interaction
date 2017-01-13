#include "TutorialProcessInspector.hpp"
#include <Tutorial/Commands/AddBanana.hpp>
#include <Tutorial/Commands/removebanana.hpp>

#include <iscore/document/DocumentContext.hpp>
#include <ossia/detail/logger.hpp>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>

namespace Tutorial
{

InspectorWidget::InspectorWidget(
        const Tutorial::ProcessModel& object,
        const iscore::DocumentContext& context,
        QWidget* parent):
    InspectorWidgetDelegate_T {object, parent},
    m_dispatcher{context.commandStack}
{
    // Here we create the GUI for the inspector with Qt widgets.
    auto lay = new QFormLayout{this};

    auto banana_label = new QLabel{this};
    lay->addRow(tr("Banana count"), banana_label);

    auto button = new QPushButton{tr("Add banana"), this};
    lay->addWidget(button);

    // Connection to the command
    connect(button, &QPushButton::pressed,
            this, &Tutorial::InspectorWidget::addBanana);

    auto button_rm = new QPushButton{tr("Rm banana"), this};
    lay->addWidget(button);

    // Connection to the command
    connect(button_rm, &QPushButton::pressed,
            this, &Tutorial::InspectorWidget::rmBanana);

    // When the model changes, this will be called.
    con(object, &Tutorial::ProcessModel::bananasChanged,
        this, [=] (int v) {
        banana_label->setText(QString::number(v));
    });

    banana_label->setText(QString::number(object.bananas()));

    // Due to a Qt limitation, we have another signal-slot system
    // for when the EntityMap changes.
    auto entity_label = new QLabel{this};
    lay->addRow("Entity count", entity_label);

    object.polymorphicEntities.added.connect<InspectorWidget, &InspectorWidget::on_entityAdded>(this);
    object.polymorphicEntities.removing.connect<InspectorWidget, &InspectorWidget::on_entityRemoved>(this);
}

void InspectorWidget::on_entityAdded(const PolymorphicEntity& e)
{
  ossia::logger().info("Entity {} added. PolymorphicEntity::someVirtualMethod() == {}", e.id().val(), e.someVirtualMethod());
}

void InspectorWidget::on_entityRemoved(const PolymorphicEntity& e)
{
  ossia::logger().info("Entity {} removed", e.id().val());
}

void InspectorWidget::addBanana()
{
    m_dispatcher.submitCommand<AddBanana>(process());
}

void InspectorWidget::rmBanana()
{
    m_dispatcher.submitCommand<RemoveBanana>(process());
}

}
