#include "timerecever.h"
#include <QSettings>


TimeRecever::TimeRecever(QWidget* parent) : QDialog(parent)
{

    MakeLayout();

    MakeWidget();

    SetLayoutS();

    makeTimeBUtton();

    setGeometry(0, 0, 396, 255);
}

void TimeRecever::MakeLayout()
{
    mainLayout = new QVBoxLayout;
    groupLayout = new QHBoxLayout;
    timeLimitationLayout = new QVBoxLayout;
    buttonLayout = new QGridLayout;
    RadioLayout = new QHBoxLayout;
    isPaidLayout = new QVBoxLayout;
    validationButtonLayout = new QHBoxLayout;
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


    RadioLayout->addWidget(TimeR);
    RadioLayout->addWidget(MoneyR);
    RadioLayout->addWidget(MoneySpin);

    timeLimitationLayout->addLayout(RadioLayout);

    isPaid->setLayout(isPaidLayout);
    isPaidLayout->addWidget(UnPaidR);
    isPaidLayout->addWidget(PaidR);

    mainLayout->addLayout(validationButtonLayout);

    validationButtonLayout->setAlignment(Qt::AlignRight);
    validationButtonLayout->addWidget(cancelButton);
    validationButtonLayout->addWidget(acceptButton);

}


void TimeRecever::MakeWidget()
{
    timeLimitation = new QGroupBox;
    timeLimitation->setCheckable(true);
    timeLimitation->setChecked(false);
    timeLimitation->setTitle("Temps limiter");

    isPaid = new QGroupBox;

    timeButtonGroup = new QGroupBox;
    timeButtonGroup->setTitle("Temps");

    TimeR = new QRadioButton("Temps");
    TimeR->setChecked(true);
    MoneyR = new QRadioButton("Argents");

    MoneySpin = new QSpinBox;
    MoneySpin->setMinimum(0);
    MoneySpin->setMaximum(50000);
    MoneySpin->setEnabled(false);
    MoneySpin->setMinimumWidth(50);
    MoneySpin->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);

    connect(TimeR, &QRadioButton::toggled, this, &TimeRecever::HandleToogleTimeToMoney);

    PaidR = new QRadioButton("Payé");
    UnPaidR = new QRadioButton("non payé");
    UnPaidR->setChecked(true);

    cancelButton = new QPushButton("Annuler");
    connect(cancelButton, &QPushButton::pressed, this, &QDialog::reject);
    acceptButton = new QPushButton("Valider");
    connect(acceptButton, &QPushButton::pressed, this, &TimeRecever::generateResult);
}

void TimeRecever::makeTimeBUtton()
{
    timeGroupButton = new QButtonGroup(this);

    int add = 0;
    for(int i=0; i < buttonNumber; i++){
        add += 15;
        timeButton.push_back(new QPushButton(QString::number(add), this));
        timeButton.at(i)->setCheckable(true);
        timeButton.at(i)->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        timeGroupButton->addButton(timeButton.at(i));
    }
    add = 0;
    for(int i=0; i < 3; i++){
        for(int a = 0; a < 2; a++){
            buttonLayout->addWidget(timeButton.at(add), a, i);
            add++;
        }
    }
    HoursMin = new QPushButton("H:m", this);
    HoursMin->setCheckable(true);

    timeGroupButton->addButton(HoursMin);


    buttonLayout->addWidget(HoursMin, 2, 0);

    HoursSpin = new QSpinBox;
    HoursSpin->setMinimum(0);
    HoursSpin->setMaximum(24);
    HoursSpin->setEnabled(false);
    HoursSpin->setMinimumWidth(50);
    HoursSpin->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);


    MinSpin = new QSpinBox;
    MinSpin->setMinimum(0);
    MinSpin->setMaximum(59);
    MinSpin->setEnabled(false);
    MinSpin->setMinimumWidth(50);
    MinSpin->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);


    //connect(HoursMin, SIGNAL(toggled(bool)), this, SLOT(HandleHoursMinButton(bool)));
    connect(HoursMin, &QPushButton::toggled, this, &TimeRecever::HandleHoursMinButton);

    buttonLayout->addWidget(HoursSpin, 2, 1);
    buttonLayout->addWidget(MinSpin, 2, 2);
}


/*SLOTS*/
void TimeRecever::HandleHoursMinButton(bool isChecked)
{
    HoursSpin->setEnabled(isChecked);
    MinSpin->setEnabled(isChecked);
}

void TimeRecever::HandleToogleTimeToMoney(bool isTime)
{
    MoneySpin->setEnabled(!isTime);
    timeButtonGroup->setEnabled(isTime);
}

custommerInfoContainer *TimeRecever::generateResult()
{
    custommerInfoContainer *result = new custommerInfoContainer;

    if(!timeLimitation->isChecked()){
        result->isUnlimited = true;
        return result;
    }


    if(TimeR->isChecked()){
        result->isTime = true;
        result->isPaid = PaidR->isChecked();

        if(HoursMin->isChecked()){
            result->customerTotalTimeSecond = (HoursSpin->value() * 60 * 60) + (MinSpin->value() * 60);
            return result;
        }

        switch (timeGroupButton->checkedId()) {
            case 0:
            result->customerTotalTimeSecond = 15 * 60;
            break;
        case 1:
            result->customerTotalTimeSecond = 30 *60;
            break;
        case 2:
            result->customerTotalTimeSecond = 45 *60;
            break;
        case 3:
            result->customerTotalTimeSecond = 60 * 60;
            break;
        case 4:
            result->customerTotalTimeSecond = 75 * 60;
            break;
        case 5:
            result->customerTotalTimeSecond = 90 * 60;
            break;
        default:
            break;
        }
        return result;

    }else{
        result->isTime = false;
        result->isPaid = PaidR->isChecked();

        QSettings mySettings;
        int price = mySettings.value("prix", 1).toInt();

        result->customerTotalTimeSecond = (MoneySpin->value() * 60 * 60) / price;
        return result;
    }

}
