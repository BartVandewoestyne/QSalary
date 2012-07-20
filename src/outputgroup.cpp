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
    person1Contribution = new QLabel("Contribution person 1:");
    person2Contribution = new QLabel("Contribution person 2:");

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(person1TotalSalaryLabel);
    mainLayout->addWidget(person2TotalSalaryLabel);
    mainLayout->addWidget(totalSalaryLabel);
    mainLayout->addWidget(person1Contribution);
    mainLayout->addWidget(person2Contribution);
    setLayout(mainLayout);
}


void OutputGroup::updateResult()
{
  qDebug() << "Name = " << group1->getName();
  qDebug() << "Net salary = " << group1->netSalary();
  qDebug() << "Average number of meal vouchers per month = " << group1->avgNbMealVouchers();
  qDebug() << "Meal voucher value = " << group1->mealVoucherValue();

  double mealVouchers1Amount = group1->avgNbMealVouchers()*group1->mealVoucherValue();
  double mealVouchers2Amount = group2->avgNbMealVouchers()*group2->mealVoucherValue();
  double totalSalary1 = group1->netSalary() + mealVouchers1Amount;
  double totalSalary2 = group2->netSalary() + mealVouchers2Amount;
  double totalSalary = totalSalary1 + totalSalary2;
  double frac1 = totalSalary1/totalSalary;
  double frac2 = totalSalary2/totalSalary;
  double contribution1 = frac1*savingsInfoGroup->requestedSavings();
  double contribution2 = frac2*savingsInfoGroup->requestedSavings();
  double contribution1WithoutVouchers = contribution1 - mealVouchers1Amount;
  double contribution2WithoutVouchers = contribution2 - mealVouchers2Amount;

  //QLocale defaultLocale;
  //qDebug() << "totalSalary1: " << defaultLocale.toCurrencyString(totalSalary1);

  person1TotalSalaryLabel->setText("Total salary " + group1->getName() + ": "
      + QString::number(totalSalary1, 'f', 2)
      + " (" + QString::number(frac1*100, 'f', 2) + "% of total income)");
  person2TotalSalaryLabel->setText("Total salary " + group2->getName() + ": "
      + QString::number(totalSalary2, 'f', 2)
      + " (" + QString::number(frac2*100, 'f', 2) + "% of total income)");
  totalSalaryLabel->setText("Total salary: " + QString::number(totalSalary));

  person1Contribution->setText("Contribution " + group1->getName() + ": "
      + QString::number(contribution1, 'f', 2)
      + " (" + QString::number(contribution1WithoutVouchers, 'f', 2) + " without meal vouchers)");
  person2Contribution->setText("Contribution " + group2->getName() + ": "
      + QString::number(contribution2, 'f', 2)
      + " (" + QString::number(contribution2WithoutVouchers, 'f', 2) + " without meal vouchers)");
}
