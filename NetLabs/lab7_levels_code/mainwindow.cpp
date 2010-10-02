/*
 * mainwindow.cpp
 *
 *  Created on: 15.09.2010
 *      Author: brunql
 *     Project: Lab5. Modem: 4B code -> FMO code -> Phase modulation
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
    int diff = 2 * SCALE_Y; // up or down graphs from center on diff bits

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
               ui->graphicsView->scene()->addLine(x, 0 -diff, x, -SCALE_Y -diff, QPen(Qt::red));
           }
           ui->graphicsView->scene()->addLine(x, -y -diff, x + SCALE_X, -y -diff, QPen(Qt::red));
           x += SCALE_X;
       }
    }

    x = y = 0;

    QList<bool> codesFMOList; // save bits for phase modulation

    // FMO code visualize:
    for(int i=0; i<codes4BList.length(); i++){
        for(int bit = (1<<3); bit != 0; bit >>= 1){
            if(codes4BList[i] & bit){
                if(y == 0){
                    y = SCALE_Y;
                    codesFMOList.append(true);
                    codesFMOList.append(true);
                }else{
                    y = 0;
                    codesFMOList.append(false);
                    codesFMOList.append(false);
                }
                ui->graphicsView->scene()->addLine(x, -y, x + SCALE_X, -y, QPen(Qt::red));
            }else{
                if(y == 0){
                    codesFMOList.append(true);
                    codesFMOList.append(false);
                    ui->graphicsView->scene()->addLine(x,             -SCALE_Y, x + SCALE_X/2, -SCALE_Y, QPen(Qt::red));
                    ui->graphicsView->scene()->addLine(x + SCALE_X/2, -SCALE_Y, x + SCALE_X/2,  0,       QPen(Qt::red));
                    ui->graphicsView->scene()->addLine(x + SCALE_X/2,  0,       x + SCALE_X,    0,       QPen(Qt::red));
                }else{
                    codesFMOList.append(false);
                    codesFMOList.append(true);
                    ui->graphicsView->scene()->addLine(x,             0,        x + SCALE_X/2, 0,        QPen(Qt::red));
                    ui->graphicsView->scene()->addLine(x + SCALE_X/2, 0,        x + SCALE_X/2, -SCALE_Y, QPen(Qt::red));
                    ui->graphicsView->scene()->addLine(x + SCALE_X/2, -SCALE_Y, x+SCALE_X,     -SCALE_Y, QPen(Qt::red));
                }
            }
            // Drawing vertical line:
            ui->graphicsView->scene()->addLine(x, 0, x, -SCALE_Y, QPen(Qt::red));

            x += SCALE_X;
        }
    }


    // Visualize quadrature phase-modulation:
    int phase = 0;
//    int prev_bits = 0;
    double y_, x_save, y_save;
    y_ = x_save = y_save = 0;

    if(codesFMOList.length() % 2 != 0){
        codesFMOList.append(false);
        qDebug() << "Error: codesFMOList contains odd elements. Append zero.";
    }

    int i = 0;
    for(int x_ = 0; x_ < codesFMOList.length()/2 * SCALE_X; x_++){
        if((x_ % (SCALE_X)) == 0 ){
            // if bit changes then change phase
            if(i+1 > codesFMOList.length()){
                qDebug() << "The end: i =" << i;
                return;
            }
            int now_bits = ((int)codesFMOList[i] << 1) | (codesFMOList[i+1]);
            switch(now_bits){
                case 0b00: phase = 1*M_PI / 4; break;
                case 0b01: phase = 3*M_PI / 4; break;
                case 0b10: phase = 5*M_PI / 4; break;
                case 0b11: phase = 7*M_PI / 4; break;
            }
            i += 2;
        }
        y_ = sin(x_/M_PI + phase);
        ui->graphicsView->scene()->addLine(x_save,
                                           y_save * SCALE_Y/2 +diff -SCALE_Y/2,
                                           x_,
                                           y_ * SCALE_Y/2 +diff -SCALE_Y/2,
                                           QPen(Qt::red));

        y_save = y_;
        x_save = x_;
    }

    x = codesFMOList.length()/2 * SCALE_X;

    // Cells
    for(int i=0; i<x; i+=SCALE_X){
        ui->graphicsView->scene()->addLine(i, diff, i, -SCALE_Y -diff, QPen(Qt::gray))->setZValue(-1);
    }
    ui->graphicsView->scene()->addLine(0, -SCALE_Y -diff, x, -SCALE_Y -diff, QPen(Qt::gray))->setZValue(-1);
    ui->graphicsView->scene()->addLine(0, -diff, x, -diff, QPen(Qt::gray))->setZValue(-1);
    ui->graphicsView->scene()->addLine(0, -SCALE_Y, x, -SCALE_Y, QPen(Qt::gray))->setZValue(-1);
    ui->graphicsView->scene()->addLine(0, 0, x, 0, QPen(Qt::gray))->setZValue(-1);
    ui->graphicsView->scene()->addLine(0, SCALE_Y, x, SCALE_Y, QPen(Qt::gray))->setZValue(-1);
    ui->graphicsView->scene()->addLine(0, diff, x, diff, QPen(Qt::gray))->setZValue(-1);


    ui->graphicsView->scene()->invalidate();
    ui->graphicsView->scene()->update(ui->graphicsView->scene()->sceneRect());
}
