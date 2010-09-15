/*
 * mainwindow.cpp
 *
 *  Created on: 12.09.2010
 *      Author: brunql
 *     Project: Lab3. Manchester and mlt3 codes.
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtGui"

#define SCALE_X   20
#define SCALE_Y   30

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(new QGraphicsScene(this));

    connect(ui->lineEdit4BManchester, SIGNAL(textChanged(QString)), this, SLOT(lineEdit_Changing()));
    connect(ui->lineEditMlt3, SIGNAL(textChanged(QString)), this, SLOT(lineEdit_Changing()));

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
    QString line4BManchester = ui->lineEdit4BManchester->text();
    QString lineMlt3 = ui->lineEditMlt3->text();

    //
    // Get codes
    //
    QList<int> codes4BList;
    for(int c=0; c<line4BManchester.length(); c++){
        if(line4BManchester[c].isDigit()){ // TODO: add ABCDEF
            codes4BList.append( line4BManchester[c].digitValue() );
        }else{
            codes4BList.append(0);
        }
    }

    //
    // Codes to text
    //
    QString code_txt = "Code 4B\n";
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

    code_txt = trUtf8("МЛТ-3\n");
    for(int i=0; i<lineMlt3.length(); i++){
        code_txt += "0b";
        for(int b=15; b>=0; b--){
            if(lineMlt3.at(i).unicode() & (1<<b)){
                code_txt += "1";
            }else{
                code_txt += "0";
            }
        }
        code_txt += "\n";
    }
    ui->textEditMlt3->setPlainText(code_txt);


    //
    // Drawing
    //
    ui->graphicsView->scene()->clear();

//    QGraphicsTextItem *text = ui->graphicsView->scene()->addText("4B");
//    text->setPos(-35, -35);

    bool drawVerticalLine = false;
    int x = 0;
    int y = 0;

    // 4B code visualize:
    for(int i=0; i<codes4BList.length(); i++){
        for(int b=3; b>=0; b--){
           if(codes4BList[i] & (1<<b)){
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
           x += SCALE_X;
       }
    }

    // Manchester code visualize:
    for(int i=0; i<codes4BList.length(); i++){
        for(int b=3; b>=0; b--){
           if(codes4BList[i] & (1<<b)){
               if(y == SCALE_Y){
                   drawVerticalLine = true;
               }
               y = SCALE_Y;
               ui->graphicsView->scene()->addLine(x,             0,        x + SCALE_X/2, 0,        QPen(Qt::red));
               ui->graphicsView->scene()->addLine(x + SCALE_X/2, 0,        x + SCALE_X/2, -SCALE_Y, QPen(Qt::red));
               ui->graphicsView->scene()->addLine(x + SCALE_X/2, -SCALE_Y, x+SCALE_X,     -SCALE_Y, QPen(Qt::red));
           }else{
               if(y == 0){
                   drawVerticalLine = true;
               }
               y = 0;
               ui->graphicsView->scene()->addLine(x,             -SCALE_Y, x + SCALE_X/2, -SCALE_Y, QPen(Qt::red));
               ui->graphicsView->scene()->addLine(x + SCALE_X/2, -SCALE_Y, x + SCALE_X/2,  0,       QPen(Qt::red));
               ui->graphicsView->scene()->addLine(x + SCALE_X/2,  0,       x + SCALE_X,    0,       QPen(Qt::red));
           }
           if(drawVerticalLine){
               drawVerticalLine = false;
               ui->graphicsView->scene()->addLine(x, 0, x, -SCALE_Y, QPen(Qt::red));
           }

           x += SCALE_X;
       }
    }

    // MLT-3 code visualize:
    int prev_y = y;
    for(int i=0; i<lineMlt3.length(); i++){
        for(int b=15; b>=0; b--){
           if(lineMlt3[i].unicode() & (1<<b)){
               if(y == 0){
                   prev_y = y;
                   y = SCALE_Y / 2;
                   ui->graphicsView->scene()->addLine(x, 0, x, -y, QPen(Qt::red));
               }else if(y == SCALE_Y / 2){
                   if(prev_y == 0){
                       y = SCALE_Y;
                   }else if(prev_y == SCALE_Y){
                       y = 0;
                   }
                   ui->graphicsView->scene()->addLine(x, -SCALE_Y/2, x, -y, QPen(Qt::red));
               }else if(y == SCALE_Y){
                   prev_y = y;
                   y = SCALE_Y / 2;
                   ui->graphicsView->scene()->addLine(x, -SCALE_Y, x, -y, QPen(Qt::red));
               }
               ui->graphicsView->scene()->addLine(x, -y, x + SCALE_X, -y, QPen(Qt::red));
           }else{
               y = y; // Nothing change
               ui->graphicsView->scene()->addLine(x, -y, x + SCALE_X, -y, QPen(Qt::red));
           }
           x += SCALE_X;
       }
    }

    // Cells
    for(int i=0; i<x; i+=SCALE_X){
        ui->graphicsView->scene()->addLine(i, 0, i, -SCALE_Y, QPen(Qt::gray))->setZValue(-1);
    }
    ui->graphicsView->scene()->addLine(0, 0, x, 0, QPen(Qt::gray))->setZValue(-1);
    ui->graphicsView->scene()->addLine(0, -SCALE_Y, x, -SCALE_Y, QPen(Qt::gray))->setZValue(-1);

    ui->graphicsView->scene()->invalidate();
}
