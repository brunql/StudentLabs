/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun Sep 12 18:10:55 2010
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
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit4BManchester;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEditMlt3;
    QHBoxLayout *horizontalLayout_3;
    QPlainTextEdit *textEdit4B;
    QPlainTextEdit *textEditMlt3;
    QGraphicsView *graphicsView;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 400);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setWordWrap(true);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit4BManchester = new QLineEdit(centralWidget);
        lineEdit4BManchester->setObjectName(QString::fromUtf8("lineEdit4BManchester"));

        horizontalLayout->addWidget(lineEdit4BManchester);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lineEditMlt3 = new QLineEdit(centralWidget);
        lineEditMlt3->setObjectName(QString::fromUtf8("lineEditMlt3"));

        horizontalLayout_2->addWidget(lineEditMlt3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        textEdit4B = new QPlainTextEdit(centralWidget);
        textEdit4B->setObjectName(QString::fromUtf8("textEdit4B"));

        horizontalLayout_3->addWidget(textEdit4B);

        textEditMlt3 = new QPlainTextEdit(centralWidget);
        textEditMlt3->setObjectName(QString::fromUtf8("textEditMlt3"));

        horizontalLayout_3->addWidget(textEditMlt3);


        verticalLayout->addLayout(horizontalLayout_3);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout->addWidget(graphicsView);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Lab 3 - \320\234\320\260\320\275\321\207\320\265\321\201\321\202\320\265\321\200\321\201\320\272\320\270\320\271 \320\270 \320\234\320\233\320\242-3 \320\272\320\276\320\264", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "\320\222\320\260\321\200\320\270\320\260\320\275\321\202 3. \320\237\321\200\320\265\320\264\321\201\321\202\320\260\320\262\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\321\207\320\265\321\201\320\272\320\270 \320\264\320\260\321\202\321\203 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217 \320\262 \320\261\320\270\320\275\320\260\321\200\320\275\320\276\320\274 \320\272\320\276\320\264\320\265 4\320\222 \320\270 \320\277\320\265\321\200\320\265\320\262\320\265\321\201\321\202\320\270 \320\262 \320\274\320\260\320\275\321\207\320\265\321\201\321\202\320\265\321\200\321\201\320\272\320\270\320\271 \320\272\320\276\320\264 \321\201 \320\277\321\200\320\276\320\264\320\276\320\273\320\266\320\265\320\275\320\270\320\265\320\274 \321\201\320\262\320\276\320\265\320\271 \321\204\320\260\320\274\320\270\320\273\320\270\320\270 \320\234\320\233\320\242-3 \320\272\320\276\320\264\320\276\320\274.", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217 (4B \320\270 \320\274\320\260\320\275\321\207\320\265\321\201\321\202\320\265\321\200\321\201\320\272\320\270\320\271):", 0, QApplication::UnicodeUTF8));
        lineEdit4BManchester->setText(QApplication::translate("MainWindow", "211191", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217 (\320\234\320\233\320\242-3):", 0, QApplication::UnicodeUTF8));
        lineEditMlt3->setText(QApplication::translate("MainWindow", "\320\250\320\260\321\202\320\276\321\205\320\270\320\275", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
