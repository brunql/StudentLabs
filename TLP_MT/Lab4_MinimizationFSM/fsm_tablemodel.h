/*
 * fsm_tablemodel.h
 *
 *  Created on: 13.09.2010
 *      Author: brunql
 *     Project: FSM
 */

#ifndef FSM_TABLEMODEL_H
#define FSM_TABLEMODEL_H

#include "QAbstractTableModel"
#include "fsmcmdline.h"

class FSM_TableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    FSM_TableModel(QObject *parent);
    QString FSM(QString stream);
    void removeUnreachableStates();

protected:
    virtual int rowCount(const QModelIndex &parent) const;
    virtual int columnCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const;

public:
    int lastStateFSM;
    int lastInputBitFSM;

private:
    QList<int> *findReachableStates(QList<int> *reachableStates, int state);

    QList<FsmCmdLine*> fsm;

};

#endif // KA_TABLEMODEL_H
