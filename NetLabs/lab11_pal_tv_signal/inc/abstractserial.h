/*
* This file is part of QSerialDevice, an open-source cross-platform library
* Copyright (C) 2009  Denis Shienkov
*
* This library is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*
* Contact Denis Shienkov:
*          e-mail: <scapig2@yandex.ru>
*             ICQ: 321789831
*/

#ifndef ABSTRACTSERIAL_H
#define ABSTRACTSERIAL_H

#include <QtCore/QIODevice>
#include <QtCore/QHash>
#include <QtCore/QDateTime>


class AbstractSerialPrivate;
class AbstractSerial : public QIODevice
{
    Q_OBJECT
    
Q_SIGNALS:
    void signalStatus(const QString &status, QDateTime current);

public:

    static const char defaultDeviceName[];

/*! \enum BaudRate
\~russian В этом перечислении представлены все поддерживаемые классом \a AbstractSerial скорости работы.
\~english In this enumeration of all supporting classes \a AbstractSerial speed.
*/
    enum BaudRate {
        BaudRate50      = 50,       /*!< \~russian скорость 50 бод      \~english speed 50 bauds */
        BaudRate75      = 75,       /*!< \~russian скорость 75 бод      \~english speed 75 bauds */
        BaudRate110     = 110,      /*!< \~russian скорость 110 бод     \~english speed 110 bauds */
        BaudRate134     = 134,      /*!< \~russian скорость 134 бод     \~english speed 134 bauds */
        BaudRate150     = 150,      /*!< \~russian скорость 150 бод     \~english speed 150 bauds */
        BaudRate200     = 200,      /*!< \~russian скорость 200 бод     \~english speed 200 bauds */
        BaudRate300     = 300,      /*!< \~russian скорость 300 бод     \~english speed 300 bauds */
        BaudRate600     = 600,      /*!< \~russian скорость 600 бод     \~english speed 600 bauds */
        BaudRate1200    = 1200,     /*!< \~russian скорость 1200 бод    \~english speed 1200 bauds */
        BaudRate1800    = 1800,     /*!< \~russian скорость 1800 бод    \~english speed 1800 bauds */
        BaudRate2400    = 2400,     /*!< \~russian скорость 2400 бод    \~english speed 2400 bauds */
        BaudRate4800    = 4800,     /*!< \~russian скорость 4800 бод    \~english speed 4800 bauds */
        BaudRate9600    = 9600,     /*!< \~russian скорость 9600 бод    \~english speed 9600 bauds */
        BaudRate14400   = 14400,    /*!< \~russian скорость 14400 бод   \~english speed 14400 bauds */
        BaudRate19200   = 19200,    /*!< \~russian скорость 19200 бод   \~english speed 19200 bauds */
        BaudRate38400   = 38400,    /*!< \~russian скорость 38400 бод   \~english speed 38400 bauds */
        BaudRate56000   = 56000,    /*!< \~russian скорость 56000 бод   \~english speed 56000 bauds */
        BaudRate57600   = 57600,    /*!< \~russian скорость 57600 бод   \~english speed 57600 bauds */
        BaudRate76800   = 76800,    /*!< \~russian скорость 76800 бод   \~english speed 76800 bauds */
        BaudRate115200  = 115200,   /*!< \~russian скорость 115200 бод  \~english speed 115200 bauds */
        BaudRate128000  = 128000,   /*!< \~russian скорость 128000 бод  \~english speed 128000 bauds */
        BaudRate256000  = 256000    /*!< \~russian скорость 256000 бод  \~english speed 256000 bauds */
    };
/*! \enum DataBits
\~russian В этом перечислении представлены все поддерживаемые классом \a AbstractSerial количества бит данных.
\~english In this enumeration of all supporting classes \a AbstractSerial number of bits of data.
*/
    enum DataBits {
        DataBits5   = 5,    /*!< \~russian 5 бит данных \~english 5 data bits */
        DataBits6   = 6,    /*!< \~russian 6 бит данных \~english 6 data bits */
        DataBits7   = 7,    /*!< \~russian 7 бит данных \~english 7 data bits */
        DataBits8   = 8     /*!< \~russian 8 бит данных \~english 8 data bits */
    };
/*! \enum Parity
\~russian В этом перечислении представлены все поддерживаемые классом \a AbstractSerial типы контроля паритета.
\~english In this enumeration of all supporting classes \a AbstractSerial types of control parity.
*/
    enum Parity {
        ParityNone  = 1,    /*!< \~russian без контроля четности    \~english parity off (none) */
        ParityOdd   = 2,    /*!< \~russian паритет "нечет"          \~english odd parity */
        ParityEven  = 3,    /*!< \~russian паритет "чет"            \~english even parity */
        ParityMark  = 4,    /*!< \~russian паритет "маркер"         \~english mark parity */
        ParitySpace = 5     /*!< \~russian паритет "пробел"         \~english space parity */
    };
/*! \enum StopBits
\~russian В этом перечислении представлены все поддерживаемые классом \a AbstractSerial количества стоп бит.
\~english In this enumeration of all supporting classes \ a AbstractSerial number of stop bits.
*/
    enum StopBits {
        StopBits1   = 1,    /*!< \~russian один стоп бит        \~english one stop bit */
        StopBits1_5 = 15,   /*!< \~russian полтора стоп бита    \~english half stop bit */
        StopBits2   = 2     /*!< \~russian два стоп бита        \~english two stop bit */
    };
/*! \enum Flow
\~russian В этом перечислении представлены все поддерживаемые классом \a AbstractSerial режимы управления потоком.
\~english In this enumeration of all supporting classes \a AbstractSerial modes of flow control.
*/
    enum Flow {
        FlowControlOff      = 1,    /*!< \~russian управление потоком отключено     \~english flow control off */
        FlowControlHardware = 2,    /*!< \~russian управление потоком аппаратное    \~english flow control hardware */
        FlowControlXonXoff  = 3     /*!< \~russian управление потоком Xon/Xoff      \~english flow control Xon/Xoff */
    };
/*! \enum Status
\~russian В этом перечислении представлены все поддерживаемые классом \a AbstractSerial статусы работы.
\~english   In this enumeration of all supporting classes \a AbstractSerial job status.
*/
    enum Status {
        /* group of "SUCESS STATES" */
        ENone                   = 0,    /*!< \~russian нет ошибок                                       \~english no errors */
        ENoneOpen               = 1,    /*!< \~russian открыто без ошибок                               \~english open without errors */
        ENoneClose              = 2,    /*!< \~russian закрыто без ошибок                               \~english closed without errors */
        ENoneSetBaudRate        = 3,    /*!< \~russian скорость установлена без ошибок                  \~english speed is set correctly */
        ENoneSetParity          = 4,    /*!< \~russian паритет установлен без ошибок                    \~english parity set correctly */
        ENoneSetDataBits        = 5,    /*!< \~russian биты данных установлены без ошибок               \~english data bits are installed correctly */
        ENoneSetStopBits        = 6,    /*!< \~russian стоп-биты установлены без ошибок                 \~english stop bits are set correctly */
        ENoneSetFlow            = 7,    /*!< \~russian управление потоком установлено без ошибок        \~english flow control is set correctly */
        ENoneSetCharTimeout     = 8,    /*!< \~russian интервал ожидания символа установлен без ошибок  \~english timed character set without errors */
        // 9-14 reserved
        /* Groups of "ERROR STATES" */
        //group of "OPEN"
        EOpen                       = 15,   /*!< \~russian ошибка при открытии                                      \~english error opening */
        EDeviceIsNotOpen            = 16,   /*!< \~russian устройство еще не открыто                                \~english device is not open */
        EOpenModeUnsupported        = 17,   /*!< \~russian режим открытия не поддерживается                         \~english open mode is not supported */
        EOpenModeUndefined          = 18,   /*!< \~russian режим открытия неопределен                               \~english open mode is undefined */
        EOpenInvalidFD              = 19,   /*!< \~russian недействительный дескриптор                              \~english invalid handle */
        EOpenOldSettingsNotSaved    = 20,   /*!< \~russian ошибка сохранения старых параметров при открытии         \~english problem of preserving the old settings when you open */
        EOpenGetCurrentSettings     = 21,   /*!< \~russian ошибка получения текущих параметров при открытии         \~english error obtaining the current settings when you open */
        EOpenSetDefaultSettings     = 22,   /*!< \~russian ошибка установки параметров по умолчанию при открытии    \~english error installing the default settings when you open */
        EDeviceIsOpen               = 23,   /*!< \~russian устройство уже открыто                                   \~english device is already open */
        //group of "CLOSE"
        ECloseSetOldSettings    = 24,   /*!< \~russian ошибка сохранения старых параметров при закрытии \~english problem of preserving the old settings when you close */
        ECloseFD                = 25,   /*!< \~russian ошибка при закрытии дескриптора                  \~english error when closing the descriptor */
        EClose                  = 26,   /*!< \~russian ошибка при закрытии                              \~english error when closing (general) */
        // 27-31 reserved
        //group of "SETTINGS"
        ESetBaudRate            = 32,   /*!< \~russian ошибка при установке скорости                    \~english error when installing speed */
        ESetDataBits            = 33,   /*!< \~russian ошибка при установке кол-ва бит данных           \~english error when installing count data bits */
        ESetParity              = 34,   /*!< \~russian ошибка при установке паритета                    \~english error when installing parity */
        ESetStopBits            = 35,   /*!< \~russian ошибка при установке кол-ва стоп бит             \~english error when installing count stop bit */
        ESetFlowControl         = 36,   /*!< \~russian ошибка при установке управления потоком          \~english error when installing flow control */
        ESetCharIntervalTimeout = 37,   /*!< \~russian ошибка при установке интервала ожидания символа  \~english rror when installing the timeout symbol */
        // 38-39 reserved
        //group of "CONTROL"
        EBytesAvailable         = 40,   /*!< \~russian ошибка при получении байт готовых для чтения             \~english failed to get a count bytes ready to read */
        ESetDtr                 = 41,   /*!< \~russian ошибка при установке DTR                                 \~english error when installing DTR */
        ESetRts                 = 42,   /*!< \~russian ошибка при установке RTS                                 \~english error when installing RTS */
        ELineStatus             = 43,   /*!< \~russian ошибка при получении статусов линий                      \~english error getting status lines */
        EWaitReadyReadIO        = 44,   /*!< \~russian ошибка ввода/вывода при ожидании приема данных           \~english I/O error when waiting for data reception */
        EWaitReadyReadTimeout   = 45,   /*!< \~russian ошибка истечения времени при ожидании приема данных      \~english error expiration time for waiting to receive data */
        EWaitReadyWriteIO       = 46,   /*!< \~russian ошибка ввода/вывода при ожидании передачи данных         \~english I/O error when waiting for data */
        EWaitReadyWriteTimeout  = 47,   /*!< \~russian ошибка истечения времени при ожидании передачи данных    \~english error when waiting for the expiration time data */
        EReadDataIO             = 48,   /*!< \~russian ошибка чтения данных                                     \~english error reading data */
        EWriteDataIO            = 49,   /*!< \~russian ошибка передачи данных                                   \~english error data */
        EFlush                  = 50    /*!< \~russian ошибка при очистки очереди буферов                       \~english error when clearing the queue buffers */
        // 51-55 reserved
    };
/*! \enum LineStatus
\~russian В этом перечислении представлены все поддерживаемые классом \a AbstractSerial состояния линий порта: CTS, DSR, DCD, RI, RTS, DTR, ST, SR (см. стандарт RS-232 и т.п.)
\~english In this enumeration of all supporting classes \a AbstractSerial state lines of port: CTS, DSR, DCD, RI, RTS, DTR, ST, SR (see RS-232 standard, etc.)
*/
    enum LineStatus {
        lsCTS   = 0x01,
        lsDSR   = 0x02,
        lsDCD   = 0x04,
        lsRI    = 0x08,
        lsRTS   = 0x10,
        lsDTR   = 0x20,
        lsST    = 0x40,
        lsSR    = 0x80
    };


    explicit AbstractSerial(QObject *parent = 0);
    virtual ~AbstractSerial();

    void setDeviceName(const QString &deviceName);
    QString deviceName() const;

    bool isValid() const;

    //baud rate
    bool setBaudRate(BaudRate baudRate);
    bool setBaudRate(const QString &baudRate);
    QString baudRate() const;
    QStringList listBaudRate() const;
    //data bits
    bool setDataBits(DataBits dataBits);
    bool setDataBits(const QString &dataBits);
    QString dataBits() const;
    QStringList listDataBits() const;
    //parity
    bool setParity(Parity parity);
    bool setParity(const QString &parity);
    QString parity() const;
    QStringList listParity() const;
    //stop bits
    bool setStopBits(StopBits stopBits);
    bool setStopBits(const QString &stopBits);
    QString stopBits() const;
    QStringList listStopBits() const;
    //flow
    bool setFlowControl(Flow flow);
    bool setFlowControl(const QString &flow);
    QString flowControl() const;
    QStringList listFlowControl() const;
    //CharIntervalTimeout
    bool setCharIntervalTimeout(int msecs = 10);
    int charIntervalTimeout() const;
    //Lines statuses
    bool setDtr(bool set);
    bool setRts(bool set);
    ulong lineStatus();

    // from public QIODevice
    bool open(OpenMode mode);
    void close();
    bool flush();
    bool reset();

    qint64 bytesAvailable() const;

    bool isSequential() const;

    bool waitForReadyRead(int msecs = 5000);
    bool waitForBytesWritten(int msecs = 5000);

    //Turns the emit signal change of status (state) devices
    void enableEmitStatus(bool enable);

protected:
    AbstractSerialPrivate * const d_ptr;
    // from protected QIODevice
    qint64 readData(char *data, qint64 maxSize);
    qint64 writeData(const char *data, qint64 maxSize);

private:
    Q_DECLARE_PRIVATE(AbstractSerial)
    Q_DISABLE_COPY(AbstractSerial)

    Q_PRIVATE_SLOT(d_func(), bool canReadNotification())
    //for a human interpret
    QHash<QString, AbstractSerial::BaudRate> m_baudRateHash;
    QHash<QString, AbstractSerial::DataBits> m_dataBitsHash;
    QHash<QString, AbstractSerial::Parity> m_parityHash;
    QHash<QString, AbstractSerial::StopBits> m_stopBitsHash;
    QHash<QString, AbstractSerial::Flow> m_flowHash;
    void initialiseHash();
    //from params types to string types
    QString statusToString(Status val) const;

    void emitStatusString(Status status);
    bool canEmitStatusString() const;
};

class AbstractSerialEngine;
class AbstractSerialPrivate
{
    Q_DECLARE_PUBLIC(AbstractSerial)
public:
    AbstractSerialPrivate();
    virtual ~AbstractSerialPrivate();

    bool canReadNotification();

    bool waitForReadyReadCalled;

    bool emittedReadyRead;
    bool emittedBytesWritten;
    bool emittedStatus;

    AbstractSerialEngine *serialEngine;

    bool initSerialLayer();
    void resetSerialLayer();

    void setupSerialNotifiers();
    void enableSerialNotifiers(bool enable);

    AbstractSerial *q_ptr;
};

#endif // ABSTRACTSERIAL_H
