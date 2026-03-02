#include <stdio.h>
#include <stdlib.h>

#define MAX 30

int stack[MAX];
int top = -1;

void push(int n)
{
    stack[++top] = n;
}

int pop()
{
    return stack[top--];
}

int evaluate(char *postfix)
{
    int i = 0;
    while (postfix[i] != '\0')
    {
        char c = postfix[i];

        // if its a digit -----> push
        if (c >= '0' && c <= '9')
        {
            push(c - '0');
        }
        // if its an operator popping  two, doing the math, push result
        else
        {
            int b = pop();
            int a = pop();
            if (c == '+')
                push(a + b);
            else if (c == '-')
                push(a - b);
            else if (c == '*')
                push(a * b);
            else if (c == '/')
                push(a / b);
            else if (c == '%')
                push(a % b);
        }
        i++;
    }
    return pop();
}

int main()
{
    char postfix[MAX];
    // assuming correct expression
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    printf("Result: %d\n", evaluate(postfix));
    return 0;
}