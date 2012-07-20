#include <QtGui>

#include "mainwindow.h"
#include "outputgroup.h"
#include "personinfogroup.h"
#include "savingsinfogroup.h"

OutputGroup::OutputGroup(
    const QString &title,
    PersonInfoGroup *group1,
    PersonInfoGroup *group2,
    SavingsInfoGroup *savingsInfoGroup,
    QWidget *parent)
  : QGroupBox(title, parent), group1(group1), group2(group2), savingsInfoGroup(savingsInfoGroup)
{
    person1TotalSalaryLabel = new QLabel("Total salary person 1:");
    person2TotalSalaryLabel = new QLabel("Total salary person 2:");
    totalSalaryLabel = new QLabel("Total Salary:");

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(person1TotalSalaryLabel);
    mainLayout->addWidget(person2TotalSalaryLabel);
    mainLayout->addWidget(totalSalaryLabel);
    setLayout(mainLayout);
}


void OutputGroup::updateResult()
{
  qDebug() << "Name = " << group1->getName();
  qDebug() << "Net salary = " << group1->netSalary();
  qDebug() << "Average number of meal vouchers per month = " << group1->avgNbMealVouchers();
  qDebug() << "Meal voucher value = " << group1->mealVoucherValue();

  double totalSalary1 = group1->netSalary() + group1->avgNbMealVouchers()*group1->mealVoucherValue();
  double totalSalary2 = group2->netSalary() + group2->avgNbMealVouchers()*group2->mealVoucherValue();
  double totalSalary = totalSalary1 + totalSalary2;
  double frac1 = (totalSalary1/totalSalary)*100;
  double frac2 = (totalSalary2/totalSalary)*100;

  person1TotalSalaryLabel->setText("Total salary " + group1->getName() + ": "
      + QString::number(totalSalary1, 'f', 2)
      + " (" + QString::number(frac1, 'f', 2) + "% of total income)");
  person2TotalSalaryLabel->setText("Total salary " + group2->getName() + ": "
      + QString::number(totalSalary2, 'f', 2)
      + " (" + QString::number(frac2, 'f', 2) + "% of total income)");
  totalSalaryLabel->setText("Total salary: " + QString::number(totalSalary));
}
