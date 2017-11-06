#include "cmdopt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void cmdAdd(int argc, char *argv[])
{
    int a, b;
    printf(">>>");
    scanf("%i", &a);
    printf(">>>");
    scanf("%i", &b);
    printf(">>>%i\n", a + b);
}

void cmdMinus(int argc, char *argv[])
{
    int a, b;
    printf(">>>");
    scanf("%i", &a);
    printf(">>>");
    scanf("%i", &b);
    printf(">>>%i\n", a - b);
}

void cmdMultiply(int argc, char *argv[])
{
    int a, b;
    printf(">>>");
    scanf("%i", &a);
    printf(">>>");
    scanf("%i", &b);
    printf(">>>%i\n", a * b);
}

void cmdDivide(int argc, char *argv[])
{
    int a, b;
    printf(">>>");
    scanf("%i", &a);
    printf(">>>");
    scanf("%i", &b);
    printf(">>>%i\n", a / b);
}

void cmdHello(int argc, char *argv[])
{
    printf(">>>Welcome to shelllet!\n");
}

void cmdQuit(int argc, char *argv[])
{
    printf("**********Shelllet End**********\n");
    exit(0);
}

void cmdShowUID(int argc, char *argv[])
{
    printf(">>>UID: %i\n", getuid());
}

void cmdHelp(int argc, char *argv[])
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

int ShellletConfig(LinkedList *l, char *cmd, int (*handler)())
{
    CmdNode *p = NULL;
    if (l == NULL)
    {
        return -1;
    }
    p = (CmdNode *)malloc(sizeof(CmdNode));
    p->cmd = cmd;
    p->handler = handler;
    addNode(l, (Node *)p);
    return 0;
}

void cmd2arg(int *argc, char **argv)
{
    char cmd[1024];
    char *pcmd = NULL;
    pcmd = fgets(cmd, 1024, stdin);
    if (pcmd == NULL)
        return;
    pcmd = strtok(pcmd, " ");
    while (pcmd != NULL && *argc < 32)
    {
        argv[*argc] = pcmd;
        (*argc)++;
        pcmd = strtok(NULL, " ");
    }
    if (*argc == 1)
    {
        int len = strlen(argv[0]);
        *(argv[0] + len - 1) = '\0';
    }
}

int ExecuteShelllet(LinkedList *l)
{
    int argc = 0;
    char *argv[32];
    printf("**********Shelllet Running**********\n");
    while (1)
    {
        printf(">>>");
        cmd2arg(&argc, argv);
        CmdNode *p = findCmd(l, argv[0]);
        if (p != NULL && p->handler != NULL)
            p->handler(argc, argv);
        argc = 0;
    }
    return 0;
}