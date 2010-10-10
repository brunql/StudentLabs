/*
 * fsmcmdline.h
 *
 *  Created on: 14.09.2010
 *      Author: brunql
 *     Project: FSM
 */

#ifndef FSMCMDLINE_H
#define FSMCMDLINE_H

#include "fsmcmd.h"

struct FsmCmdLine
{
    FsmCmdLine();
    FsmCmdLine(FsmCmdOut *co1, FsmCmdOut *co2);
    FsmCmdLine(int cmd1, int out1, int cmd2, int out2);
    FsmCmdOut * operator[] (int index);

    FsmCmdOut *co1;
    FsmCmdOut *co2;
};



#endif // FSMCMDLINE_H
