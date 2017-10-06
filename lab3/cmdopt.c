#include "cmdopt.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void cmdAdd(){
    int a, b;
    printf(">>>");
    scanf("%i", &a);
    printf(">>>");
    scanf("%i", &b);
    printf(">>>%i\n", a+b);
}

void cmdMinus(){
    int a, b;
    printf(">>>");
    scanf("%i", &a);
    printf(">>>");
    scanf("%i", &b);
    printf(">>>%i\n", a-b);
}

void cmdMultiply(){
    int a, b;
    printf(">>>");
    scanf("%i", &a);
    printf(">>>");
    scanf("%i", &b);
    printf(">>>%i\n", a*b);
}

void cmdDivide(){
    int a, b;
    printf(">>>");
    scanf("%i", &a);
    printf(">>>");
    scanf("%i", &b);
    printf(">>>%i\n", a/b);
}

void cmdHello(){
    printf(">>>Welcome to shelllet!\n");
}

void cmdQuit(){
    printf("**********Shelllet End**********\n");
    exit(0);
}

void cmdShowUID(){
    printf(">>>UID: %i\n", getuid());
}

void cmdHelp(){
    printf("|help\n");
    printf("|hello\n");
    printf("|add\n");
    printf("|minus\n");
    printf("|multiply\n");
    printf("|divide\n");
    printf("|showuid\n");
    printf("|quit\n");
}

void cmdElse(){
    printf(">>>Wrong Commend\n");
}