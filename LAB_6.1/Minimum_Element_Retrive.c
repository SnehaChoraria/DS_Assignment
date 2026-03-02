// Design a stack that supports retrieval of the minimum element in O(1) time.

#include <stdio.h>
#define MAX 30

int top = -1;
int topMin = -1;

void push(int x, int stack[], int minStack[])
{
    if (top == MAX - 1)
    {
        printf("Stack overflow\n");
        return;
    }

    stack[++top] = x;

    if (topMin == -1 || x <= minStack[topMin])
        minStack[++topMin] = x;
}

void pop(int stack[], int minStack[])
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return;
    }

    int popped = stack[top--];

    if (popped == minStack[topMin])
        topMin--;

    printf("Popped: %d\n", popped);
}

void minimum(int minStack[])
{
    if (topMin == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Minimum element: %d\n", minStack[topMin]);
}

int main()
{
    int stack[MAX], minStack[MAX];
    int ch = 1, x;

    printf("1-push\n2-pop\n3-minimum\n");

    while (ch > 0 && ch < 4)
    {
        printf("Choice: ");
        scanf("%d", &ch);

        if (ch == 1)
        {
            printf("Enter value: ");
            scanf("%d", &x);
            push(x, stack, minStack);
        }
        else if (ch == 2)
        {
            pop(stack, minStack);
        }
        else if (ch == 3)
        {
            minimum(minStack);
        }
    }
}