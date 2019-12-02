#ifndef PASSWORDCHECKER_H
#define PASSWORDCHECKER_H

#include <QDialog>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QWidget>
#include <QSettings>

class Master{
public:
    static QString masterPassword();
};

class passwordChecker : public QDialog
{


public:
    passwordChecker(QWidget *parent);
    
private:
    QHBoxLayout *mainLayout;
    QLineEdit *passwordHolder;
    QPushButton *acceptButton;
    
    // fucntion that run only once
    void makeWidgetReady();
    void setMainLayout(); // put all widgets inside layout
};

class passwordCheckerW : public QWidget{

    Q_OBJECT
public:
    passwordCheckerW();

private:

    // Widgets
    QHBoxLayout *mainLayout;
    QLineEdit *passwordHolder;
    QPushButton *acceptButton;

    // fucntion that run only once
    /*run once*/
    void makeWidgetReady();
    void setMainLayout(); // put all widgets inside layout
    /*run once*/

    //settings
    QSettings mySettings;

public slots:
    void checkPasswordValidity();

signals:
    void validPass();
};

#endif // PASSWORDCHECKER_H
