/*
 * main.cpp
 *
 *  Created on: 12.09.2010
 *      Author: brunql
 *     Project: Lab1. Bodo codes.
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
