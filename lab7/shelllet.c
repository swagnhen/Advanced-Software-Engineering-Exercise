#include "cmdopt.h"
#include <stdio.h>
#include <string.h>

int test(int argc, char *argv[]){
    printf(">>>Test success\n");
    return 0;
}

int main()
{
    LinkedList *l = NULL;
    initMenuData(&l);
    ShellletConfig(l, "test", test);
    ExecuteShelllet(l);
    return 0;
}