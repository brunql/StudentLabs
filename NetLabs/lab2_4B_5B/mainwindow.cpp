/*
 * mainwindow.cpp
 *
 *  Created on: 12.09.2010
 *      Author: brunql
 *     Project: Lab2. 4B-5B codes.
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtGui"

#define SCALE_X   20
#define SCALE_Y   30

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

    lineEdit_Changing();
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

void MainWindow::drawListBits(QList<int> list, int y_level)
{
    int previousBit = 0;
    bool drawVerticalLine = false;
    int x = 0;
    int y = 0;
    for(int i=0; i<list.length(); i++){
        for(int b=4; b>=0; b--){
           if(list[i] & (1<<b)){
               y = SCALE_Y;
               if(previousBit == 0){
                   drawVerticalLine = true;
               }
               previousBit = 1;
           }else{
               y = 0;
               if(previousBit == 1){
                   drawVerticalLine = true;
               }
               previousBit = 0;
           }
           if(drawVerticalLine){
               drawVerticalLine = false;
               ui->graphicsView->scene()->addLine(x, 0 -y_level, x, -SCALE_Y -y_level, QPen(Qt::red));
           }
           ui->graphicsView->scene()->addLine(x, -y -y_level, x+SCALE_X, -y -y_level, QPen(Qt::red));
           x += SCALE_X;
       }
    }

    // Cells
    for(int i=0; i<x; i+=SCALE_X){
        ui->graphicsView->scene()->addLine(i, 0 -y_level, i, -SCALE_Y -y_level, QPen(Qt::gray))->setZValue(-1);
    }
    ui->graphicsView->scene()->addLine(0, 0 -y_level, x, 0 -y_level, QPen(Qt::gray))->setZValue(-1);
    ui->graphicsView->scene()->addLine(0, -SCALE_Y -y_level, x, -SCALE_Y -y_level, QPen(Qt::gray))->setZValue(-1);

}

void MainWindow::lineEdit_Changing()
{
    QString line = ui->lineEdit->text().toUpper();
    ui->lineEdit->setText(line);


    // Get codes
    QList<int> codes4BList, codes5BList;

    for(int c=0; c<line.length(); c++){
        if(line[c].isDigit()){ // TODO: add ABCDEF
            codes4BList.append( line[c].digitValue() );
            codes5BList.append( codes5B[ line[c].digitValue() ] );
        }else{
            codes4BList.append(0);
            codes5BList.append(0);
        }
    }

    QString code_txt = "Code 4B\t Code 5B\n";

    for(int i=0; i<codes5BList.length(); i++){
        code_txt += "0b";
        for(int b=3; b>=0; b--){
            if(codes4BList[i] & (1<<b)){
                code_txt += "1";
            }else{
                code_txt += "0";
            }
        }

        code_txt += "\t 0b";
        for(int b=4; b>=0; b--){
            if(codes5BList[i] & (1<<b)){
                code_txt += "1";
            }else{
                code_txt += "0";
            }
        }
        code_txt += "\n";
    }

    ui->textEdit->setPlainText(code_txt);

    // Drawing
    ui->graphicsView->scene()->clear();

    QGraphicsTextItem *text = ui->graphicsView->scene()->addText("4B");
    text->setPos(-2*SCALE_X, -(2.5*SCALE_Y));
    this->drawListBits(codes4BList, 2*SCALE_Y);

    text = ui->graphicsView->scene()->addText("5B");
    text->setPos(-2*SCALE_X, -SCALE_Y/2);
    this->drawListBits(codes5BList, 0);

    ui->graphicsView->scene()->invalidate();
}
