#include "settingwindow.h"
#include <QApplication>
#include <QMessageBox>

SettingWindow::SettingWindow(QWidget* parent) : QDialog(parent),
    mySettings(QApplication::organizationName(), QApplication::applicationName())
{
    buttonLayout = new QHBoxLayout;
    mainLaoyout = new QVBoxLayout;

    formLayout = new QFormLayout;
    setLayout(mainLaoyout);

    pass1 = new QLineEdit;
    pass1->setMaxLength(passLenght);
    pass2 = new QLineEdit;
    pass2->setMaxLength(passLenght);

    Prix = new QSpinBox;
    Prix->setMinimum(1);
    Prix->setMaximum(50000);
    Prix->setValue(mySettings.value("prix", 1).toInt());

    formLayout->addRow("&Nouveau mot de passe :", pass1);
    formLayout->addRow("&Confirmer mot de passe :", pass2);
    formLayout->addRow("&Prix / heure :", Prix);

    cancelButton = new QPushButton("Annuler");
    connect(cancelButton, &QPushButton::pressed, this, &SettingWindow::reject);
    acceptButton = new QPushButton("Accepter");
    connect(acceptButton, &QPushButton::pressed, this, &SettingWindow::handleAcceptButton);

    buttonLayout->addWidget(cancelButton);
    buttonLayout->addWidget(acceptButton);
    buttonLayout->setAlignment(Qt::AlignRight);

    mainLaoyout->addLayout(formLayout);
    mainLaoyout->addLayout(buttonLayout);

    setWindowTitle("Reglages");
}

void SettingWindow::handleAcceptButton()
{
    if(pass1->text() == pass2->text()){
        mySettings.setValue("password", pass1->text());
        mySettings.setValue("prix", Prix->value());
        accept();
    }else{
        QMessageBox::warning(this, "Erreur", "les deux mot de passe ne sont pas identiques");
    }
}
