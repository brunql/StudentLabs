/*
 * mainwindow.cpp
 *
 *  Created on: 19.09.2010
 *      Author: brunql
 *     Project: Lab6. Universal Asynchronous Reciver Transmitter
 *     Problem: Visualize UART (Bodo 5B, 1 stop) transmition day of birthday date
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtGui"

#define SCALE_X   60
#define SCALE_Y   60

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(new QGraphicsScene(this));

    connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(lineEdit_Changing()));

    this->lineEdit_Changing();
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


void MainWindow::lineEdit_Changing()
{
    QString lineInput = ui->lineEdit->text();

    //
    // Get codes
    //
    QList<int> codes4BList;
    for(int c=0; c<lineInput.length(); c++){
        if(lineInput[c].isDigit()){ // TODO: add ABCDEF
            codes4BList.append( lineInput[c].digitValue() );

        }else{
            QPalette pal = ui->lineEdit->palette();
            pal.setBrush(ui->lineEdit->backgroundRole(), QBrush(Qt::red));
            ui->lineEdit->setPalette(pal);
            return;
        }
    }
    QPalette pal = ui->lineEdit->palette();
    pal.setBrush(ui->lineEdit->backgroundRole(), QBrush(Qt::white));
    ui->lineEdit->setPalette(pal);


    //
    // Codes to text
    //
    QString code_txt = "";
    for(int i=0; i<codes4BList.length(); i++){
        code_txt += "0b";
        for(int b=3; b>=0; b--){
            if(codes4BList[i] & (1<<b)){
                code_txt += "1";
            }else{
                code_txt += "0";
            }
        }
        code_txt += "\n";
    }
    ui->textEdit4B->setPlainText(code_txt);



    //
    // Drawing
    //
    ui->graphicsView->scene()->clear();

//    QGraphicsTextItem *text = ui->graphicsView->scene()->addText("4B");
//    text->setPos(-35, -35);

    bool drawVerticalLine = false;
    int x = 0;
    int y = 0;

    // Visualize UART (Bodo 5B, 1 stop):
    for(int i=0; i<codes4BList.length(); i++){
        for(int b=3; b>=0; b--){
//           if(codes4BList[i] & (1<<b)){
//               if(y == 0){
//                   drawVerticalLine = true;
//               }
//               y = SCALE_Y;
//           }else{
//               if(y == SCALE_Y){
//                   drawVerticalLine = true;
//               }
//               y = 0;
//           }
//           if(drawVerticalLine){
//               drawVerticalLine = false;
//               ui->graphicsView->scene()->addLine(x, 0 -diff, x, -SCALE_Y -diff, QPen(Qt::red));
//           }
//           ui->graphicsView->scene()->addLine(x, -y -diff, x + SCALE_X, -y -diff, QPen(Qt::red));
           x += SCALE_X;
       }
    }



    // Cells
    for(int i=0; i<x; i+=SCALE_X){
        ui->graphicsView->scene()->addLine(i, 0, i, -SCALE_Y, QPen(Qt::gray))->setZValue(-1);
    }
    ui->graphicsView->scene()->addLine(0, -SCALE_Y, x, -SCALE_Y, QPen(Qt::gray))->setZValue(-1);
    ui->graphicsView->scene()->addLine(0, 0, x, 0, QPen(Qt::gray))->setZValue(-1);


    ui->graphicsView->scene()->invalidate();
}
