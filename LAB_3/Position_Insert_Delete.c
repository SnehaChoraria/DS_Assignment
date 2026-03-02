#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node *next;
} node;

void insertAtPos(node **head, int pos, int val)
{
    if (pos < 0)
    {
        printf("Invalid position\n");
        return;
    }
    if (pos == 0)
    {
        insertHead(head, val);
        return;
    }
    node *ptr = *head;
    for (int i = 0; i < pos - 1 && ptr; i++)
        ptr = ptr->next;
    if (ptr == NULL)
    {
        printf("Position out of range\n");
        return;
    }
    node *n = (node *)malloc(sizeof(node));
    n->num = val;
    n->next = ptr->next;
    ptr->next = n;
}

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

void deletePos(node **head, int pos)
{
    if (*head == NULL || pos < 0)
    {
        printf("Invalid\n");
        return;
    }
    if (pos == 0)
    {
        node *tmp = *head;
        *head = (*head)->next;
        free(tmp);
        return;
    }
    node *ptr = *head;
    for (int i = 0; i < pos - 1 && ptr->next; i++)
        ptr = ptr->next;
    if (ptr->next == NULL)
    {
        printf("Position out of range\n");
        return;
    }
    node *tmp = ptr->next;
    ptr->next = tmp->next;
    free(tmp);
}

int main()
{
    node *head4 = NULL;
    insertTail(&head4, 10);
    insertTail(&head4, 20);
    insertTail(&head4, 30);
    insertTail(&head4, 40);
    printf("Original: ");
    display(head4);
    insertAtPos(&head4, 2, 25);
    printf("After Insert(pos=2, 25): ");
    display(head4);
    deletePos(&head4, 4);
    printf("After Delete(pos=4): ");
    display(head4);
}