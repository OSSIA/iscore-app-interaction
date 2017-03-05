#pragma once
#include <QWidget>
#include <iscore_addon_app_interaction_export.h>


 class QComboBox;
 class QHBoxLayout;
 namespace State
 {
class ISCORE_ADDON_APP_INTERACTION_EXPORT MobileDevicesWidget : public QWidget
 {
   Q_OBJECT
 public:
   MobileDevicesWidget( QWidget* parent);
   void setMobileDevice(int);

signals:
   void mobileDeviceChanged(int);

private:
   QHBoxLayout* m_layout{};
   QComboBox* m_combobox{};
   std::vector<const char*> MobileList;

 };
 }
