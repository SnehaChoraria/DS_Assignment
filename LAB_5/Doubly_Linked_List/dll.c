#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

Node *createList()
{
    Node *head = NULL;
    Node *tail = NULL;
    int num;

    printf("Enter number of elements: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        Node *n = malloc(sizeof(Node));

        if (n == NULL)
        {
            printf("Memory not allocated");
            exit(1);
        }

        scanf("%d", &n->value);
        n->next = NULL;

        if (head == NULL)
        {
            n->prev = NULL;
            head = n;
            tail = n;
        }
        else
        {
            n->prev = tail;
            tail->next = n;
            tail = n;
        }
    }

    return head;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d <-> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}
