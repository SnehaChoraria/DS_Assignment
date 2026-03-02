// Reverse a given string using stack operations.

#include <stdio.h>
#define MAX 20

void push(char stack[], char x, int *top)
{
    if ((*top) + 1 == MAX)
    {
        printf("Stack overflow\n");
        return;
    }
    else
    {
        stack[++(*top)] = x;
    }
}

void pop(char stack[], int *top)
{
    if (*top == -1)
    {
        printf("Stack underflow\n");
        return;
    }
    else
    {
        printf("%c", stack[*top]);
        (*top)--;
    }
}

void reverse(char *ch)
{
    char *temp = ch;
    int top = -1;
    char stack[MAX];

    while (*temp != '\0')
    {
        push(stack, *temp, &top);
        temp++;
    }
    while (*ch != '\0')
    {
        pop(stack, &top);
        ch++;
    }
}
int main()
{

    char ch[MAX];

    printf("Enter the string :");
    scanf("%s", ch);

    printf("\nReversed string is :");
    reverse(ch);
    printf("\nEnd of program");
}
