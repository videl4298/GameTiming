#ifndef TIMEWINDOWS_H
#define TIMEWINDOWS_H

#include <QDialog>
#include <QString>
#include <QCloseEvent>
#include "passwordchecker.h"

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

    void closeEvent(QCloseEvent *event) override;

    void connectAll();

private:
    passwordChecker* askPass;

public slots:
    void handleQuitButton();
    void handleAcceptedQuit();
    void handleControlButton();
    void handleControlResult();

};

#endif // TIMEWINDOWS_H
