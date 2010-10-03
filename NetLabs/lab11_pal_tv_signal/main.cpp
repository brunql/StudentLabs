/*
 * main.cpp
 *
 *  Created on: 25.07.2010
 *      Author: brunql
 */

#include <QtGui>
#include "main.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow mainwindow;
    mainwindow.show();

    return app.exec();
}
