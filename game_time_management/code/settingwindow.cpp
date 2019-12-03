#include "settingwindow.h"

SettingWindow::SettingWindow(QWidget* parent) : QDialog(parent)
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

    formLayout->addRow("&Nouveau mot de passe :", pass1);
    formLayout->addRow("&Confirmer mot de passe :", pass2);
    formLayout->addRow("&Prix / heure :", Prix);

    cancelButton = new QPushButton("Annuler");
    connect(cancelButton, &QPushButton::pressed, this, &SettingWindow::reject);
    acceptButton = new QPushButton("Accepter");

    buttonLayout->addWidget(cancelButton);
    buttonLayout->addWidget(acceptButton);
    buttonLayout->setAlignment(Qt::AlignRight);

    mainLaoyout->addLayout(formLayout);
    mainLaoyout->addLayout(buttonLayout);

    setWindowTitle("Reglages");
}
