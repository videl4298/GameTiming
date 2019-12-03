#ifndef SCREENBLOCKER_H
#define SCREENBLOCKER_H

#include <QDialog>
#include <QWidget>
#include <QPushButton>

class ScreenBlocker : public QDialog
{
    Q_OBJECT
public:
    ScreenBlocker(QWidget* parent);

private:
    QPushButton* quitButton;
};

#endif // SCREENBLOCKER_H
