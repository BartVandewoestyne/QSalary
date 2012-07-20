#ifndef PERSONINFOGROUP_H
#define PERSONINFOGROUP_H

#include <QGroupBox>

class QLabel;
class QLineEdit;

class PersonInfoGroup : public QGroupBox
{
    Q_OBJECT

public:
    PersonInfoGroup(const QString &title, QWidget *parent = 0);
    QString getName();
    double netSalary();
    double mealVoucherValue();
    int avgNbMealVouchers();

private:
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *netSalaryLabel;
    QLineEdit *netSalaryLineEdit;
    QLabel *mealVouchersLabel;
    QLineEdit *mealVouchersLineEdit;
    QLabel *mealVouchersValueLabel;
    QLineEdit *mealVouchersValueLineEdit;
};

#endif
