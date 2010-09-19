/*
 * mainwindow.h
 *
 *  Created on: 15.09.2010
 *      Author: brunql
 *     Project: Lab6. Universal Asynchronous Reciver Transmitter
 *     Problem: Visualize UART (Bodo 5B, 1 stop) transmition day of birthday date
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void lineEdit_Changing();

private:
    Ui::MainWindow *ui;

    static const int codes5B[16];
};

#endif // MAINWINDOW_H
