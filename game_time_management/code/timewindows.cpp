#include "timewindows.h"
#include "ui_timewindows.h"

timeWindows::timeWindows(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::timeWindows)
{
    ui->setupUi(this);
    ui->lcdNumber->setDigitCount(8);

}

timeWindows::~timeWindows()
{
    delete ui;
}

void timeWindows::setTime(QString time)
{
    ui->lcdNumber->display(time);
}

void timeWindows::showStats(QString const& stat)
{
    ui->textEdit->clear();
    ui->textEdit->setText(stat);

}

void timeWindows::setPriceLabel(int price)
{
    ui->priceLabel->setText(QString::number(price) + "Fmg");
}
