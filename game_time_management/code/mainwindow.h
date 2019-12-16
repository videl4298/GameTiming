#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QCloseEvent>
#include <QSettings>
#include "passwordchecker.h"
#include "code/settingwindow.h"
#include "code/screenblocker.h"
#include "code/timewindows.h"
#include "code/timerecever.h"
#include "custommerinfocontainer.h"
#include <QTimer>
#include <QTime>


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

    ScreenBlocker* myScreenBlocker;
    timeWindows* timePrinter;

    // prevent user from closing app without permission
    void closeEvent(QCloseEvent *event) override;

    QTimer *chrono;
    QTime *times;

    int actualValue = 0;


    // manage settings
    QSettings mySettings;

    passwordChecker* askPass;

    TimeRecever *takeCommand;

    QString GenetrateStat(custommerInfoContainer const& info);


    const int pricePerHour;

signals:

public slots:
    // ask password if user want to close the app
    void handleQuitButton();


    void handleSettingsButton();

    void showSettingWindow();

    void resultHandler(custommerInfoContainer info);

    void handleUnlimitedTime();

    void handleLimitedTime();
};



#endif // MAINWINDOW_H
