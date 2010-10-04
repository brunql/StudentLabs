/*
 * main.cpp
 *
 *  Created on: 3.10.2010
 *      Author: brunql
 */

#include "cameradevice.h"

#define BUFFER_SIZE 2574


CameraDevice::CameraDevice(int time) : QThread()
{
    this->loop = false;
    this->time = time;

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

    if(device->setBaudRate(AbstractSerial::BaudRate115200) == false){
        qDebug() << "error: setBaudRate";
        exit(3);
    }
}


void CameraDevice::run(){
    while(loop){     

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
            QPainterPath *path = new QPainterPath();
            path->moveTo(0, rawSignalBuffer[0] & 0xff);
            for(int i=0; i<BUFFER_SIZE-1; i++){
                int prev = rawSignalBuffer[i]   & 0xff;
                int now  = rawSignalBuffer[i+1] & 0xff;
                path->lineTo(i, now);

                ba->append(prev);
                //            columns++;

                if (prev == 1 && now != 1){
                    lines++;
                    //                qDebug() << "  columns =" << columns;

                    videoBuffer.append(ba);
                    ba = new QByteArray();
                    columns = 0;
                }
            }
            //        qDebug() << "lines =" << lines;

            emit graphOscill_NewPath(path);


            QImage *im = new QImage(32, lines, QImage::Format_RGB32);
            im->fill(0);
            for(int line=0; line<lines; line++){
                for(int c=0; c < 32 && c<videoBuffer[line]->length(); c++){
                    int gray = videoBuffer[line]->at(c) & 0xff;
                    int rgb = (gray << 16) | (gray << 8) | (gray); //0xffRRGGBB
                    im->setPixel(c, line, rgb);
                }
            }
            emit graphImage_NewImage(im);

        }else{
            qDebug() << "waitForReadyRead() fail";
        }


        usleep(this->time * 1000);
    }
}

void CameraDevice::setLoop(bool loop)
{
    this->loop = loop;
}

bool CameraDevice::getLoop()
{
    return this->loop;
}
