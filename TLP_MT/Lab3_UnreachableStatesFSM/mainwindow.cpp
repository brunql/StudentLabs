/*
 * mainwindow.cpp
 *
 *  Created on: 13.09.2010
 *      Author: brunql
 *     Project: Lab3. FSM
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QtGui"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->lineEditInput, SIGNAL(textChanged(QString)), this, SLOT(lineInputEditing()));
    connect(ui->lineEditInputDigits, SIGNAL(textChanged(QString)), this, SLOT(lineInputDigitsEditing()));
    connect(ui->btnRemoveUnreachableStates, SIGNAL(clicked()), this, SLOT(btnRemoveUnreachableStatesClicked()));

    fsm_table = new FSM_TableModel(this);
    ui->tableView->setModel(fsm_table);
    lineInputEditing();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::showEvent(QShowEvent *)
{
    resizeEvent(0);
    int screenW = QApplication::desktop()->screenGeometry().width();
    int screenH = QApplication::desktop()->screenGeometry().height();

    this->move( screenW/2 - this->width()/2,
            screenH/2 - this->height()/2 );
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    int widthColumns =  ui->tableView->columnWidth(0) + ui->tableView->columnWidth(1);
    ui->tableView->setColumnWidth(0, widthColumns/2);
    ui->tableView->setColumnWidth(1, widthColumns/2);
}


void MainWindow::lineInputEditing()
{
    QString binaryInput = ui->lineEditInput->text();
    QString result = fsm_table->FSM(binaryInput);
    if(result != "error"){
        // Set result
        ui->lineEditOutput->setText( result );

        // Convert binary simbols to digits 4 bin to 1 digit (1,2...f)
        QString digits = "";
        int bit = 3;
        int digit = 0;
        for(int i=0; i<result.length(); i++){
            if(result[i].digitValue() == 1){
                digit |= (1<<bit);
            }
            if(--bit < 0){
                bit = 3;
                digits += QString::number(digit, 16).toUpper(); // out in hex
                digit = 0;
            }
        }
        ui->lineEditOutputDigits->setText( digits );

        // Makes white background of lineEditInput:
        QPalette pal = ui->lineEditInput->palette();
        pal.setBrush(ui->lineEditInput->backgroundRole(), QBrush(Qt::white));
        ui->lineEditInput->setPalette(pal);
    }else{
        ui->lineEditOutput->setText( "" );
        ui->lineEditOutputDigits->setText( "" );
        // Error. Makes red background of lineEditInput:
        QPalette pal = ui->lineEditInput->palette();
        pal.setBrush(ui->lineEditInput->backgroundRole(), QBrush(Qt::red));
        ui->lineEditInput->setPalette(pal);
    }

    ui->tableView->selectRow(fsm_table->lastStateFSM);

}

void MainWindow::lineInputDigitsEditing()
{
    QString digits = ui->lineEditInputDigits->text();
    if(digits == ""){
        ui->lineEditInput->setText( "" );
        return;
    }

    QString binaryInput = "";

    for(int i=0; i<digits.length(); i++){
        if(digits[i].isDigit()){
            int digit = digits[i].digitValue();

            // Convert digit to binary string:
            QString bin = "";
            for(int bit=(1<<3); bit != 0; bit >>= 1){
                if(digit & bit){
                    bin += "1";
                }else{
                    bin += "0";
                }
            }
            binaryInput += bin;

        }else{
            ui->lineEditOutput->setText( "" );
            ui->lineEditOutputDigits->setText( "" );
            // Error while parse inputed digits
            QPalette pal = ui->lineEditInputDigits->palette();
            pal.setBrush(ui->lineEditInputDigits->backgroundRole(), QBrush(Qt::red));
            ui->lineEditInputDigits->setPalette(pal);
            return;
        }
    }


    // Changing text to start FSM
   ui->lineEditInput->setText(binaryInput);

   // Makes white background of lineEditInputDigits:
   QPalette pal = ui->lineEditInputDigits->palette();
   pal.setBrush(ui->lineEditInputDigits->backgroundRole(), QBrush(Qt::white));
   ui->lineEditInputDigits->setPalette(pal);
}

void MainWindow::btnRemoveUnreachableStatesClicked()
{
    fsm_table->removeUnreachableStates();
}
















