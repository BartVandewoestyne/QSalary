#ifndef SAVINGSINFOGROUP_H
#define SAVINGSINFOGROUP_H

#include <QGroupBox>

class QLabel;
class QLineEdit;

class SavingsInfoGroup : public QGroupBox
{
    Q_OBJECT

public:
    SavingsInfoGroup(const QString &title, QWidget *parent = 0);

private:
    QLabel *requestedSavingsLabel;
    QLineEdit *requestedSavingsLineEdit;
};

#endif
