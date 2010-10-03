/*
 * mainwindow.cpp
 *
 *  Created on: 2.10.2010
 *      Author: brunql
 *     Project: Lab 11. Digitizing of the analog PAL CMOS camera
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"


#define BUFFER_SIZE 1000

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphViewOscilloscope->setScene(new QGraphicsScene(ui->graphViewOscilloscope));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerTimeout()));
    connect(ui->pushButtonStartStop, SIGNAL(clicked()), this, SLOT(buttonStartStop()));

    device = new AbstractSerial();
    if(!device){
        qDebug() << "Error: AbstractSerial *device = new AbstractSerial();";
        return;
    }

    QString devicePath = "/dev/";

    QStringList filter_ttyUSB;
    filter_ttyUSB << "ttyUSB?";
    QStringList list_ttyUSB = QDir("/dev/").entryList(filter_ttyUSB, QDir::System);
    if(list_ttyUSB.count() == 0){
        qDebug() << "Can't find any device starts with '/dev/ttyUSB'. Please check FTDI connection.";
        exit(1);
    }else if(list_ttyUSB.count() == 1){
        devicePath += list_ttyUSB[0];
    }else{ // > 1
        qDebug() << "Found devices:";
        for(int i=0; i<list_ttyUSB.count(); i++){
            qDebug() << "/dev/" << list_ttyUSB[i];
        }
        qDebug() << "I need help to make right choice";
        exit(2);
    }
    device->setDeviceName(devicePath);

    if(!device->open(QIODevice::ReadWrite | QIODevice::Unbuffered)){
        qDebug() << "Device open failed.";
        exit(3);
    }

    timer->setInterval(1000);
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

void MainWindow::buttonStartStop()
{
    if(timer->isActive()){
        timer->stop();
    }else{
        timer->start();
    }
}


void MainWindow::timerTimeout()
{
    qDebug() << "timerTimeout()";

    bool result = device->putChar(0xf0);
    if(result == false){
        qDebug() << "timerTimeout(): device->putChar(0xf0) fail";
        return;
    }

    QByteArray ba;
    if(device->waitForReadyRead(100)){
        ba.clear();
        ba = device->read(BUFFER_SIZE);

        // Visualize
        ui->graphViewOscilloscope->scene()->clear();
        int num = 0;
        int num_max = 0;
        for(int i=0; i<BUFFER_SIZE; i++){
            ui->graphViewOscilloscope->scene()->addLine(i, 0, i, -(ba[i] & 0xff));
            if(ba[i] == 1){
                num++;
            }else{
                if(num > num_max){
                    qDebug() << num;
                    num_max = num;
                }
                num = 0;
            }
        }        
        repaint();
    }else{
        qDebug() << "waitForReadyRead() fail";
    }
}
