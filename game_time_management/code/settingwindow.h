#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H

#include <QDialog>
#include <QSettings>
#include <QWidget>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>



class SettingWindow : public QDialog
{
    Q_OBJECT
public:
    SettingWindow(QWidget* parent);

private:
    QFormLayout* formLayout;
    QVBoxLayout* mainLaoyout;
    QHBoxLayout* buttonLayout;
    QLineEdit *pass1, *pass2;
    QSpinBox* Prix;
    QPushButton *cancelButton, *acceptButton;


    static constexpr int passLenght = 20;

    QSettings mySettings;

public slots:
    void handleAcceptButton();

};

#endif // SETTINGWINDOW_H
