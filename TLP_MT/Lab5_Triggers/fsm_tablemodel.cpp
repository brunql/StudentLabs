/*
 * fsm_tablemodel.cpp
 *
 *  Created on: 13.09.2010
 *      Author: brunql
 *     Project: Lab1. Simple FSM
 */


#include "fsm_tablemodel.h"
#include <QDebug>
#include <QtGui>


// Simple macro, just for fill robot (FSM)
#define q(n) (n-1)

const int FSM_TableModel::fsm[5][2][2] = {
        {{q(4),0}, {q(3),1}},
        {{q(1),1}, {q(4),0}},
        {{q(2),1}, {q(1),0}},
        {{q(3),0}, {q(2),1}},
        {{q(3),0}, {q(2),1}}
};

FSM_TableModel::FSM_TableModel(QObject *parent) : QAbstractTableModel(parent)
{
    lastStateFSM = 0;
    lastInputBitFSM = 0;

    QString out = "a\tqt-1\tqt\tR\tS\tV\n";

    for(int a=0; a<2; a++){
        for(int qt_prev=0; qt_prev<5; qt_prev++){
            int r = (fsm[qt_prev][a][OUT_VALUE] == 0)?1:0, s = (fsm[qt_prev][a][OUT_VALUE] == 1)?1:0;
            out += QString::number(a) + "\t" +
                   QString::number(qt_prev) + "\t" +
                   QString::number(fsm[qt_prev][a][NEXT_STATE]) + "\t" +
                   QString::number(r) + "\t" +
                   QString::number(s) + "\t" +
                   QString::number(fsm[qt_prev][a][OUT_VALUE]) + "\n";
        }
    }
    qDebug() << out;

}

int FSM_TableModel::rowCount(const QModelIndex &) const
{
    return 5;
}

int FSM_TableModel::columnCount(const QModelIndex &) const
{
    return 2;
}

QVariant FSM_TableModel::data(const QModelIndex &index, int role) const
{
    if(role != 0){
        return QVariant();
    }

    return QVariant("q" + QString::number(fsm[index.row()][index.column()][NEXT_STATE]+1) + "," +
                    QString::number(fsm[index.row()][index.column()][OUT_VALUE]));
}

QVariant FSM_TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{    
    if(role != 0){
        return QVariant();
    }

    // section == index row or column
    if(orientation == Qt::Horizontal){ // rows
        return QVariant(QString::number(section));
    }else if(orientation == Qt::Vertical){ // columns
        return QVariant("q" + QString::number(section+1));
    }

    return QVariant();
}



QString FSM_TableModel::FSM(QString stream)
{
    QString result = "";
    int state = 0; // FSM start state
    int input_bit = 0;
    for(int i=0; i<stream.length(); i++){
        if(stream[i].isDigit() && (stream[i] == '1' || stream[i] == '0')){
            input_bit = stream[i].digitValue(); // 0 or 1
            result += QString::number(fsm[state][input_bit][OUT_VALUE]);
            state = fsm[state][input_bit][NEXT_STATE];
        }else{
            return "error";
        }
    }
    lastStateFSM = state;
    lastInputBitFSM = input_bit;

    return result;
}



















