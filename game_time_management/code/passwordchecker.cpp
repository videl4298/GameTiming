#include "passwordchecker.h"

passwordChecker::passwordChecker(QWidget *parent) : QDialog(parent)
{
    makeWidgetReady(); // initialise all widgets

    setMainLayout(); // put widgets inside a layout
}

void passwordChecker::makeWidgetReady(){
    mainLayout = new QHBoxLayout;

    passwordHolder = new QLineEdit;
    passwordHolder->setPlaceholderText("ici Mot de passe");
    passwordHolder->setMaxLength(20);
    passwordHolder->setEchoMode(QLineEdit::Password);

    acceptButton = new QPushButton("ouvrir");
}

void passwordChecker::setMainLayout(){
    setLayout(mainLayout);
    mainLayout->addWidget(passwordHolder);
    mainLayout->addWidget(acceptButton);
}

passwordCheckerW::passwordCheckerW() : QWidget()
{
    makeWidgetReady(); // initialise all widgets

    setMainLayout(); // put widgets inside a layout
}

void passwordCheckerW::makeWidgetReady(){
    mainLayout = new QHBoxLayout;

    passwordHolder = new QLineEdit;
    passwordHolder->setPlaceholderText("ici Mot de passe");
    passwordHolder->setMaxLength(20);
    passwordHolder->setEchoMode(QLineEdit::Password);

    acceptButton = new QPushButton("ouvrir");
}

void passwordCheckerW::setMainLayout(){
    setLayout(mainLayout);
    mainLayout->addWidget(passwordHolder);
    mainLayout->addWidget(acceptButton);
}
