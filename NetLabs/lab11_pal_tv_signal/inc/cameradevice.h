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

#include "usb.h"
#include "hiddata.h"
#include "usbconfig.h"
#include "timeevaluations.h"

class CameraDevice : public QThread, public QRunnable
{
    Q_OBJECT

public:
    CameraDevice(int time);
    void run();
    void setLoop(bool loop);
    bool getLoop();

    // USB HID functions
    bool openDevice();
    bool readDataFromDevice();
    bool writeBufferToDevice();
    QString usbErrorMessage(int errCode);

signals:
    void graphOscill_NewPath(QPainterPath *path);
    void graphImage_NewImage(QImage *im);

private:
    int time;
    bool loop;

    AbstractSerial *device;    
    TimeEvaluations *timeEval;

    usb_dev_handle *usbDeviceCamera; // USB HID device

    // USB HID buffers
    char read_buffer[1 + 7];    /* 0-system, 1..7-data */
    char write_buffer[1 + 7];   /* 0-system, 1..7-data */
};

#endif // CAMERADEVICE_H
