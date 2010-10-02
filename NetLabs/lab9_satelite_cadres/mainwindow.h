/*
 * mainwindow.h
 *
 *  Created on: 2.10.2010
 *      Author: brunql
 *     Project: Lab 9. Satelite cadres show must go on
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

    static const int bodoCodes[32];
    static const char bodoChars[29];
    static const char bodoDigits[29];
};

#endif // MAINWINDOW_H
