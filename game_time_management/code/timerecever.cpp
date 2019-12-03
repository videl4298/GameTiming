#include "timerecever.h"


TimeRecever::TimeRecever(QWidget* parent) : QDialog(parent)
{

    MakeLayout();

    MakeWidget();

    SetLayoutS();

    makeTimeBUtton();
}

void TimeRecever::MakeLayout()
{
    mainLayout = new QVBoxLayout;
    groupLayout = new QHBoxLayout;
    timeLimitationLayout = new QVBoxLayout;
    buttonLayout = new QGridLayout;
}


void TimeRecever::SetLayoutS()
{
    setLayout(mainLayout);
    mainLayout->addLayout(groupLayout);

    groupLayout->addWidget(timeLimitation);
    groupLayout->addWidget(isPaid);

    timeLimitationLayout->addWidget(timeButtonGroup);
    timeLimitation->setLayout(timeLimitationLayout);

    timeButtonGroup->setLayout(buttonLayout);
}


void TimeRecever::MakeWidget()
{
    timeLimitation = new QGroupBox;
    timeLimitation->setCheckable(true);
    timeLimitation->setChecked(false);

    isPaid = new QGroupBox;

    timeButtonGroup = new QGroupBox;
}

void TimeRecever::makeTimeBUtton()
{
    timeGroupButton = new QButtonGroup(this);
    int add = 0;
    for(int i=0; i < buttonNumber; i++){
        add += 15;
        timeButton.push_back(new QPushButton(QString::number(add), this));
    }
    add = 0;
    for(int i=0; i < 3; i++){
        for(int a = 0; a < 2; a++){
            buttonLayout->addWidget(timeButton.at(add), a, i);
            add++;
        }
    }
}
