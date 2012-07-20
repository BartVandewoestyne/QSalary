#include <QtGui>

#include "personinfogroup.h"

PersonInfoGroup::PersonInfoGroup(const QString &title, QWidget *parent)
    : QGroupBox(title, parent)
{
    nameLabel = new QLabel("Name:");
    nameLineEdit = new QLineEdit();
    QHBoxLayout *nameLayout = new QHBoxLayout();
    nameLayout->addWidget(nameLabel);
    nameLayout->addWidget(nameLineEdit);

    netSalaryLabel = new QLabel("Net salary:");
    netSalaryLineEdit = new QLineEdit();
    QHBoxLayout *salaryLayout = new QHBoxLayout();
    salaryLayout->addWidget(netSalaryLabel);
    salaryLayout->addWidget(netSalaryLineEdit);

    mealVouchersLabel = new QLabel("Average number of meal vouchers per month:");
    mealVouchersLineEdit = new QLineEdit();
    QHBoxLayout *mealVouchersLayout = new QHBoxLayout();
    mealVouchersLayout->addWidget(mealVouchersLabel);
    mealVouchersLayout->addWidget(mealVouchersLineEdit);

    mealVouchersValueLabel = new QLabel("Value of a meal voucher:");
    mealVouchersValueLineEdit = new QLineEdit();
    QHBoxLayout *mealVouchersValueLayout = new QHBoxLayout();
    mealVouchersValueLayout->addWidget(mealVouchersValueLabel);
    mealVouchersValueLayout->addWidget(mealVouchersValueLineEdit);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(nameLayout);
    mainLayout->addLayout(salaryLayout);
    mainLayout->addLayout(mealVouchersLayout);
    mainLayout->addLayout(mealVouchersValueLayout);
    setLayout(mainLayout);
}


QString PersonInfoGroup::getName()
{
  return nameLineEdit->text();
}


double PersonInfoGroup::netSalary()
{
  return netSalaryLineEdit->text().toDouble();
}


double PersonInfoGroup::mealVoucherValue()
{
  return mealVouchersValueLineEdit->text().toDouble();
}


int PersonInfoGroup::avgNbMealVouchers()
{
  return mealVouchersLineEdit->text().toInt();
}
