#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

typedef struct Node
{
    int value;
    struct Node *next;
    struct Node *prev;
} Node;

Node *createList();
void printList(Node *head);

#endif
