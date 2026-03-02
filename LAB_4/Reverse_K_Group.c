#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node *next;
} node;

node *createNode(int val)
{
    node *n = (node *)malloc(sizeof(node));
    n->num = val;
    n->next = NULL;
    return n;
}

void insertTail(node **head, int val)
{
    node *n = createNode(val);
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
    node *cur = head;
    node *prev = NULL;
    node *prevGroupTail = NULL;
    node *newHead = NULL;

    while (cur)
    {
        // remember where this group starts
        // after reversing, this node becomes the tail of the group
        node *groupTail = cur;

        // reverse k nodes
        int count = 0;
        while (cur && count < k)
        {
            node *nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
            count++;
        }
        // prev is now the head of the reversed group

        // first group sets the new head of the whole list
        if (newHead == NULL)
            newHead = prev;

        // connect previous group's tail to this group's head
        if (prevGroupTail)
            prevGroupTail->next = prev;

        // groupTail is now the last node of this group
        // save it so next group can connect to it
        prevGroupTail = groupTail;

        // reset prev for next group
        prev = NULL;
    }
    return newHead;
}

int main()
{
    node *head = NULL;
    for (int i = 1; i <= 7; i++)
        insertTail(&head, i);

    printf("Original: ");
    display(head);

    int k = 3;
    head = reverseGroupK(head, k);

    printf("After reverseGroupK(%d): ", k);
    display(head);

    return 0;
}