#include <QApplication>
#include "code/mainwindow.h"
#include "code/passwordchecker.h"
#include <QObject>
#include "code/timerecever.h"

void setApplicationInfo();


int main(int argc, char* argv[]){
    QApplication app(argc, argv);
/*
    setApplicationInfo();

    passwordCheckerW* passCheck = new passwordCheckerW;
    passCheck->show();

    MainWindow fenetre;

    // if password is correct then show the main window
    QObject::connect(passCheck, &passwordCheckerW::validPass, passCheck, &passwordCheckerW::deleteLater);
    QObject::connect(passCheck, &passwordCheckerW::validPass, &fenetre, &MainWindow::show);

*/
    TimeRecever temps(nullptr);
    temps.show();

    return app.exec();
}

void setApplicationInfo(){
    QApplication::setOrganizationName("VIDEL CORPORATION");
    QApplication::setOrganizationDomain("videl.com");
    QApplication::setApplicationName("Game time manager");
}

