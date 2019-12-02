#include <QApplication>
#include "code/mainwindow.h"
#include "code/passwordchecker.h"
#include <QObject>

void setApplicationInfo();

int main(int argc, char* argv[]){
    QApplication app(argc, argv);

    setApplicationInfo();

//    MainWindow myMainWindow;
//    myMainWindow.show();

    return app.exec();
}

void setApplicationInfo(){
    QApplication::setOrganizationName("VIDEL CORPORATION");
    QApplication::setOrganizationDomain("videl.com");
    QApplication::setApplicationName("Game time manager");
}
