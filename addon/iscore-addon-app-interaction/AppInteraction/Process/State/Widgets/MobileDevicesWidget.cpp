#include "MobileDevicesWidget.hpp"
// #include <ossia/editor/dataspace/dataspace.hpp>
// #include <ossia/editor/dataspace/dataspace_visitors.hpp>
#include <QComboBox>
#include <QHBoxLayout>
// #include <brigand/algorithms/for_each.hpp>
#include <iscore/widgets/MarginLess.hpp>
#include <iscore/widgets/SignalUtils.hpp>

namespace State
{

  MobileDevicesWidget::MobileDevicesWidget(const State::Unit& u, QWidget* parent) : QWidget{parent}
  {
    m_layout = new iscore::MarginLess<QHBoxLayout>{this};
    m_combobox = new QComboBox{this}; //appelé m_dataspace dans UnitWidget
    m_layout->addWidget(m_combobox);


    // Fill combobox. Unit is filled each time the dataspace changes
    m_combobox->addItem(tr("None"), QVariant::fromValue(State::Unit{}));
    m_combobox->addItem(tr("Mobile Device n°1"), QVariant::fromValue(State::Unit{}));
    m_combobox->addItem(tr("Mobile Device n°2"), QVariant::fromValue(State::Unit{}));
    m_combobox->addItem(tr("Mobile Device n°3"), QVariant::fromValue(State::Unit{}));
    m_combobox->addItem(tr("Mobile Device n°4"), QVariant::fromValue(State::Unit{}));



//State::Unit MobileDevicesWidget::unit() const
//{
 // return m_unit->currentData().value<State::Unit>();
//}

 }
}
