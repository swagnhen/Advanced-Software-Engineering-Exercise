#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

LinkedList *initLinkedList()
{
    LinkedList *l = (LinkedList *)malloc(sizeof(LinkedList));
    if (l == NULL)
    {
        return NULL;
    }
    l->head = NULL;
    l->tail = NULL;
    l->len = 0;
    return l;
}

int delLinkedList(LinkedList *l)
{
    if (l == NULL)
    {
        return -1;
    }
    while (l->head != NULL)
    {
        Node *p = l->head;
        l->head = l->head->next;
        free(p);
        l->len--;
    }
    l->head = NULL;
    l->tail = NULL;
    l->len = 0;
    free(l);
    return 0;
}

int addNode(LinkedList *l, Node *n)
{
    if (l == NULL || n == NULL)
    {
        return -1;
    }
    if (l->head == NULL)
    {
        l->head = n;
    }
    if (l->tail == NULL)
    {
        l->tail = n;
    }
    else
    {
        l->tail->next = n;
        l->tail = n;
        l->tail->next = NULL;
    }
    l->len++;
    return 0;
}

int delNode(LinkedList *l, Node *n)
{
    if (l == NULL || n == NULL)
    {
        return -1;
    }
    if (l->head == n)
    {
        l->head = l->head->next;
        l->len--;
        if (l->len == 0)
        {
            l->tail = NULL;
        }
        return 0;
    }
    Node *temp = l->head;
    while (temp != NULL)
    {
        if (temp->next == n)
        {
            temp->next = temp->next->next;
            l->len--;
            if (l->len == 0)
            {
                l->tail = NULL;
            }
            return 0;
        }
        temp = temp->next;
    }
    return -1;
}

Node *getHeadNode(LinkedList *l)
{
    if (l == NULL || l->head == NULL)
    {
        return NULL;
    }
    return l->head;
}

Node *getNextNode(LinkedList *l, Node *n)
{
    if (l == NULL || n == NULL)
    {
        return NULL;
    }
    Node *temp = l->head;
    while (temp != NULL)
    {
        if (temp == n)
        {
            return temp->next;
        }
        temp = temp->next;
    }
    return NULL;
}