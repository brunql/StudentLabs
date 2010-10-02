/*
 * main.cpp
 *
 *  Created on: 2.10.2010
 *      Author: brunql
 *     Project: Lab 9. Satelite cadres show must go on
 */


#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();
    return a.exec();
}
