#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "code/timewindows.h"
#include <QMessageBox>
#include "import/pricedurationcalc_v.h"


MainWindow::MainWindow(QWidget *parent) : QWidget(parent),
    mySettings(QApplication::organizationName(), QApplication::applicationName()),
    pricePerHour(mySettings.value("prix", 1).toInt())
{
    setWindowTitle("Gestion Temps Salle de jeux");

    initialiseButton();

    makeLayoutReady();

    setLayout(MainLayout);

    takeCommand = new TimeRecever(this);
    connect(StartButton, &QPushButton::pressed, takeCommand, &QDialog::exec);
    connect(takeCommand, &TimeRecever::resultReady, this, &MainWindow::resultHandler);

    // disable close button
    setWindowFlags(Qt::WindowTitleHint | Qt::WindowMinimizeButtonHint);

    // initialise password checker widgets
    askPass = new passwordChecker(this);
    connect(askPass, &QDialog::accepted, qApp, &QApplication::quit);
    connect(askPass, &passwordChecker::validPass, this, &MainWindow::showSettingWindow);

    myScreenBlocker = new ScreenBlocker(this);
    timePrinter = new timeWindows(this);

    chrono = new QTimer(this);

    times = new QTime(0, 0, 0);


    connect(timePrinter, &timeWindows::accepted, this, &MainWindow::show);
//    connect(StartButton, &QPushButton::pressed, timePrinter, &QDialog::exec);
}

void MainWindow::makeLayoutReady(){
    MainLayout = new QHBoxLayout;
    MainLayout->addWidget(StartButton);
    MainLayout->addWidget(ChangePasswordButton);
    MainLayout->addWidget(QuitButton);
}

void MainWindow::initialiseButton(){
    StartButton = new QPushButton();
    StartButton->setIcon(QIcon(":/all/start_button.png"));
    StartButton->setIconSize(QSize(125,125));
    StartButton->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);


    ChangePasswordButton = new QPushButton("MDP");
    QFont myFont = ChangePasswordButton->font();
    myFont.setWeight(75);
    myFont.setPointSize(25);
    ChangePasswordButton->setFont(myFont);
    ChangePasswordButton->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    connect(ChangePasswordButton, &QPushButton::pressed, this, &MainWindow::handleSettingsButton);

    QuitButton = new QPushButton();
    QuitButton->setIcon(QIcon(":/all/quit.png"));
    QuitButton->setIconSize(QSize(125,125));
    QuitButton->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    connect(QuitButton, &QPushButton::pressed, this, &MainWindow::handleQuitButton);


}

void MainWindow::closeEvent(QCloseEvent *event)
{
    event->ignore();
}




void MainWindow::handleQuitButton()
{
    askPass->setParam(passParam::Quit);
    askPass->exec();
}

void MainWindow::handleSettingsButton(){
    askPass->setParam(passParam::Settings);
    askPass->exec();
}

void MainWindow::showSettingWindow(){
    askPass->close();
    SettingWindow mySettingWindow(this);
    mySettingWindow.exec();

}

void MainWindow::resultHandler(custommerInfoContainer info)
{
    hide();
    takeCommand->hide();
    if(info.isUnlimited){
        connect(chrono, &QTimer::timeout, this, &MainWindow::handleUnlimitedTime);
        //connect(chrono, SIGNAL(timeout()), this, SLOT(handleUnlimitedTime()));
        timePrinter->setTime(times->toString(Qt::TextDate));
        actualValue = 0;
        chrono->start(1000);


        timePrinter->showStats(GenetrateStat(info));
        timePrinter->setPriceLabel(0);

        timePrinter->exec();
//        timePrinter->setTime(times->toString(Qt::TextDate));

    }else{
        connect(chrono, &QTimer::timeout, this, &MainWindow::handleLimitedTime);
        actualValue = info.customerTotalTimeSecond + 1;
//        timePrinter->setTime(times->toString(Qt::TextDate));
        chrono->start(1000);
        timePrinter->showStats(GenetrateStat(info));
        timePrinter->setPriceLabel(actualValue);


        timePrinter->exec();
    }
}

void MainWindow::handleUnlimitedTime()
{
    actualValue++;
    QTime t = times->addSecs(actualValue);
    timePrinter->setTime(t.toString(Qt::TextDate));
    if((actualValue % 300) == 0){

        timePrinter->setPriceLabel(priceDurationCalc_V::calcPayementFromSec(actualValue, pricePerHour));
    }

}

void MainWindow::handleLimitedTime()
{

    actualValue--;
    QTime t = times->addSecs(actualValue);
    timePrinter->setTime(t.toString(Qt::TextDate));
    if((actualValue % 30) == 0){

        timePrinter->setPriceLabel(priceDurationCalc_V::calcPayementFromSec(actualValue, pricePerHour));
    }
}


QString MainWindow::GenetrateStat(custommerInfoContainer const& info)
{
    QString stat;
    stat = "\tCOMPTEUR CLIENT";
    if(info.isUnlimited){
        stat += "\nChrono non limiter";
        return stat;
    }else{
        stat += "\nChrono limiter";
        stat += "\n" + times->addSecs(info.customerTotalTimeSecond).toString();
        if(info.isPaid){
            stat += "\nPayée : ";
        }else{
            stat += "\nNon Payée : ";
        }

//        QSettings mySettings;
//        int pricePerHour = mySettings.value("prix", 1).toInt();
        int payement;
        payement = priceDurationCalc_V::calcPayementFromSec(info.customerTotalTimeSecond, pricePerHour);

        stat += QString::number(payement) + "Fmg";

        //result.customerTotalTimeSecond = (MoneySpin->value() * 60 * 60) / price;
        return stat;
    }

}
