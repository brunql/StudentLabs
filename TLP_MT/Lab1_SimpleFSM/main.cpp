/*
 * main.cpp
 *
 *  Created on: 13.09.2010
 *      Author: brunql
 *     Project: Lab1. Simple FSM
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
