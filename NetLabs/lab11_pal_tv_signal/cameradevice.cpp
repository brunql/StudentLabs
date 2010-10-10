/*
 * main.cpp
 *
 *  Created on: 3.10.2010
 *      Author: brunql
 */

#include "cameradevice.h"

#define BUFFER_SIZE 1774



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
            QByteArray *ba = new QByteArray(); // temp QByteArray for video line

            // Visualize raw signal
            QPainterPath *path = new QPainterPath();
            path->moveTo(0, rawSignalBuffer[0] & 0xff);
            for(int i=0; i<BUFFER_SIZE-1; i++){
                int prev = rawSignalBuffer[i]   & 0xff;
                int now  = rawSignalBuffer[i+1] & 0xff;
                path->lineTo(i, now);

                ba->append(prev);
                if (prev == 1 && now != 1){
                    if(ba->length() >= 20){
                        videoBuffer.append(ba);
                        lines++;
                    }
                    ba = new QByteArray();
                }
            }

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


///
/// USB HID
///
bool CameraDevice::openDevice()
{
    usbDeviceCamera = NULL;

    const char * vendorName  = "brunql.github";
    const char * productName = "CameraDigitizer";
    int vid = USB_VENDOR_ID;
    int pid = USB_PROD_ID;

    int err;

    if((err = usbhidOpenDevice(&usbDeviceCamera, vid, NULL, pid, NULL, 1)) != 0){
        qWarning() << "Error finding " << productName << ": " << usbErrorMessage(err);
        return false;
    }
    qDebug("%s %s (PID: 0x%04x; VID: 0x%04x) opened.", productName, vendorName, pid, vid);
    return true;
}

bool CameraDevice::readDataFromDevice()
{
    int result = 0;
    char buff[65];
    memset(buff, 0, sizeof(buff));
    //memset(read_buffer, 0, sizeof(read_buffer));

    int len = sizeof(buff);
    //result = usb_get_string_simple(usbDeviceCamera, 0, buff, 256);
    //qDebug() << "usb_get_string_simple: " << result << usb_strerror();
    //qDebug() << QString(buff);      

    usbhidGetReport(usbDeviceCamera, 0, buff, &len);
    qDebug() << buff;


    result = usb_control_msg(usbDeviceCamera,
                             USB_CLASS_HID,
                             0x0, // GET_REPORT
                             0x0,
                             0,
                             buff, len, 1000);
    qDebug() << "usb_control_msg: " << result << usb_strerror();
    qDebug() << QString(buff);



//    int err;
//
//    int len = sizeof(read_buffer);
//    if((err = usbhidGetReport(dev, 0, read_buffer, &len)) != 0){
//        qWarning() << "error reading data:" << usbErrorMessage(err);
//        return false;
//    }
//    return true;
}

bool CameraDevice::writeBufferToDevice()
{
    int err;

    if((err = usbhidSetReport(usbDeviceCamera, write_buffer, sizeof(write_buffer), 500)) != 0){   /* add a dummy report ID */
        qWarning() << "error writing data:" << usbErrorMessage(err);
        return false;
    }
    return true;
}

QString CameraDevice::usbErrorMessage(int errCode)
{
    QString result = "";
    switch(errCode){
    case USBOPEN_ERR_ACCESS:      result = "Access to device denied"; break;
    case USBOPEN_ERR_NOTFOUND:    result = "The specified device was not found"; break;
    case USBOPEN_ERR_IO:          result = "Communication error with device"; break;
    default:
        result = result.sprintf("Unknown USB error %d", errCode);
        break;
    }
    return result;
}

