#pragma once
#include <QWidget>
#include <iscore_addon_app_interaction_export.h>
#include <AppInteraction/DocumentPlugin/AppInteractionDocumentPlugin.hpp>
#include "AppInteraction/Connection/ConnectionManagerFaussaire.hpp"
#include <AppInteraction/Connection/Connection.hpp>

 class QComboBox;
 class QHBoxLayout;
 namespace State
 {
class ISCORE_ADDON_APP_INTERACTION_EXPORT MobileDevicesWidget : public QWidget
 {
   Q_OBJECT
 public:
   MobileDevicesWidget(QWidget* parent, const iscore::DocumentContext &context);
   void setMobileDevice(int);

signals:
   void mobileDeviceChanged(int);

private:
   QHBoxLayout* m_layout{};
   QComboBox* m_combobox{};

   /**
   * @brief MobileList : existing connected mobile devices list
   */
  std::vector<connectionFaussaire::ConnectionFaussaire*> MobileList;

 };
 }
