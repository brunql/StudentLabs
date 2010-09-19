/*
 * fsm_tablemodel.cpp
 *
 *  Created on: 13.09.2010
 *      Author: brunql
 *     Project: FSM
 */


#include "fsm_tablemodel.h"
#include <QDebug>
#include <QtGui>

#include "fsmcmd.h" // FsmCmdOut struct (q-cmd, v-out)


// Simple macro, just for fill robot (FSM)
#define q(n) (n-1)

int FSM_TableModel::robot[5][2][2] = {
    // Variant #20
    {{q(4),0}, {q(3),1}},
    {{q(1),1}, {q(4),0}},
    {{q(2),1}, {q(1),0}},
    {{q(3),0}, {q(2),1}},
    {{q(3),0}, {q(2),1}}
};

QList<FsmCmdOut> test;

FSM_TableModel::FSM_TableModel(QObject *parent) : QAbstractTableModel(parent)
{
    lastStateFSM = 0;
    lastInputBitFSM = 0;

    // TODO: Придумать структуру удобную для хранения КА
//    test.append(FsmCmdOut(0,1));
}

int FSM_TableModel::rowCount(const QModelIndex &parent) const
{
    return 5;
}

int FSM_TableModel::columnCount(const QModelIndex &parent) const
{
    return 2;
}

QVariant FSM_TableModel::data(const QModelIndex &index, int role) const
{
    if(role != 0){
        return QVariant();
    }

    return QVariant("q" + QString::number(robot[index.row()][index.column()][NEXT_STATE]+1) + "," +
                    QString::number(robot[index.row()][index.column()][OUT_VALUE]));
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
            result += QString::number(robot[state][input_bit][OUT_VALUE]);
            state = robot[state][input_bit][NEXT_STATE];
        }else{
            return "error";
        }
    }
    lastStateFSM = state;
    lastInputBitFSM = input_bit;

    return result;
}

void FSM_TableModel::removeUnreachableStates()
{
    for(int i=0; i<5; i++){
        robot[i][0][0];
    }
}



















