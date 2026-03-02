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

// merge two sorted lists into one sorted list
// same idea as merge step in merge sort
node *mergeTwo(node *a, node *b)
{
    // dummy node so we dont have to handle empty list separately
    node dummy;
    dummy.next = NULL;
    node *tail = &dummy;

    while (a && b)
    {
        if (a->num <= b->num)
        {
            tail->next = a;
            a = a->next;
        }
        else
        {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    // attach whichever list still has nodes left
    if (a)
        tail->next = a;
    if (b)
        tail->next = b;

    return dummy.next;
}

// merge all k lists one by one into a result list
node *mergeKLists(node *lists[], int k)
{
    if (k == 0)
        return NULL;

    node *result = lists[0];
    for (int i = 1; i < k; i++)
        result = mergeTwo(result, lists[i]);

    return result;
}

int main()
{

    // L1=1->5, L2=2->6, L3=3->4
    node *l1 = NULL;
    insertTail(&l1, 1);
    insertTail(&l1, 5);
    node *l2 = NULL;
    insertTail(&l2, 2);
    insertTail(&l2, 6);
    node *l3 = NULL;
    insertTail(&l3, 3);
    insertTail(&l3, 4);

    printf("L1: ");
    display(l1);
    printf("L2: ");
    display(l2);
    printf("L3: ");
    display(l3);

    node *lists[] = {l1, l2, l3};
    int k = 3;

    node *merged = mergeKLists(lists, k);
    printf("Merged: ");
    display(merged);

    return 0;
}