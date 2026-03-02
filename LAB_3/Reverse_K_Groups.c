// Reverse Linked List in Groups of K

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node *next;
} node;

void insertTail(node **head, int val)
{
    node *n = (node *)malloc(sizeof(node));
    n->num = val;
    n->next = NULL;
    if (*head == NULL)
    {
        *head = n;
        return;
    }
    node *ptr = *head;
    while (ptr->next)
        ptr = ptr->next;
    ptr->next = n;
}

void display(node *head)
{
    if (!head)
    {
        printf("(empty)\n");
        return;
    }
    for (node *ptr = head; ptr != NULL; ptr = ptr->next)
        printf("->%d", ptr->num);
    printf("\n");
}

node *reverseGroupK(node *head, int k)
{
    node *cur = head, *prevGroupTail = NULL, *newHead = NULL;
    while (cur)
    {
        node *groupHead = cur;
        node *prev = NULL;
        int count = 0;
        while (cur && count < k)
        {
            node *nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
            count++;
        }
        if (newHead == NULL)
            newHead = prev;
        if (prevGroupTail)
            prevGroupTail->next = prev;
        prevGroupTail = groupHead;
    }
    return newHead;
}

int main()
{
    node *head7 = NULL;
    for (int i = 1; i <= 8; i++)
        insertTail(&head7, i);
    printf("Original: ");
    display(head7);
    head7 = reverseGroupK(head7, 3);
    printf("After reverseGroupK(3): ");
    display(head7);
}