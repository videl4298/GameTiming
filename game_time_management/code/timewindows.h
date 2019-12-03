#ifndef TIMEWINDOWS_H
#define TIMEWINDOWS_H

#include <QDialog>

namespace Ui {
class timeWindows;
}

class timeWindows : public QDialog
{
    Q_OBJECT

public:
    explicit timeWindows(QWidget *parent = nullptr);
    ~timeWindows();

private:
    Ui::timeWindows *ui;
};

#endif // TIMEWINDOWS_H
