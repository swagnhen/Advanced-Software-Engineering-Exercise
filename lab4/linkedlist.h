#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_
#define FAILURE (-1)

typedef struct Node
{
    struct Node *next;
} Node;

typedef struct LinkedList
{
    Node *head;
    Node *tail;
    int len;
} LinkedList;

LinkedList *initLinkedList();

int delLinkedList(LinkedList *l);

int addNode(LinkedList *l, Node *n);

int delNode(LinkedList *l, Node *n);

Node *getHeadNode(LinkedList *l);

Node *getNextNode(LinkedList *l, Node *n);

#endif