#include <QApplication>
#include "code/mainwindow.h"

int main(int argc, char* argv[]){
    QApplication app(argc, argv);

    MainWindow myMainWindow;
    myMainWindow.show();

    return app.exec();
}
