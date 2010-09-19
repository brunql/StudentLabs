/*
 * main.cpp
 *
 *  Created on: 19.09.2010
 *      Author: brunql
 *     Project: Lab6. Universal Asynchronous Reciver Transmitter
 *     Problem: Visualize UART (Bodo 5B, 1 stop) transmition day of birthday date
 */

#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
