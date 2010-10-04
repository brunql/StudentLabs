/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Oct 4 18:04:23 2010
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
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLabel *label;
    QVBoxLayout *verticalLayout_4;
    QGraphicsView *graphViewImage;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelScale;
    QSlider *horSliderScale;
    QLabel *labelScaleXY;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QGraphicsView *graphViewOscilloscope;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonStartStop;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(677, 529);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout_3->addWidget(label_3);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label->setWordWrap(true);

        verticalLayout_3->addWidget(label);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        graphViewImage = new QGraphicsView(centralwidget);
        graphViewImage->setObjectName(QString::fromUtf8("graphViewImage"));

        verticalLayout_4->addWidget(graphViewImage);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelScale = new QLabel(centralwidget);
        labelScale->setObjectName(QString::fromUtf8("labelScale"));

        horizontalLayout_2->addWidget(labelScale);

        horSliderScale = new QSlider(centralwidget);
        horSliderScale->setObjectName(QString::fromUtf8("horSliderScale"));
        horSliderScale->setMinimum(1);
        horSliderScale->setMaximum(10);
        horSliderScale->setSingleStep(1);
        horSliderScale->setPageStep(1);
        horSliderScale->setValue(1);
        horSliderScale->setTracking(true);
        horSliderScale->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horSliderScale);

        labelScaleXY = new QLabel(centralwidget);
        labelScaleXY->setObjectName(QString::fromUtf8("labelScaleXY"));
        labelScaleXY->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labelScaleXY);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout);


        horizontalLayout_3->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        graphViewOscilloscope = new QGraphicsView(centralwidget);
        graphViewOscilloscope->setObjectName(QString::fromUtf8("graphViewOscilloscope"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(graphViewOscilloscope->sizePolicy().hasHeightForWidth());
        graphViewOscilloscope->setSizePolicy(sizePolicy1);
        graphViewOscilloscope->setMinimumSize(QSize(0, 10));
        graphViewOscilloscope->setMaximumSize(QSize(16777215, 200));

        verticalLayout_2->addWidget(graphViewOscilloscope);


        verticalLayout_5->addLayout(verticalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonStartStop = new QPushButton(centralwidget);
        pushButtonStartStop->setObjectName(QString::fromUtf8("pushButtonStartStop"));

        horizontalLayout->addWidget(pushButtonStartStop);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_5->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Lab #11. \320\236\321\206\320\270\321\204\321\200\320\276\320\262\320\272\320\260 \320\260\320\275\320\260\320\273\320\276\320\263\320\276\320\262\320\276\320\263\320\276 \320\262\320\270\320\264\320\265\320\276 \321\201\320\270\320\263\320\275\320\260\320\273\320\260 \321\201 \320\272\320\260\320\274\320\265\321\200\321\213", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\264\320\265\320\262\320\260\320\271\321\201\320\260", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">MCU: <span style=\" font-weight:600;\">LPC 1343</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Core: <span style=\" font-weight:600;\">ARM Cortex M3</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">System clock: <span style=\" font-weight:600;\">72 MHz</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">UART: <"
                        "span style=\" font-weight:600;\">115200 bit/s</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">ADC: <span style=\" font-weight:600;\">8 bit / 9 clocks</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        labelScale->setText(QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261:", 0, QApplication::UnicodeUTF8));
        labelScaleXY->setText(QApplication::translate("MainWindow", "00x00", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "\320\241\320\270\320\263\320\275\320\260\320\273 \321\201 \320\272\320\260\320\274\320\265\321\200\321\213", 0, QApplication::UnicodeUTF8));
        pushButtonStartStop->setText(QApplication::translate("MainWindow", "Start / Stop", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
