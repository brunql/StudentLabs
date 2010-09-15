/*
 * main.cpp
 *
 *  Created on: 15.09.2010
 *      Author: brunql
 *     Project: Lab4. Modem: 4B code -> FMO code -> Phase modulation
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
