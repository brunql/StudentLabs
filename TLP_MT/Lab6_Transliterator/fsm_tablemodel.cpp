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



FSM_TableModel::FSM_TableModel(QObject *parent) : QAbstractTableModel(parent)
{
    lastStateFSM = 0;
    lastInputBitFSM = 0;
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



















