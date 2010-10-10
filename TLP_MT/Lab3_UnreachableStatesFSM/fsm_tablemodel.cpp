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


FSM_TableModel::FSM_TableModel(QObject *parent) : QAbstractTableModel(parent)
{
    lastStateFSM = 0;
    lastInputBitFSM = 0;

    fsm.append(new FsmCmdLine(q(4),0, q(3),1));
    fsm.append(new FsmCmdLine(q(1),1, q(4),0));
    fsm.append(new FsmCmdLine(q(2),1, q(1),0));
    fsm.append(new FsmCmdLine(q(3),0, q(2),1));
    fsm.append(new FsmCmdLine(q(3),0, q(2),1));
}

int FSM_TableModel::rowCount(const QModelIndex &parent) const
{
    return fsm.count();
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

    if(index.column() == 0 || index.column() == 1){
        FsmCmdOut *fsmIndex = (*fsm[index.row()])[index.column()];

        return QVariant("q" + QString::number(fsmIndex->cmd +1) + "," +
                    QString::number(fsmIndex->out));
    }else{
        qDebug() << "Error in QVariant FSM_TableModel::data(const QModelIndex &index, int role) const: index.column() ==" << index.column();        
    }
    qDebug() << "Return empty data";
    return QVariant();
}

QVariant FSM_TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{    
    if(role != 0){
        return QVariant();
    }

    if(section >= fsm.count()){
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
            result += QString::number((*fsm[state])[input_bit]->out);
            state = (*fsm[state])[input_bit]->cmd;
        }else{
            return "error";
        }
    }
    lastStateFSM = state;
    lastInputBitFSM = input_bit;

    return result;
}

QList<int> *FSM_TableModel::findReachableStates(QList<int> *reachableStates, int state)
{
    int cmdCheckMe = fsm[state]->co1->cmd;
    if(reachableStates->indexOf(cmdCheckMe) == -1){
        reachableStates->append(cmdCheckMe);
        reachableStates = findReachableStates(reachableStates, cmdCheckMe);
    }

    cmdCheckMe = fsm[state]->co2->cmd;
    if(reachableStates->indexOf(cmdCheckMe) == -1){
        reachableStates->append(cmdCheckMe);
        reachableStates = findReachableStates(reachableStates, cmdCheckMe);
    }
    return reachableStates;
}

void FSM_TableModel::removeUnreachableStates()
{
    const int firstState = 0;

    QList<int> *reachableStates = new QList<int>();
    reachableStates->append(firstState);

    reachableStates = findReachableStates(reachableStates, firstState);
    if(reachableStates->count() < fsm.count()){
        // not all FSM states are reachable
        for(int state=0; state<fsm.count(); state++){
            if(reachableStates->indexOf(state) == -1){
                fsm.removeAt(state);
            }
        }
    }else if(reachableStates->count() == fsm.count()){
        qDebug() << "All FSM states are reachable";
    }else{
        qDebug() << "Error in void FSM_TableModel::removeUnreachableStates(): reachableStates->count() > fsm.count()."
                << "reachableStates->count() ==" << reachableStates->count();
    }

    emit this->dataChanged(QModelIndex(), QModelIndex());
    emit this->headerDataChanged(Qt::Vertical, 0, fsm.count());
}









