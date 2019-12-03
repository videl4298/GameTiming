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

constexpr int buttonNumber = 6;

class TimeRecever : public QDialog
{
public:
    TimeRecever(QWidget* parent);

private:
    QVBoxLayout *mainLayout, *timeLimitationLayout;
    QHBoxLayout *groupLayout;
    QGridLayout* buttonLayout;
    QGroupBox *timeLimitation, *isPaid, *timeButtonGroup;
    QVector<QPushButton *> timeButton;

    QButtonGroup *timeGroupButton;

    /* run once */
    void MakeLayout();
    void MakeWidget();
    void SetLayoutS();
    void makeTimeButtonReady();
    void makeTimeBUtton();
};

#endif // TIMERECEVER_H
