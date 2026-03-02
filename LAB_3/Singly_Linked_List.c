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

void deleteVal(node **head, int val)
{
    if (*head == NULL)
    {
        printf("List empty\n");
        return;
    }
    if ((*head)->num == val)
    {
        node *tmp = *head;
        *head = (*head)->next;
        free(tmp);
        return;
    }
    node *ptr = *head;
    while (ptr->next && ptr->next->num != val)
        ptr = ptr->next;
    if (ptr->next == NULL)
    {
        printf("Value not found\n");
        return;
    }
    node *tmp = ptr->next;
    ptr->next = tmp->next;
    free(tmp);
}

void search(node *head, int val)
{
    int idx = 0;
    for (node *ptr = head; ptr != NULL; ptr = ptr->next, idx++)
        if (ptr->num == val)
        {
            printf("Found %d at index %d\n", val, idx);
            return;
        }
    printf("%d not found\n", val);
}

void reverseList(node **head)
{
    node *prev = NULL, *cur = *head, *nxt;
    while (cur)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *head = prev;
}

void search(node *head, int val)
{
    int idx = 0;
    for (node *ptr = head; ptr != NULL; ptr = ptr->next, idx++)
        if (ptr->num == val)
        {
            printf("Found %d at index %d\n", val, idx);
            return;
        }
    printf("%d not found\n", val);
}

void reverseList(node **head)
{
    node *prev = NULL, *cur = *head, *nxt;
    while (cur)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *head = prev;
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
    node *head = NULL;
    insertTail(&head, 10);
    insertTail(&head, 20);
    insertTail(&head, 30);
    printf("After InsertTail 10,20,30: ");
    display(head);
    deleteVal(&head, 20);
    printf("After DeleteVal(20): ");
    display(head);
    reverseList(&head);
    printf("After Reverse: ");
    display(head);
    search(head, 30);
    search(head, 99);
    printf("Cycle? %s\n", detectCycle(head) ? "Yes" : "No");
}