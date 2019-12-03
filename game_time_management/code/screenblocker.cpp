#include "screenblocker.h"

ScreenBlocker::ScreenBlocker(QWidget* parent) : QDialog(parent)
{
    quitButton = new QPushButton("Quitter", this);
    connect(quitButton, &QPushButton::pressed, this, &ScreenBlocker::close);
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    //setWindowFlags(Qt::FramelessWindowHint);
}
