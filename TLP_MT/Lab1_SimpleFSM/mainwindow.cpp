/*
 * mainwindow.cpp
 *
 *  Created on: 13.09.2010
 *      Author: brunql
 *     Project: Lab1. Simple FSM
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QDebug"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->lineEditInput, SIGNAL(textChanged(QString)), this, SLOT(lineEditing()));

    fsm_table = new FSM_TableModel(this);
    ui->tableView->setModel(fsm_table);
    lineEditing();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}


void MainWindow::resizeEvent(QResizeEvent *)
{
    int summ = ui->tableView->columnWidth(0) + ui->tableView->columnWidth(1);
    ui->tableView->setColumnWidth(0, summ/2);
    ui->tableView->setColumnWidth(1, summ/2);
}


void MainWindow::lineEditing()
{
    QString result = fsm_table->FSM(ui->lineEditInput->text());
    if(result != "error"){
        // Set result
        ui->lineEditOutput->setText( result );
        // Makes white background of lineEditInput:
        QPalette pal = ui->lineEditInput->palette();
        pal.setBrush(ui->lineEditInput->backgroundRole(), QBrush(Qt::white));
        ui->lineEditInput->setPalette(pal);
    }else{
        ui->lineEditOutput->setText( "" );
        // Error. Makes red background of lineEditInput:
        QPalette pal = ui->lineEditInput->palette();
        pal.setBrush(ui->lineEditInput->backgroundRole(), QBrush(Qt::red));
        ui->lineEditInput->setPalette(pal);
    }

    ui->tableView->selectRow(fsm_table->lastStateFSM);

}




















