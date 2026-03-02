#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

int main()
{
    int num;

    printf("Enter number of nodes in list");
    scanf("%d", &num);

    Node *head = NULL;
    Node *tail = NULL;

    printf("Enter the elements of list:\n");
    for (int i = 0; i < num; i++)
    {
        Node *n = malloc(sizeof(Node));
        if (n == NULL)
        {
            // free previously allocated nodes
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
            tail = n;
        }
    }

    Node *lead = head->next;
    Node *lag = head;

    while (lead != NULL)
    {
        if (lead->value == lag->value)
        {
            Node *temp = lead;
            lag->next = lead->next;
            lead = lead->next;
            free(temp);
        }
        else
        {
            lead = lead->next;
            lag = lag->next;
        }
    }

    printf("Hence the new list is : ");
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->value);
        head = temp;
        temp = temp->next;
        free(head);
    }
    printf("NULL");
}
