#include <QtGui>

#include "mainwindow.h"
#include "outputgroup.h"
#include "personinfogroup.h"

MainWindow::MainWindow()
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    group1 = new PersonInfoGroup(tr("Person 1"), this);
    group2 = new PersonInfoGroup(tr("Person 2"), this);

    QHBoxLayout *personInfoLayout = new QHBoxLayout;
    personInfoLayout->addWidget(group1);
    personInfoLayout->addWidget(group2);

    SavingsInfoGroup *savingsInfoGroup = new SavingsInfoGroup(tr("Requested savings"), this);

    OutputGroup *outputGroup = new OutputGroup(tr("Results"), group1, group2, savingsInfoGroup, this);

    QPushButton *updateButton = new QPushButton(tr("Update"), this);
    updateButton->setToolTip(tr("Update the info in the Results group."));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(personInfoLayout);
    mainLayout->addWidget(savingsInfoGroup);
    mainLayout->addWidget(outputGroup);
    mainLayout->addWidget(updateButton);
    widget->setLayout(mainLayout);

    connect(updateButton, SIGNAL(clicked()),
            outputGroup, SLOT(updateResult()));

    setWindowTitle(tr("QSalary"));
    //setMinimumSize(160, 160);
    //resize(480, 320);
}


PersonInfoGroup* MainWindow::getPersonInfoGroup1()
{
  return group1;
}

void MainWindow::myTest()
{
  qDebug() << "MainWindow::test()";
}
