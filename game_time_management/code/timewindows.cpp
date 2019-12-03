#include "timewindows.h"
#include "ui_timewindows.h"

timeWindows::timeWindows(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::timeWindows)
{
    ui->setupUi(this);
}

timeWindows::~timeWindows()
{
    delete ui;
}
