/*
 * main.cpp
 *
 *  Created on: 2.10.2010
 *      Author: brunql
 *     Project: Lab 8. Sync impulses
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
