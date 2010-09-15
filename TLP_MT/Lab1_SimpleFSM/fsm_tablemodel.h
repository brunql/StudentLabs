/*
 * fsm_tablemodel.h
 *
 *  Created on: 13.09.2010
 *      Author: brunql
 *     Project: Lab1. Simple FSM
 */

#ifndef FSM_TABLEMODEL_H
#define FSM_TABLEMODEL_H

#include "QAbstractTableModel"

class FSM_TableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    FSM_TableModel(QObject *parent);
    QString FSM(QString stream);

protected:
    virtual int rowCount(const QModelIndex &parent) const;
    virtual int columnCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const;

public:
    int lastStateFSM;
    int lastInputBitFSM;


private:
    static const int robot[5][2][2];
    static const int NEXT_STATE = 0;
    static const int OUT_VALUE  = 1;
};

#endif // KA_TABLEMODEL_H
