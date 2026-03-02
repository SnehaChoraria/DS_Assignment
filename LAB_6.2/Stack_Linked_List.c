// Implement Stack Using Linked List

#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int data;
    struct stack *next;
} stack;

void isEmpty(stack *head)
{
    if (head == NULL)
        printf("Stack is empty\n");
    else
        printf("Stack is not empty\n");
}

stack *push(int x, stack *head)
{
    stack *n = malloc(sizeof(stack));
    n->data = x;
    n->next = head;
    return n;
}

stack *pop(stack *head)
{
    if (head == NULL)
    {
        printf("Stack is empty\n");
        return NULL;
    }

    stack *temp = head;
    head = head->next;
    printf("Popped element : %d\n", temp->data);
    free(temp);
    return head;
}

void peek(stack *head)
{
    printf("\nSTACK\n");
    while (head != NULL)
    {
        printf("| %d |\n", head->data);
        printf("------\n");
        head = head->next;
    }
}
int main()
{

    printf("\n1 - push()");
    printf("\n2 - pop()");
    printf("\n3 - peek()");
    printf("\n4 - isEmpty()");
    printf("\nAny other number to terminate\n");

    int ch, x;
    stack *head = NULL;

    do
    {
        printf("Choice:");
        scanf("%d", &ch);

        if (ch == 1)
        {
            printf("Enter the number to be pushed");
            scanf("%d", &x);

            head = push(x, head);
        }
        else if (ch == 2)
            head = pop(head);

        else if (ch == 3)
            peek(head);
        else
            isEmpty(head);

    } while (0 < ch && ch < 5);

    printf("End of program ");
}