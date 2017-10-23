#ifndef _CMDOPT_H_
#define _CMDOPT_H_

#include "linkedlist.h"

typedef struct CmdNode
{
    Node *next;
    char *cmd;
    int (*handler)();
} CmdNode;

int initMenuData(LinkedList **l);

int searchOperation(Node *n, char *cmd);

CmdNode *findCmd(LinkedList *head, char *cmd);

void cmdAdd();

void cmdMinus();

void cmdMultiply();

void cmdDivide();

void cmdHello();

void cmdQuit();

void cmdShowUID();

void cmdHelp();

void cmdElse();

#endif