/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun Sep 19 14:55:46 2010
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
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QPlainTextEdit *textEdit4B;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QPlainTextEdit *textEdit5B;
    QGraphicsView *graphicsView;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(521, 459);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setWordWrap(true);

        verticalLayout_3->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setBaseSize(QSize(0, 0));

        verticalLayout_2->addWidget(label_3);

        textEdit4B = new QPlainTextEdit(centralWidget);
        textEdit4B->setObjectName(QString::fromUtf8("textEdit4B"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textEdit4B->sizePolicy().hasHeightForWidth());
        textEdit4B->setSizePolicy(sizePolicy1);
        textEdit4B->setBaseSize(QSize(0, 0));
        textEdit4B->setReadOnly(true);

        verticalLayout_2->addWidget(textEdit4B);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setBaseSize(QSize(0, 0));

        verticalLayout->addWidget(label_4);

        textEdit5B = new QPlainTextEdit(centralWidget);
        textEdit5B->setObjectName(QString::fromUtf8("textEdit5B"));
        sizePolicy1.setHeightForWidth(textEdit5B->sizePolicy().hasHeightForWidth());
        textEdit5B->setSizePolicy(sizePolicy1);
        textEdit5B->setBaseSize(QSize(0, 0));
        textEdit5B->setReadOnly(true);

        verticalLayout->addWidget(textEdit5B);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_2);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        sizePolicy1.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy1);
        graphicsView->setMinimumSize(QSize(0, 0));

        verticalLayout_3->addWidget(graphicsView);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Lab #6 - \320\220\321\201\320\270\320\275\321\205\321\200\320\276\320\275\320\275\320\260\321\217 \321\201\321\202\320\260\321\200\321\202\321\201\321\202\320\276\320\277\320\275\320\260\321\217 \320\277\320\265\321\200\320\265\320\264\320\260\321\207\320\260", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\260\321\200\321\202\321\201\321\202\320\276\320\277\320\275\320\276\320\271 \320\260\321\201\320\270\320\275\321\205\321\200\320\276\320\275\320\275\320\276\320\271 \320\277\320\265\321\200\320\265\320\264\320\260\321\207\320\265\320\271 \320\277\321\200\320\265\320\264\321\201\321\202\320\260\320\262\320\270\321\202\321\214 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202 \321\207\320\270\321\201\320\273\320\260 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217.", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "\320\246\320\270\321\204\321\200\320\276\320\262\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265:", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("MainWindow", "211191", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "4B-\320\272\320\276\320\264:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "5B-\320\272\320\276\320\264:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
