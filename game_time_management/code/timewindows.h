#ifndef TIMEWINDOWS_H
#define TIMEWINDOWS_H

#include <QDialog>
#include <QString>

namespace Ui {
class timeWindows;
}

class timeWindows : public QDialog
{
    Q_OBJECT

public:
    explicit timeWindows(QWidget *parent = nullptr);
    ~timeWindows();

public:
    Ui::timeWindows *ui;
    void setTime(QString time);
    void showStats(QString const& stat);
    void setPriceLabel(int price);

};

#endif // TIMEWINDOWS_H
