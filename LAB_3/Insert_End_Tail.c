#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node *next;
} node;

void insertTailO1(node **head, node **tail, int val)
{
    node *n = (node *)malloc(sizeof(node));
    n->num = val;
    n->next = NULL;
    if (*head == NULL)
    {
        *head = n;
        *tail = n;
        return;
    }
    (*tail)->next = n;
    *tail = n;
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
    node *head3 = NULL;
    node *tail3 = NULL;
    insertTailO1(&head3, &tail3, 1);
    insertTailO1(&head3, &tail3, 2);
    insertTailO1(&head3, &tail3, 3);
    printf("After 3 tail inserts: ");
    display(head3);
}
