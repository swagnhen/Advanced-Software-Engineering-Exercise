#include "cmdopt.h"
#include <stdio.h>
#include <string.h>

int main(){
    char cmd[128];
    printf("**********Shelllet Running**********\n");
    while (1)
    {
        printf(">>>");
        scanf("%s", cmd);
        if (strcmp(cmd, "hello") == 0)
        {
            cmdHello();
        }
        else if (strcmp(cmd, "showuid") == 0)
        {
            cmdShowUID();
        }
        else if (strcmp(cmd, "add") == 0)
        {
            cmdAdd();
        }
        else if (strcmp(cmd, "minus") == 0)
        {
            cmdMinus();
        }
        else if (strcmp(cmd, "multiply") == 0)
        {
            cmdMultiply();
        }
        else if (strcmp(cmd, "divide") == 0)
        {
            cmdDivide();
        }
        else if (strcmp(cmd, "help") == 0)
        {
            cmdHelp();
        }
        else if (strcmp(cmd, "quit") == 0)
        {
            cmdQuit();
        }
        else
        {
            cmdElse();
        }
    }
    return 0;
}