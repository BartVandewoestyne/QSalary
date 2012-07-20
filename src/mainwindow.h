#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "personinfogroup.h"
#include "savingsinfogroup.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    PersonInfoGroup* getPersonInfoGroup1();
    void myTest();

private:
    PersonInfoGroup *group1;
    PersonInfoGroup *group2;
    SavingsInfoGroup *savingsInfoGroup;
};

#endif
