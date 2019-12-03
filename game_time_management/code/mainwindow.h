#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QCloseEvent>
#include "passwordchecker.h"


class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    QHBoxLayout *MainLayout;
    /*called once*/
    void makeLayoutReady();
    void initialiseButton();
    /*called once*/
    QPushButton *StartButton, *ChangePasswordButton, *QuitButton;

    // prevent user from closing app without permission
    void closeEvent(QCloseEvent *event) override;


signals:

public slots:
    // ask password if user want to close the app
    void handleQuitButton();
};



#endif // MAINWINDOW_H
