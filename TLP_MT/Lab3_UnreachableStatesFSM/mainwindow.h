/*
 * mainwindow.h
 *
 *  Created on: 13.09.2010
 *      Author: brunql
 *     Project: FSM
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fsm_tablemodel.h"

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
    void resizeEvent(QResizeEvent *);

private slots:
    void lineInputEditing();
    void lineInputDigitsEditing();
    void btnRemoveUnreachableStatesClicked();

private:
    Ui::MainWindow *ui;
    FSM_TableModel *fsm_table;
};

#endif // MAINWINDOW_H
