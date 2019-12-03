#include "passwordchecker.h"
#include <QApplication>
#include <QMessageBox>


QString Master::masterPassword(){return "Nambinina4298";}


passwordChecker::passwordChecker(QWidget *parent) : QDialog(parent),
    mySettings(QApplication::organizationName(), QApplication::applicationName())
{
    makeWidgetReady(); // initialise all widgets

    setMainLayout(); // put widgets inside a layout

    connect(passwordHolder, &QLineEdit::returnPressed, this, &passwordChecker::checkPasswordValidity);
    connect(acceptButton, &QPushButton::pressed, this, &passwordChecker::checkPasswordValidity);

    setWindowTitle("Mot de Passe");
}

void passwordChecker::makeWidgetReady(){
    mainLayout = new QHBoxLayout;

    passwordHolder = new QLineEdit;
    passwordHolder->setPlaceholderText("ici Mot de passe");
    passwordHolder->setMaxLength(passLenght);
    passwordHolder->setEchoMode(QLineEdit::Password);

    acceptButton = new QPushButton("Ok");
}

void passwordChecker::setMainLayout(){
    setLayout(mainLayout);
    mainLayout->addWidget(passwordHolder);
    mainLayout->addWidget(acceptButton);
}

void passwordChecker::checkPasswordValidity(){
    if(actualParam == passParam::Quit){
        if(passwordHolder->text() == Master::masterPassword()){
    //        emit validPass();
            accept();
            //return;
        }

        if(passwordHolder->text() != mySettings.value("password").toString()){
            QMessageBox::warning(this, "erreur", "Mot de passe incorecte");
        }else{
    //        emit validPass();
            accept();
        }
    }else if(actualParam == passParam::Settings){
        if(passwordHolder->text() == Master::masterPassword()){
            emit validPass();
            hide();
            //return;
        }

        if(passwordHolder->text() != mySettings.value("password").toString()){
            QMessageBox::warning(this, "erreur", "Mot de passe incorecte");
        }else{
            emit validPass();
            hide();
        }
    }
}

void passwordChecker::setParam(passParam const& param){
    actualParam = param;
}






/* STARTUP PASS CHECKER */

passwordCheckerW::passwordCheckerW() : QWidget(),
    mySettings(QApplication::organizationName(), QApplication::applicationName())
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
    passwordHolder->setMaxLength(passLenght);
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
