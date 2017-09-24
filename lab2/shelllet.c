#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    char cmd[128];
    printf("**********Shelllet Running**********\n");
    while (1)
    {
        printf(">>>");
        scanf("%s", cmd);
        if (strcmp(cmd, "hello") == 0)
        {
            printf(">>>Welcome to shelllet!\n");
        }
        else if (strcmp(cmd, "showUid") == 0)
        {
            printf(">>>UID: %i\n", getuid());
        }
        else if (strcmp(cmd, "man") == 0)
        {
            printf(">>>This is \"man\" commend\n");
        }
        else if (strcmp(cmd, "cd") == 0)
        {
            printf(">>>This is \"cd\" commend\n");
        }
        else if (strcmp(cmd, "ls") == 0)
        {
            printf(">>>This is \"ls\" commend\n");
        }
        else if (strcmp(cmd, "ipconfig") == 0)
        {
            printf(">>>This is \"ipconfig\" commend\n");
        }
        else if (strcmp(cmd, "env") == 0)
        {
            printf(">>>This is \"env\" commend\n");
        }
        else if (strcmp(cmd, "quit") == 0)
        {
            printf("**********Shelllet End**********\n");
            exit(0);
        }
        else
        {
            printf(">>>Wrong Commend\n");
        }
    }
    return 0;
}