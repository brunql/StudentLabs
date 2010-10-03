#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore>
#include <QMainWindow>

#include <abstractserial.h>
#include <iostream>


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private slots:
    void timerTimeout();
    void buttonStartStop();

private:
    Ui::MainWindow *ui;
    QTimer *timer;

    AbstractSerial *device;


};

#endif // MAINWINDOW_H
