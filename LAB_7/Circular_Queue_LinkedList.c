#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

int displayFront(Node *front)
{
    if (front != NULL)
        return front->data;
    else
        printf("No elements");
    return 0;
}

int displayRear(Node *rear)
{
    if (rear != NULL)
        return rear->data;
    else
        printf("No elements");
    return 0;
}

void enQueue(Node **front, Node **rear, int value)
{
    Node *n = malloc(sizeof(Node));
    n->data = value;
    if (*front == NULL && *rear == NULL)
    {
        *front = n;
        *rear = n;
        n->next = n;
    }
    else
    {
        (*rear)->next = n;
        n->next = *front;
        *rear = (*rear)->next;
    }
}

void deQueue(Node **front, Node **rear)
{
    if (*front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    if (*front == *rear)
    {
        free(*front);
        *front = *rear = NULL;
        return;
    }

    Node *temp = *front;
    *front = (*front)->next;
    (*rear)->next = *front;

    if (*front == NULL)
        *rear = NULL;

    free(temp);
}

int main()
{
    Node *front = NULL;
    Node *rear = NULL;

    int x, i;

    printf("Enter the options :\n");
    printf("1-Enqueue\n");
    printf("2-Dequeue\n");
    printf("3-Front\n");
    printf("4-Rear\n");

    do
    {
        printf("Enter choice :");
        scanf("%d", &x);

        switch (x)
        {
        case 1:
            printf("Enter the element:");
            scanf("%d", &i);
            enQueue(&front, &rear, i);
            break;
        case 2:
            deQueue(&front, &rear);
            break;
        case 3:
            printf("Front: %d\n", displayFront(front));
            break;
        case 4:
            printf("Rear: %d\n", displayRear(rear));
            break;
            break;
        default:
            break;
        }

    } while (x != 0);

    printf("Program end");
}
