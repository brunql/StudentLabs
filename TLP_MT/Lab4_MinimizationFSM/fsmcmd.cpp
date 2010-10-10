/*
 * fsmcmd.cpp
 *
 *  Created on: 13.09.2010
 *      Author: brunql
 *     Project: FSM
 */

#include "fsmcmd.h"

FsmCmdOut::FsmCmdOut()
{
    cmd = 0;
    out = 0;
};

FsmCmdOut::FsmCmdOut(int cmd, int out)
{
    this->cmd = cmd;
    this->out = out;
}
