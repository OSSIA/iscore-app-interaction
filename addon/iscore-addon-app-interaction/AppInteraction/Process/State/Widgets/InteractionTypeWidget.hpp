#pragma once
#include <QWidget>
#include <State/Unit.hpp>

#include <iscore_addon_app_interaction_export.h>

 class QComboBox;
 class QHBoxLayout;
 namespace State
 {
class ISCORE_ADDON_APP_INTERACTION_EXPORT InteractionTypeWidget : public QWidget
 {
   Q_OBJECT
 public:
   InteractionTypeWidget(const State::Unit& u, QWidget* parent);

   State::Unit unit() const;
//   void setUnit(const State::Unit&);

// signals:
//   void unitChanged(const State::Unit&);

// private:
//   void on_dataspaceChanged(const State::Unit&);

   QHBoxLayout* m_layout{};
   QComboBox* m_combobox{};
   QComboBox* m_unit{};
 };
 }
