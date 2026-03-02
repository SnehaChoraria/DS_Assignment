#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int num;

    printf("Enter the number of elemennts in list");
    scanf("%d", &num);

    printf("Enter the elements:\n");
    for (int i = 0; i < num; i++)
    {
        Node *n = malloc(sizeof(Node));

        if (n == NULL)
        {
            printf("Memory not allocated");
            exit(1);
        }

        scanf("%d", &n->value);
        n->next = NULL;

        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = tail->next;
        }
    }

    // reversing or checking from tail to front
    Node *temp = head;
    Node *head2 = NULL;
    while (temp != NULL)
    {
        Node *n2 = malloc(sizeof(Node));
        n2->value = temp->value;

        n2->next = head2;
        head2 = n2;
        temp = temp->next;
    }

    temp = head;
    Node *temp2 = head2;
    int flag = 0;
    while (temp != NULL)
    {
        if (temp->value == temp2->value)
        {
            flag = 1;
        }
        else
        {
            flag = 0;
            break;
        }
        temp = temp->next;
        temp2 = temp2->next;
    }
    if (flag == 1)
        printf("Is palindrome");
    else
        printf("Is not palindrome");

    temp = head;

    while (temp != NULL)
    {
        Node *next = temp->next;
        free(temp);
        temp = next;
    }
    temp = head2;

    while (temp != NULL)
    {
        Node *next = temp->next;
        free(temp);
        temp = next;
    }
}