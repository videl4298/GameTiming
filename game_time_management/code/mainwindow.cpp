#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent),
    mySettings(QApplication::organizationName(), QApplication::applicationName())
{
    setWindowTitle("Gestion Temps Salle de jeux");

    initialiseButton();

    makeLayoutReady();

    setLayout(MainLayout);

    // disable close button
    setWindowFlags(Qt::WindowTitleHint | Qt::WindowMinimizeButtonHint);

    // initialise password checker widgets
    askPass = new passwordChecker(this);
    connect(askPass, &QDialog::accepted, qApp, &QApplication::quit);
    connect(askPass, &passwordChecker::validPass, [=]{QMessageBox::information(this, "titre", "fonctionne");});
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
