#pragma once
#include <QWidget>

#include <iscore_addon_app_interaction_export.h>

 class QComboBox;
 class QHBoxLayout;
 namespace State
 {
class ISCORE_ADDON_APP_INTERACTION_EXPORT InteractionTypeWidget : public QWidget
 {
   Q_OBJECT
 public:
   InteractionTypeWidget( QWidget* parent);
   void setInteractionType(int);

signals:
   void interactionTypeChanged(int);

private:

   QHBoxLayout* m_layout{};
   QComboBox* m_combobox{};
   std::vector<const char*> InteractionTypeList;
 };
 }
