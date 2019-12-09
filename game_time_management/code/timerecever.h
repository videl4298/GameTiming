#ifndef TIMERECEVER_H
#define TIMERECEVER_H

#include <QDialog>
#include <QWidget>
#include <QGroupBox>
#include <QPushButton>
#include <QSpinBox>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QVector>
#include <QButtonGroup>
#include <QRadioButton>
#include "custommerinfocontainer.h"

constexpr int buttonNumber = 6;

class TimeRecever : public QDialog
{
    Q_OBJECT
public:
    TimeRecever(QWidget* parent);

private:
    QVBoxLayout *mainLayout, *timeLimitationLayout, *isPaidLayout;
    QHBoxLayout *groupLayout, *RadioLayout, *validationButtonLayout;
    QGridLayout* buttonLayout;
    QGroupBox *timeLimitation, *isPaid, *timeButtonGroup;
    QVector<QPushButton *> timeButton;
    QPushButton* HoursMin;
    QSpinBox *HoursSpin, *MinSpin, *MoneySpin;
    QRadioButton *TimeR, *MoneyR, *PaidR, *UnPaidR;
    QPushButton *cancelButton, *acceptButton;

    QButtonGroup *timeGroupButton;

    /* run once */
    void MakeLayout();
    void MakeWidget();
    void SetLayoutS();
    void makeTimeButtonReady();
    void makeTimeBUtton();

public slots:
    void HandleHoursMinButton(bool isChecked);
    void HandleToogleTimeToMoney(bool isTime);
    custommerInfoContainer* generateResult();
};

#endif // TIMERECEVER_H
