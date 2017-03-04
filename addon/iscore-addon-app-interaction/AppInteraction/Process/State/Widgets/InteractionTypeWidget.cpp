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
            qDebug("Interaction type n°%d selected",i);
            /*emit interactionTypeChanged(m_combobox->itemData(i).value<State::InteractionTypeWidget>());*/
         });

    }

}
