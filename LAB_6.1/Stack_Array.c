// Implement a stack using an array and perform standard stack

#include <stdio.h>
#define MAX 6

void push(int stack[], int x, int *top)
{
    if ((*top) + 1 == MAX)
    {
        printf("Stack overflow\n");
        return;
    }
    else
    {
        stack[++(*top)] = x;
        return;
    }
}

void pop(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("Stack underflow\n");
        return;
    }
    else
    {
        printf("Popped element is %d\n", stack[*top]);
        (*top)--;
        return;
    }
}

void peek(int stack[], int top)
{
    for (int i = top; i >= 0; i--)
    {
        printf("| %d |\n", stack[i]);
        printf("------\n");
    }
}

void isEmpty(int top)
{
    if (top == -1)
        printf("Stack is empty\n");
    else
        printf("Stack is not empty\n");
}

void isFull(int top)
{
    if (top + 1 == MAX)
        printf("Stack is full\n");
    else
        printf("Stack is not full\n");
}

int main()
{
    int stack[MAX];

    printf("\n1 - push()");
    printf("\n2 - pop()");
    printf("\n3 - peek()");
    printf("\n4 - isEmpty()");
    printf("\n5 - isFull()");
    printf("\nAny other number to terminate\n");

    int ch, x;
    int top = -1;
    do
    {
        printf("Choice: ");
        scanf("%d", &ch);

        if (ch == 1)
        {
            printf("Enter the number to be pushed");
            scanf("%d", &x);

            push(stack, x, &top);
        }
        else if (ch == 2)
            pop(stack, &top);
        else if (ch == 3)
            peek(stack, top);
        else if (ch == 4)
            isEmpty(top);
        else if (ch == 5)
            isFull(top);
        else
            printf("Wrong entered");

    } while (0 < ch && ch < 6);
    printf("End of program ");
}