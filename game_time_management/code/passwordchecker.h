#ifndef PASSWORDCHECKER_H
#define PASSWORDCHECKER_H

#include <QDialog>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QWidget>


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
public:
    passwordCheckerW();

private:
    QHBoxLayout *mainLayout;
    QLineEdit *passwordHolder;
    QPushButton *acceptButton;

    // fucntion that run only once
    void makeWidgetReady();
    void setMainLayout(); // put all widgets inside layout
};

#endif // PASSWORDCHECKER_H
