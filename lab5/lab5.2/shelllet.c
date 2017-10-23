#include "cmdopt.h"
#include <stdio.h>
#include <string.h>

int main()
{
    LinkedList *l = NULL;
    initMenuData(&l);
    char cmd[128];
    printf("**********Shelllet Running**********\n");
    while (1)
    {
        printf(">>>");
        scanf("%s", cmd);
        CmdNode *p = findCmd(l, cmd);
        if (p != NULL && p->handler != NULL)
            p->handler();
    }
    return 0;
}