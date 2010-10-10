/*
 * fsmcmdline.cpp
 *
 *  Created on: 14.09.2010
 *      Author: brunql
 *     Project: FSM
 */

#include "fsmcmdline.h"
#include "QtDebug"

FsmCmdLine::FsmCmdLine()
{
    this->co1 = new FsmCmdOut();
    this->co2 = new FsmCmdOut();
}

FsmCmdLine::FsmCmdLine(FsmCmdOut *co1, FsmCmdOut *co2)
{
    this->co1 = co1;
    this->co2 = co2;
}

FsmCmdLine::FsmCmdLine(int cmd1, int out1, int cmd2, int out2)
{
    this->co1 = new FsmCmdOut(cmd1, out1);
    this->co2 = new FsmCmdOut(cmd2, out2);
}

FsmCmdOut * FsmCmdLine::operator[] (int index)
{
    if(index == 0){
        return co1;
    }else if(index == 1){
        return co2;
    }else{
        qDebug() << "Error in FsmCmdOut * FsmCmdLine::operator[] (int index): index ==" << index;
    }
    return new FsmCmdOut();
}
