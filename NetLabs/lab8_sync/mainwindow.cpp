/*
 * mainwindow.cpp
 *
 *  Created on: 2.10.2010
 *      Author: brunql
 *     Project: Lab 8. Sync impulses
 */


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtGui"

#define SCALE_X   30
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
    QPen redPen2(Qt::red, 2);

//    QGraphicsTextItem *text = ui->graphicsView->scene()->addText("4B");
//    text->setPos(-35, -35);

    bool drawVerticalLine = false;
    int x = 0;
    int y = 0;
    int diff = 2 * SCALE_Y; // up or down graphs from center on diff bits

    // 4B code with sync impulses visualize:
    for(int i=0; i<codes4BList.length(); i++){
        // draw sync impulse:
        if(y == SCALE_Y){
            ui->graphicsView->scene()->addLine(x, 0, x, -SCALE_Y, redPen2);
        }
        ui->graphicsView->scene()->addLine(x, 0, x + SCALE_X, 0, redPen2);   // line
        x += SCALE_X;
        ui->graphicsView->scene()->addLine(x, 0, x, -SCALE_Y, redPen2);      // up
        ui->graphicsView->scene()->addLine(x, -SCALE_Y, x + SCALE_X, -SCALE_Y, redPen2);   // line
        x += SCALE_X;
        ui->graphicsView->scene()->addLine(x, -SCALE_Y, x, 0, redPen2);      // down
        ui->graphicsView->scene()->addLine(x, 0, x + SCALE_X/3, 0, redPen2); // line/2
        x += SCALE_X/3;
        ui->graphicsView->scene()->addLine(x, 0, x, -SCALE_Y, redPen2);      // up
        ui->graphicsView->scene()->addLine(x, -SCALE_Y, x + SCALE_X, -SCALE_Y, redPen2);   // line
        x += SCALE_X;
        ui->graphicsView->scene()->addLine(x, -SCALE_Y, x, 0, redPen2);      // down
        ui->graphicsView->scene()->addLine(x, 0, x + SCALE_X, 0, redPen2);   // line
        x += SCALE_X;

        y = 0;


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
               ui->graphicsView->scene()->addLine(x, 0, x, -SCALE_Y, redPen2);
           }
           ui->graphicsView->scene()->addLine(x, -y, x + SCALE_X, -y, redPen2);
           x += SCALE_X;
       }
    }   



    ui->graphicsView->scene()->invalidate();
    ui->graphicsView->scene()->update(ui->graphicsView->scene()->sceneRect());
}
