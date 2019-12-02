#include "mainwindow.h"
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Gestion Temps Salle de jeux");

    initialiseButton();

    makeLayoutReady();

    setLayout(MainLayout);
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

    QuitButton = new QPushButton();
    QuitButton->setIcon(QIcon(":/all/quit.png"));
    QuitButton->setIconSize(QSize(125,125));
    QuitButton->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);


}
