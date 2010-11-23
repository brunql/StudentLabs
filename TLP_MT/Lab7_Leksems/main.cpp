/*
 * main.cpp
 *
 *  Created on: 13.09.2010
 *      Author: brunql
 *     Project: Lab1. Simple FSM
 */

#include <QtCore>

int main(int argc, char *argv[])
{   
    QList<QString> leksems;
    leksems.append("BOOLEAN");
    leksems.append("REPEAT");
    leksems.append("READLN");
    leksems.append("WRITELN");

    QList<QString> slogs;
    QList<QChar> chars;

    for(int i=0; i<leksems.count(); i++){
        for(int c=0; c<leksems[i].length(); c++){
            if(!chars.contains(leksems[i][c])){
                chars.append(leksems[i][c]);
            }
            if(!slogs.contains(leksems[i].left(c+1))){
                slogs.append(leksems[i].left(c+1));
            }
        }
    }
    QString table = "\nСлоги\t";
    for(int i=0; i<chars.count(); i++){
        table += QString(chars[i]) + "\t";
    }
    table += "_|_\n";

    for(int slog=0; slog<slogs.count(); slog++){
        QString findLeksem = "";
        table += slogs[slog] + "\t";
        for(int i=0; i<chars.count(); i++){
            QString check = slogs[slog];
            check.append(chars[i]);
            if(slogs.contains(check)){
                table += check + "\t";
                if(leksems.contains(check)){
                    findLeksem = check;
                }
            }else{
                table += "err \t";
            }           
        }
        if(findLeksem != ""){
            table += "yes\n";
        }else{
            table += "no\n";
        }
    }

    qDebug() << table;

    return 0;
}
