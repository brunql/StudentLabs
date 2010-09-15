/*
 * mainwindow.cpp
 *
 *  Created on: 12.09.2010
 *      Author: brunql
 *     Project: Lab1. Bodo codes.
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtGui"

#define SCALE_X   20
#define SCALE_Y   30

const int MainWindow::bodoCodes[32] = {
  0b11000,
  0b10011,
  0b01110,
  0b10010,
  0b10000,
  0b10110,
  0b01011,
  0b00101,
  0b01100,
  0b11010,
  0b11110,
  0b01001,
  0b00111,
  0b00110,
  0b00011,
  0b01101,
  0b11101,
  0b01010,
  0b10100,
  0b00001,
  0b11100,
  0b01111,
  0b11001,
  0b10111,
  0b10101,
  0b10001,
  0b00000,
  0b00100,
  0b01000,
  0b11111,
  0b11011,
  0b00010
};

const char MainWindow::bodoChars[29] = {
   'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\t',' ','\n'
};

const char MainWindow::bodoDigits[29] = {
   '-','?',':','w','3','*','*','*','8','b','(',')','.',',','9','0','1','4','\'','5','7','=','2','/','6','+','\t',' ','\n'
};

#define  BODO_SENDING_CHARS     1
#define  BODO_SENDING_DIGITS    2




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

void MainWindow::lineEdit_Changing()
{
    QString line = ui->lineEdit->text().toUpper();
    ui->lineEdit->setText(line);


    // Get codes
    QList<int> codesList;
    int bodoSwitchRegister = 0;

    for(int c=0; c<line.length(); c++){
        int code = -1;
        for(int i=0; i<29; i++){
            if(line[c] == bodoChars[i]){
                code = bodoCodes[i];
            }
        }
        if(code != -1){
            // Found char in bodoChars array
            if(bodoSwitchRegister != BODO_SENDING_CHARS){  // If not sended CHAR switch register
                bodoSwitchRegister = BODO_SENDING_CHARS;
                codesList.append(0b11111); // Append CHAR switch register.
            }
            codesList.append(code);
        }else{
            for(int i=0; i<29; i++){
                if(line[c] == bodoDigits[i]){
                    code = bodoCodes[i];
                }
            }
            if(code != -1){
                // Found char in bodoDigits array
                if(bodoSwitchRegister != BODO_SENDING_DIGITS){  // If not sended DIGIT switch register
                    bodoSwitchRegister = BODO_SENDING_DIGITS;
                    codesList.append(0b11011); // Append DIGIT switch register.
                }
                codesList.append(code);
            }else{
                // Char not found. Send zero.
                codesList.append(0);
            }
        }
    }

    // Codes in text
    QString codes = "";
    for(int i=0; i<codesList.length(); i++){
        codes += "0b";
        for(int b=4; b>=0; b--){
           if(codesList[i] & (1<<b)){
               codes += "1";
           }else{
               codes += "0";
           }
        }
        codes += "\n";
    }

    ui->textEdit->setPlainText(codes);


    // Drawing
    ui->graphicsView->scene()->clear();
    int previousBit = 0;
    bool drawVerticalLine = false;
    int x = 0;
    int y = 0;
    for(int i=0; i<codesList.length(); i++){
        for(int b=4; b>=0; b--){
           if(codesList[i] & (1<<b)){
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
               ui->graphicsView->scene()->addLine(x, 0, x, -SCALE_Y, QPen(Qt::red));
           }
           ui->graphicsView->scene()->addLine(x, -y, x+SCALE_X, -y, QPen(Qt::red));
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
