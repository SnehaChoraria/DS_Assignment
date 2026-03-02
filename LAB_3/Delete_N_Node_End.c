// Delete Nth Node from End (One Pass Only)
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

void deleteNthFromEnd(node **head, int n)
{
    node dummy;
    dummy.next = *head;
    node *fast = &dummy, *slow = &dummy;
    for (int i = 0; i <= n; i++)
    {
        if (fast == NULL)
        {
            printf("N is larger than list length\n");
            return;
        }
        fast = fast->next;
    }
    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    node *tmp = slow->next;
    slow->next = tmp->next;
    free(tmp);
    *head = dummy.next;
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

int main()
{
    node *head5 = NULL;
    for (int i = 1; i <= 5; i++)
        insertTail(&head5, i);
    printf("Original: ");
    display(head5);
    deleteNthFromEnd(&head5, 2);
    printf("After deleting 2nd from end: ");
    display(head5);
}