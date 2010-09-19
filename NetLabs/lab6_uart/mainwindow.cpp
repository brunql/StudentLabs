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


const int MainWindow::codes5B[16] = {
    0b11110,
    0b01001,
    0b10100,
    0b10101,
    0b01010,
    0b01011,
    0b01110,
    0b01111,
    0b10010,
    0b10011,
    0b10110,
    0b10111,
    0b11010,
    0b11011,
    0b11100,
    0b11101
};






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
    // 4B
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

    // 5B
    QList<int> codes5BList;
    for(int i=0; i<codes4BList.length(); i++){
        codes5BList.append( codes5B[ codes4BList[i] ] );
    }


    //
    // Codes to text
    //
    QString code4B_txt = "";
    for(int i=0; i<codes4BList.length(); i++){
        code4B_txt += "0b";
        for(int b=3; b>=0; b--){
            if(codes4BList[i] & (1<<b)){
                code4B_txt += "1";
            }else{
                code4B_txt += "0";
            }
        }
        code4B_txt += "\n";
    }
    ui->textEdit4B->setPlainText(code4B_txt);

    QString code5B_txt = "";
    for(int i=0; i<codes5BList.length(); i++){
        code5B_txt += "0b";
        for(int b=4; b>=0; b--){
            if(codes5BList[i] & (1<<b)){
                code5B_txt += "1";
            }else{
                code5B_txt += "0";
            }
        }
        code5B_txt += "\n";
    }
    ui->textEdit5B->setPlainText(code5B_txt);


    //
    // Drawing
    //
    ui->graphicsView->scene()->clear();

    bool drawVerticalLine = false;
    int x = 0;
    int y = 0;
    int diff = 0;
    QGraphicsTextItem *text;

    // Visualize UART (Bodo 5B, 1 stop):
    for(int i=0; i<codes5BList.length(); i++){
        // Start bit:
        ui->graphicsView->scene()->addLine(x, -y, x, 0, QPen(Qt::red));
        ui->graphicsView->scene()->addLine(x, 0, x + SCALE_X, 0, QPen(Qt::red));
        text = ui->graphicsView->scene()->addText("Start");
        diff = (SCALE_X - text->boundingRect().width()) / 2;
        text->setPos(x + diff, 0);
        x += SCALE_X;

        // Data bits:
        y = 0;
        for(int b=4; b>=0; b--){
           if(codes5BList[i] & (1<<b)){
               if(y == 0){
                   drawVerticalLine = true;
               }
               y = SCALE_Y;
           }else{
               if(y == SCALE_Y){
                   drawVerticalLine = true;
               }
               y = 0;
           }
           if(drawVerticalLine){
               drawVerticalLine = false;
               ui->graphicsView->scene()->addLine(x, 0, x, -SCALE_Y, QPen(Qt::red));
           }
           ui->graphicsView->scene()->addLine(x, -y, x + SCALE_X, -y, QPen(Qt::red));
           text = ui->graphicsView->scene()->addText("D" + QString::number(b));
           diff = (SCALE_X - text->boundingRect().width()) / 2;
           text->setPos(x + diff, 0);
           x += SCALE_X;
        }

        // Stop bit:
        if(y == 0){
            ui->graphicsView->scene()->addLine(x, 0, x, -SCALE_Y, QPen(Qt::red));
        }
        y = SCALE_Y;
        ui->graphicsView->scene()->addLine(x, -y, x + SCALE_X, -y, QPen(Qt::red));
        text = ui->graphicsView->scene()->addText("Stop");
        diff = (SCALE_X - text->boundingRect().width()) / 2;
        text->setPos(x + diff, 0);
        x += SCALE_X;
    }



    // Cells
    for(int i=0; i<x; i+=SCALE_X){
        ui->graphicsView->scene()->addLine(i, 0, i, -SCALE_Y, QPen(Qt::gray))->setZValue(-1);
    }
    ui->graphicsView->scene()->addLine(0, -SCALE_Y, x, -SCALE_Y, QPen(Qt::gray))->setZValue(-1);
    ui->graphicsView->scene()->addLine(0, 0, x, 0, QPen(Qt::gray))->setZValue(-1);


    ui->graphicsView->scene()->invalidate();
}
