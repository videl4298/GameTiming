#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

signals:

public slots:

private:
    QHBoxLayout *MainLayout;
    void makeLayoutReady();

    void initialiseButton();
    QPushButton *StartButton, *ChangePasswordButton, *QuitButton;
};

#endif // MAINWINDOW_H
