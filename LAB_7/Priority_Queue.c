#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    int priority;
    struct node *next;
} node;

void display(node *front)
{
    node *ptr = front;
    while (ptr != NULL)
    {
        printf("%d(p%d)->", ptr->data, ptr->priority);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// we know lowest priority number = highest priority = goes to front
void push(node **front, int val, int pri)
{
    node *n = (node *)malloc(sizeof(node));
    n->data = val;
    n->priority = pri;
    n->next = NULL;

    // if list empty or new node has higher priority than front
    if (*front == NULL || pri < (*front)->priority)
    {
        n->next = *front;
        *front = n;
        return;
    }

    // loc to insert
    node *ptr = *front;
    while (ptr->next != NULL && ptr->next->priority <= pri)
        ptr = ptr->next;

    n->next = ptr->next;
    ptr->next = n;
}

// remove from front
void pop(node **front)
{
    if (*front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    node *tmp = *front;
    printf("Popped: %d (priority %d)\n", tmp->data, tmp->priority);
    *front = (*front)->next;
    free(tmp);
}

// just look at front without removing
void peek(node *front)
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Top element: %d (priority %d)\n", front->data, front->priority);
}

void isEmpty(node *front)
{
    if (front == NULL)
        printf("Queue is empty\n");
    else
        printf("Queue is not empty\n");
}

int main()
{
    node *front = NULL;
    int x, val, pri;

    printf("Enter choice:\n1-Push\n2-Pop\n3-Peek\n4-isEmpty\n5-Display\n0-Exit\n");

    do
    {
        printf("Choice: ");
        scanf("%d", &x);

        switch (x)
        {
        case 1:
            printf("Enter value and priority: ");
            scanf("%d %d", &val, &pri);
            push(&front, val, pri);
            break;
        case 2:
            pop(&front);
            break;
        case 3:
            peek(front);
            break;
        case 4:
            isEmpty(front);
            break;
        case 5:
            display(front);
            break;
        default:
            break;
        }
    } while (x != 0);

    display(front);
    printf("Program end\n");
    return 0;
}