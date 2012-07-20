#ifndef OUTPUTGROUP_H
#define OUTPUTGROUP_H

#include <QGroupBox>

class QLabel;
class PersonInfoGroup;
class SavingsInfoGroup;

class OutputGroup : public QGroupBox
{
    Q_OBJECT

public:
    OutputGroup(
        const QString &title,
        PersonInfoGroup *group1,
        PersonInfoGroup *group2,
        SavingsInfoGroup *savingsInfoGroup,
        QWidget *parent = 0);

public slots:
    void updateResult();

private:
    PersonInfoGroup *group1;
    PersonInfoGroup *group2;
    SavingsInfoGroup *savingsInfoGroup;
    QLabel *person1TotalSalaryLabel;
    QLabel *person2TotalSalaryLabel;
    QLabel *totalSalaryLabel;
    QLabel *person1Contribution;
    QLabel *person2Contribution;
};

#endif
