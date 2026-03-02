// Check for Balanced Parentheses

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int top = -1;

void push(char ch, char stack[])
{
    stack[++top] = ch;
}

char pop(char stack[])
{
    return stack[top--];
}

void balanced(char ch[])
{
    int i;
    int len = strlen(ch);
    char stack[len / 2];
    for (i = 0; i < len; i++)
    {
        if (ch[i] == '[' || ch[i] == '{' || ch[i] == '(')
        {
            push(ch[i], stack);
        }
        else if (ch[i] == ']' || ch[i] == '}' || ch[i] == ')')
        {
            char temp = pop(stack);
            {
                if (temp == '[' && ch[i] == ']')
                    continue;
                else if (temp == '(' && ch[i] == ')')
                    continue;
                else if (temp == '{' && ch[i] == '}')
                    continue;
                else
                {
                    printf("Wrong expression !!");
                    exit(1);
                }
            }
        }
    }
}
int main()
{
    char ch[20];

    printf("Enter the expression:\n");
    scanf("%s", ch);

    balanced(ch);
    printf("\nBalanced expression");
}