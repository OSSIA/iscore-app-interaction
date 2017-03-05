#include "InteractionTypeWidget.hpp"
#include <QComboBox>
#include <QHBoxLayout>
#include <iscore/widgets/MarginLess.hpp>
#include <iscore/widgets/SignalUtils.hpp>
#include <qvariant.h>


namespace State
{

  InteractionTypeWidget::InteractionTypeWidget(QWidget* parent) : QWidget{parent}
  {
    m_layout = new iscore::MarginLess<QHBoxLayout>{this};
    m_combobox = new QComboBox{this}; //appelé m_dataspace dans UnitWidget
    m_layout->addWidget(m_combobox);

    //TEMPORARY list for test
    InteractionTypeList={"InteractionType n°1","InteractionType n°2","InteractionType n°3"};


    // Fill combobox.
    m_combobox->addItem(tr("None"));

            for(int i = 0; i < InteractionTypeList.size(); ++i)
        {
               m_combobox->addItem(tr(InteractionTypeList[i]));
        }


  // Signals
     connect(
         m_combobox, SignalUtils::QComboBox_currentIndexChanged_int(), this,
         [=](int i) {
            setInteractionType(i);
             emit interactionTypeChanged(i); //déclenche AppInteractionProcessInspector::on_interactionTypeChange
        });

    }

  void InteractionTypeWidget::setInteractionType(int i)
  {
    // qDebug("/!\ setInteractionType...\n");

    QSignalBlocker b(this);
    //qDebug("signal blocker ok...\n");
    m_combobox->setCurrentIndex(i);
     //qDebug("setcurrentindex ok...\n");
    m_type = InteractionTypeList[i];
    // qDebug("setInteractionType to index %d\n",m_combobox->currentIndex());
  }

  char const* InteractionTypeWidget::getInteractionType() const
  {
      return m_type;
  }
}
