#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

struct Node *reverse(Node *head)
{

    Node *result = NULL;
    Node *temp = NULL;

    while (head != NULL)
    {
        temp = head->prev;
        head->prev = head->next;
        head->next = temp;

        result = head;
        head = head->prev;
    }

    return result;
}

int main()
{
    Node *head = createList();
    printList(head);
    printList(reverse(head));
}