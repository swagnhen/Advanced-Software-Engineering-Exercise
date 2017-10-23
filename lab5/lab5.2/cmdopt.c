#include "cmdopt.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int initMenuData(LinkedList **l)
{
    *l = initLinkedList();

    CmdNode *p = (CmdNode *)malloc(sizeof(CmdNode));
    p->cmd = "add";
    p->handler = cmdAdd;
    addNode(*l, (Node *)p);

    p = (CmdNode *)malloc(sizeof(CmdNode));
    p->cmd = "minus";
    p->handler = cmdMinus;
    addNode(*l, (Node *)p);

    p = (CmdNode *)malloc(sizeof(CmdNode));
    p->cmd = "multiply";
    p->handler = cmdMultiply;
    addNode(*l, (Node *)p);

    p = (CmdNode *)malloc(sizeof(CmdNode));
    p->cmd = "divide";
    p->handler = cmdDivide;
    addNode(*l, (Node *)p);

    p = (CmdNode *)malloc(sizeof(CmdNode));
    p->cmd = "quit";
    p->handler = cmdQuit;
    addNode(*l, (Node *)p);

    p = (CmdNode *)malloc(sizeof(CmdNode));
    p->cmd = "showuid";
    p->handler = cmdShowUID;
    addNode(*l, (Node *)p);

    p = (CmdNode *)malloc(sizeof(CmdNode));
    p->cmd = "help";
    p->handler = cmdHelp;
    addNode(*l, (Node *)p);

    p = (CmdNode *)malloc(sizeof(CmdNode));
    p->cmd = "hello";
    p->handler = cmdHello;
    addNode(*l, (Node *)p);

    p = (CmdNode *)malloc(sizeof(CmdNode));
    p->cmd = "";
    p->handler = cmdElse;
    addNode(*l, (Node *)p);

    return 0;
}

int searchOperation(Node *n, char *cmd)
{
    CmdNode *p = (CmdNode *)n;
    if (strcmp(p->cmd, cmd) == 0)
    {
        return 0;
    }
    return -1;
}

CmdNode *findCmd(LinkedList *l, char *cmd)
{
    return (CmdNode *)searchNode(l, cmd, searchOperation);
}

void cmdAdd()
{
    int a, b;
    printf(">>>");
    scanf("%i", &a);
    printf(">>>");
    scanf("%i", &b);
    printf(">>>%i\n", a + b);
}

void cmdMinus()
{
    int a, b;
    printf(">>>");
    scanf("%i", &a);
    printf(">>>");
    scanf("%i", &b);
    printf(">>>%i\n", a - b);
}

void cmdMultiply()
{
    int a, b;
    printf(">>>");
    scanf("%i", &a);
    printf(">>>");
    scanf("%i", &b);
    printf(">>>%i\n", a * b);
}

void cmdDivide()
{
    int a, b;
    printf(">>>");
    scanf("%i", &a);
    printf(">>>");
    scanf("%i", &b);
    printf(">>>%i\n", a / b);
}

void cmdHello()
{
    printf(">>>Welcome to shelllet!\n");
}

void cmdQuit()
{
    printf("**********Shelllet End**********\n");
    exit(0);
}

void cmdShowUID()
{
    printf(">>>UID: %i\n", getuid());
}

void cmdHelp()
{
    printf("|help\n");
    printf("|hello\n");
    printf("|add\n");
    printf("|minus\n");
    printf("|multiply\n");
    printf("|divide\n");
    printf("|showuid\n");
    printf("|quit\n");
}

void cmdElse()
{
    printf(">>>Wrong Commend\n");
}