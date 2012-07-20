#include <QtGui>

#include "savingsinfogroup.h"

SavingsInfoGroup::SavingsInfoGroup(const QString &title, QWidget *parent)
  : QGroupBox(title, parent)
{
    requestedSavingsLabel = new QLabel("Requested savings:");
    requestedSavingsLineEdit = new QLineEdit();

    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->addWidget(requestedSavingsLabel);
    mainLayout->addWidget(requestedSavingsLineEdit);
    setLayout(mainLayout);
}


double SavingsInfoGroup::requestedSavings()
{
  return requestedSavingsLineEdit->text().toDouble();
}
