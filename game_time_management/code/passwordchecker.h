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

enum class passParam{
    Quit,
    Settings,
    Other
};

// password lenght
static constexpr int passLenght = 20;

class passwordChecker : public QDialog
{

    Q_OBJECT
public:
    passwordChecker(QWidget *parent);

    void setParam(passParam const& param);
    
private:
    QHBoxLayout *mainLayout;
    QLineEdit *passwordHolder;
    QPushButton *acceptButton;
    
    // fucntion that run only once
    void makeWidgetReady();
    void setMainLayout(); // put all widgets inside layout



    //settings
    QSettings mySettings;

    passParam actualParam = passParam::Other;

public slots:
    void checkPasswordValidity();

signals:
    void validPass();
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
