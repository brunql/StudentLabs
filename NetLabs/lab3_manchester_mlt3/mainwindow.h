/*
 * mainwindow.h
 *
 *  Created on: 12.09.2010
 *      Author: brunql
 *     Project: Lab3. Manchester and mlt3 codes.
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
