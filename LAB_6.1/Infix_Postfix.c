#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

int top = -1;
int top_post = -1;

char infix[MAX];
char postfix[MAX];
char stack[MAX];

void push(char c)
{
    stack[++top] = c;
}

void pushPostfix(char c) // find expression store here
{
    postfix[++top_post] = c;
}

void pop()
{
    pushPostfix(stack[top--]);
}

void display()
{
    postfix[top_post + 1] = '\0';
    printf("%s\n", postfix);
}

int main()
{
    // assuming correct expresion to check us previous program (balanced_parenthesis)
    printf("Enter the expression: ");
    scanf("%s", infix);

    int i = 0;
    while (infix[i] != '\0' && i < MAX)
    {
        char c = infix[i];

        if (c == '(')
        {
            push(c);
        }
        else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
        {
            pushPostfix(c);
        }
        else if (c == ')')
        {
            while (top != -1 && stack[top] != '(')
                pop();
            top--;
        }
        else if (c == '+' || c == '-')
        {
            while (top != -1 && stack[top] != '(')
                pop();
            push(c);
        }
        else if (c == '*' || c == '/')
        {
            while (top != -1 && stack[top] != '(' && stack[top] != '+' && stack[top] != '-')
                pop();
            push(c);
        }

        i++;
    }

    while (top != -1)
        pop();

    display();
    return 0;
}