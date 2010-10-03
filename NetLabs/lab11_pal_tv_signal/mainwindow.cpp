/*
 * mainwindow.cpp
 *
 *  Created on: 2.10.2010
 *      Author: brunql
 *     Project: Lab 11. Digitizing of the analog PAL CMOS camera
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"

#define BUFFER_SIZE 4096

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphViewOscilloscope->setScene(new QGraphicsScene(ui->graphViewOscilloscope));
    ui->graphViewImage->setScene(new QGraphicsScene(ui->graphViewImage));
    ui->graphViewImage->scale(3,2);

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
    //device->setBaudRate(AbstractSerial::BaudRate9600);
    device->setDeviceName(devicePath);

    if(!device->open(QIODevice::ReadWrite | QIODevice::Unbuffered)){
        qDebug() << "Device open failed.";
        exit(3);
    }

    timer->setInterval(1000);
    timer->start();
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
        qDebug() << "buttonStartStop(): timer stopped";
    }else{
        timer->start();
        qDebug() << "buttonStartStop(): timer started";
    }
}


void MainWindow::timerTimeout()
{
    bool result = device->putChar(0xf0);
    if(result == false){
        qDebug() << "timerTimeout(): device->putChar(0xf0) fail";
        return;
    }

    QByteArray rawSignalBuffer;
    QList<QByteArray *> videoBuffer;
    if(device->waitForReadyRead(100)){
        rawSignalBuffer.clear();
        rawSignalBuffer = device->read(BUFFER_SIZE);

        int lines = 0;
        int columns = 0;
        QByteArray *ba = new QByteArray(); // temp QByteArray for video line

        // Visualize raw signal
        ui->graphViewOscilloscope->scene()->clear();
        for(int i=0; i<BUFFER_SIZE-1; i++){
            int prev = rawSignalBuffer[i]   & 0xff;
            int now  = rawSignalBuffer[i+1] & 0xff;
            ui->graphViewOscilloscope->scene()->addLine(i, -prev, i, -now);

            ba->append(prev);
            columns++;

            if (prev == 1 && now != 1){
                lines++;
                qDebug() << "  columns =" << columns;

                videoBuffer.append(ba);
                ba = new QByteArray();
                columns = 0;
            }
        }
        qDebug() << "lines =" << lines;

        ui->graphViewImage->scene()->clear();
        QImage im(32, lines, QImage::Format_RGB32);
        for(int line=0; line<lines; line++){
            for(int c=0; c < 32 && c<videoBuffer[line]->length(); c++){
                int gray = videoBuffer[line]->at(c) & 0xff;
                int rgb = (gray << 16) | (gray << 8) | (gray); //0xffRRGGBB
                im.setPixel(c, line, rgb);
            }
        }
        ui->graphViewImage->scene()->addPixmap(QPixmap::fromImage(im));
        repaint();
    }else{
        qDebug() << "waitForReadyRead() fail";
    }
}












