/*
 * main.cpp
 *
 *  Created on: 3.10.2010
 *      Author: brunql
 */

#ifndef CAMERADEVICE_H
#define CAMERADEVICE_H

#include <QtGui>
#include <QObject>
#include <abstractserial.h>

#include "timeevaluations.h"

class CameraDevice : public QThread, public QRunnable
{
    Q_OBJECT

public:
    CameraDevice(int time);
    void run();
    void setLoop(bool loop);
    bool getLoop();

signals:
    void graphOscill_NewPath(QPainterPath *path);
    void graphImage_NewImage(QImage *im);

private:
    int time;
    bool loop;

    AbstractSerial *device;    
    TimeEvaluations *timeEval;
};

#endif // CAMERADEVICE_H
