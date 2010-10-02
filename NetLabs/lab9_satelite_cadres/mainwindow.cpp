/*
 * mainwindow.cpp
 *
 *  Created on: 2.10.2010
 *      Author: brunql
 *     Project: Lab 9. Satelite cadres show must go on
 */


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtGui"

#define SCALE_X   30
#define SCALE_Y   60


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
    connect(ui->centralWidget, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(lineEdit_Changing()));

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
    // Encode input text to bodo codes
    //
    QList<int> codesList;
    int bodoSwitchRegister = 0;

    for(int c=0; c<lineInput.length(); c++){
        int code = -1;
        for(int i=0; i<29; i++){
            if(lineInput[c] == bodoChars[i]){
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
                if(lineInput[c] == bodoDigits[i]){
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

    ui->textEditBodo->setPlainText(codes);



    //
    // Drawing
    //
    ui->graphicsView->scene()->clear();
    QPen redPen2(Qt::red, 2);

//    QGraphicsTextItem *text = ui->graphicsView->scene()->addText("4B");
//    text->setPos(-35, -35);

    int x=0, y=0;

    for(int i=0; i<4; i++){
        ui->graphicsView->scene()->addText("Channel #" + QString::number(i+1))->setPos(SCALE_X*4 + i * SCALE_X*7, -1.5*SCALE_Y);
    }

    // Visualize sending birth date in 3-channel, Bodo codes, sync mode:
    for(int i=0; i<codesList.length(); i++){
        // Draw sync impulse:
        ui->graphicsView->scene()->addText("Sync")->setPos(x + SCALE_X/3, y-SCALE_Y/3*2);
        ui->graphicsView->scene()->addRect(x, y, SCALE_X * 3, -SCALE_Y);
        x += SCALE_X * 4;

        // Start of channel
        ui->graphicsView->scene()->addText("S")->setPos(x + SCALE_X/3, y-SCALE_Y/3*2);
        ui->graphicsView->scene()->addRect(x, y, SCALE_X, -SCALE_Y);
        x += SCALE_X;

        // First channel send zero
        for(int first=0; first < 5; first++){
            ui->graphicsView->scene()->addText("0")->setPos(x + SCALE_X/3, y-SCALE_Y/3*2);
            ui->graphicsView->scene()->addRect(x, y, SCALE_X, -SCALE_Y / 10);
            x += SCALE_X;
        }
        x += SCALE_X;

        // Start of channel
        ui->graphicsView->scene()->addText("S")->setPos(x + SCALE_X/3, y-SCALE_Y/3*2);
        ui->graphicsView->scene()->addRect(x, y, SCALE_X, -SCALE_Y);
        x += SCALE_X;
        // Second channel send zero
        for(int second=0; second < 5; second++){
            ui->graphicsView->scene()->addText("0")->setPos(x + SCALE_X/3, y-SCALE_Y/3*2);
            ui->graphicsView->scene()->addRect(x, y, SCALE_X, -SCALE_Y / 10);
            x += SCALE_X;
        }
        x += SCALE_X;

        // Start of channel
        ui->graphicsView->scene()->addText("S")->setPos(x + SCALE_X/3, y-SCALE_Y/3*2);
        ui->graphicsView->scene()->addRect(x, y, SCALE_X, -SCALE_Y);
        x += SCALE_X;
        // Thrird channel
        for(int b=4; b>=0; b--){

            if(codesList[i] & (1<<b)){
                ui->graphicsView->scene()->addText("1")->setPos(x + SCALE_X/3, y-SCALE_Y/3*2);
                ui->graphicsView->scene()->addRect(x, y, SCALE_X, -SCALE_Y);
            }else{
                ui->graphicsView->scene()->addText("0")->setPos(x + SCALE_X/3, y-SCALE_Y/3*2);
                ui->graphicsView->scene()->addRect(x, y, SCALE_X, -SCALE_Y / 10);
            }
            x += SCALE_X;
        }
        x += SCALE_X;

        // Start of channel
        ui->graphicsView->scene()->addText("S")->setPos(x + SCALE_X/3, y-SCALE_Y/3*2);
        ui->graphicsView->scene()->addRect(x, y, SCALE_X, -SCALE_Y);
        x += SCALE_X;
        // Fourth channel send zero
        for(int fourth=0; fourth < 5; fourth++){
            ui->graphicsView->scene()->addText("0")->setPos(x + SCALE_X/3, y -SCALE_Y/3*2);
            ui->graphicsView->scene()->addRect(x, y, SCALE_X, -SCALE_Y/10);
            x += SCALE_X;
        }
        x = 0;
        y += 1.5 * SCALE_Y;
    }

    ui->graphicsView->scene()->addText(" ")->setPos(0, y);


    ui->graphicsView->scene()->invalidate();
    ui->graphicsView->scene()->update(ui->graphicsView->scene()->sceneRect());
}
