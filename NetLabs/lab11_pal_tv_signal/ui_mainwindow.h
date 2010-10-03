/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun Oct 3 11:17:17 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphViewImage;
    QGraphicsView *graphViewOscilloscope;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonStartStop;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(784, 426);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        graphViewImage = new QGraphicsView(centralwidget);
        graphViewImage->setObjectName(QString::fromUtf8("graphViewImage"));

        verticalLayout->addWidget(graphViewImage);

        graphViewOscilloscope = new QGraphicsView(centralwidget);
        graphViewOscilloscope->setObjectName(QString::fromUtf8("graphViewOscilloscope"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphViewOscilloscope->sizePolicy().hasHeightForWidth());
        graphViewOscilloscope->setSizePolicy(sizePolicy);
        graphViewOscilloscope->setMinimumSize(QSize(0, 255));
        graphViewOscilloscope->setMaximumSize(QSize(16777215, 255));

        verticalLayout->addWidget(graphViewOscilloscope);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonStartStop = new QPushButton(centralwidget);
        pushButtonStartStop->setObjectName(QString::fromUtf8("pushButtonStartStop"));

        horizontalLayout->addWidget(pushButtonStartStop);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        pushButtonStartStop->setText(QApplication::translate("MainWindow", "Start / Stop", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
