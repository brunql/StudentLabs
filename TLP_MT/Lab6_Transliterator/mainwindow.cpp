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
}


void MainWindow::lineEditing()
{
    QString result = "";
    QString input = ui->lineEditInput->text();
    for(int i=0; i<input.length(); i++){
        if(input[i].isLetterOrNumber()){
            if(input[i].isLetter()){
                result += "1" + input[i];
            }else if(input[i].isDigit()){
                result += "2" + input[i];
            }else{
                result = "error";
            }
        }else{
            switch(input[i].toAscii()){
            case '+': result += "3" + input[i]; break;
            case '-': result += "3" + input[i]; break;
            case '*': result += "3" + input[i]; break;
            case '/': result += "3" + input[i]; break;
            case '.': result += "4"; break;
            case ',': result += "5"; break;
            case '(': result += "6"; break;
            case ')': result += "7"; break;
            default : result = "error";
            }
        }
    }


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
}





















