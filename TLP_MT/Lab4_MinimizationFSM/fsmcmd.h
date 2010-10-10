/*
 * fsmcmd.h
 *
 *  Created on: 14.09.2010
 *      Author: brunql
 *     Project: FSM
 */

#ifndef FSMCMD_H
#define FSMCMD_H

struct FsmCmdOut
{
    FsmCmdOut();
    FsmCmdOut(int cmd, int out);

    int cmd; // q
    int out; // v
};

#endif // FSMCMD_H
