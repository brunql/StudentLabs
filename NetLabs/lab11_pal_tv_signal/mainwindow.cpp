/*
 * mainwindow.cpp
 *
 *  Created on: 2.10.2010
 *      Author: brunql
 *     Project: Lab 11. Digitizing of the analog PAL CMOS camera
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->graphViewOscilloscope->setScene(new QGraphicsScene(ui->graphViewOscilloscope));
    ui->graphViewImage->setScene(new QGraphicsScene(ui->graphViewImage));
    //QTransform matrix = ui->graphViewImage->transform();

    camDevice = new CameraDevice(1);

    connect(ui->pushButtonStartStop, SIGNAL(clicked()), this, SLOT(buttonStartStop()));
    connect(camDevice, SIGNAL(graphOscill_NewPath(QPainterPath*)), this, SLOT(graphOscill_AddPath(QPainterPath*)));
    connect(camDevice, SIGNAL(graphImage_NewImage(QImage*)), this, SLOT(graphImage_AddImage(QImage*)));
    ui->graphViewOscilloscope->scale(1, -1);


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
    if(camDevice->getLoop() == true){
        qDebug() << "camDevice->loop = false;";
        camDevice->setLoop(false);

    }else{
        qDebug() << "camDevice->loop = true;";
        camDevice->setLoop(true);
        camDevice->start(QThread::HighPriority);
    }
}


void MainWindow::graphOscill_AddPath(QPainterPath *path)
{
    ui->graphViewOscilloscope->scene()->clear();
    ui->graphViewOscilloscope->scene()->addPath(*path);
    repaint();
}

void MainWindow::graphImage_AddImage(QImage *im)
{
    int imScaledWidth = im->width()*ui->horSliderScale->value();
    int imScaledHeight = im->height()*ui->horSliderScale->value();

    ui->graphViewImage->scene()->clear();    
    ui->graphViewImage->scene()->addPixmap(
            QPixmap::fromImage(
                        im->scaled(imScaledWidth, imScaledHeight, Qt::IgnoreAspectRatio)
                    )
            )->setPos(0, 0);
    ui->labelScaleXY->setText(QString::number(imScaledWidth) + "x" + QString::number(imScaledHeight));

    repaint();
}

