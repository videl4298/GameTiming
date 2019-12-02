#include "passwordchecker.h"
#include <QApplication>
#include <QMessageBox>


QString Master::masterPassword(){return "Nambinina4298";}


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

passwordCheckerW::passwordCheckerW() : QWidget(),
    mySettings(QApplication::applicationName(), QApplication::organizationName())
{
    makeWidgetReady(); // initialise all widgets

    setMainLayout(); // put widgets inside a layout

    connect(passwordHolder, &QLineEdit::returnPressed, this, &passwordCheckerW::checkPasswordValidity);
    connect(acceptButton, &QPushButton::pressed, this, &passwordCheckerW::checkPasswordValidity);
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

void passwordCheckerW::checkPasswordValidity(){
    if(passwordHolder->text() == Master::masterPassword()){
        emit validPass();
        return;
    }

    if(passwordHolder->text() != mySettings.value("password").toString()){
        QMessageBox::warning(this, "erreur", "Mot de passe incorecte");
    }else{
        emit validPass();
    }
}
