#include "timewindows.h"
#include "ui_timewindows.h"


timeWindows::timeWindows(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::timeWindows)
{
    ui->setupUi(this);
    ui->lcdNumber->setDigitCount(8);
//    setWindowFlags(Qt::WindowTitleHint | Qt::WindowMinimizeButtonHint);
    askPass = new passwordChecker(this);
    connectAll();

    ui->controlGroupBox->setEnabled(false);
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

void timeWindows::closeEvent(QCloseEvent *event)
{
    event->ignore();
}


void timeWindows::handleQuitButton()
{
    askPass->setParam(passParam::Quit);
    askPass->exec();
}

void timeWindows::handleAcceptedQuit()
{
    hide();
    accept();
}

void timeWindows::handleControlButton()
{
    askPass->setParam(passParam::Other);
    askPass->exec();
}

void timeWindows::handleControlResult()
{

    ui->controlGroupBox->setDisabled(ui->controlGroupBox->isEnabled());

}

void timeWindows::connectAll()
{
    connect(ui->closeButton, &QPushButton::pressed, this, &timeWindows::handleQuitButton);
    connect(askPass, &passwordChecker::accepted, this, &timeWindows::handleAcceptedQuit);
    connect(ui->controlButton, &QPushButton::pressed, this, &timeWindows::handleControlButton);
    connect(askPass, &passwordChecker::validActivation, this, &timeWindows::handleControlResult);
}
