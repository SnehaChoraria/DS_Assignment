// Implement a queue using Linked list.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void display(Node *front)
{
    Node *temp = front;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}
void enqueue(Node **front, Node **rear, int value)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = value;
    n->next = NULL;

    if (*rear == NULL)
    {
        *front = *rear = n;
        return;
    }

    (*rear)->next = n;
    *rear = n;
}
void dequeue(Node **front, Node **rear)
{
    if (*front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    Node *temp = *front;
    *front = (*front)->next;

    if (*front == NULL)
        *rear = NULL;

    free(temp);
}

void isEmpty(Node *front, Node *rear)
{
    if (front == NULL && rear == NULL)
    {
        printf("List is empty\n");
    }
    else
        printf("List is not empty\n");
}

void frontOperation(Node *front)
{
    if (front == NULL)
        printf("Queue is empty\n");
    else
        printf("The front element is: %d\n", front->data);
}

int main()
{
    int x, i;

    printf("Enter the options :\n");
    printf("1-Enqueue\n");
    printf("2-Dequeue\n");
    printf("3-To check if empty\n");
    printf("4-Front Operation\n");

    Node *front = NULL;
    Node *rear = NULL;

    do
    {
        printf("Enter choice :");
        scanf("%d", &x);

        switch (x)
        {
        case 1:
            printf("Enter the element:");
            scanf("%d", &i);
            enqueue(&front, &rear, i);
            break;
        case 2:
            dequeue(&front, &rear);
            break;
        case 3:
            isEmpty(front, rear);
            break;
        case 4:
            frontOperation(front);
            break;
        default:
            break;
        }

    } while (x != 0);

    display(front);
    printf("Program end");
}