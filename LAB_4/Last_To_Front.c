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

    Node *last_2 = NULL;
    Node *temp = head;
    while (temp != 0)
    {
        if (temp->next->next == NULL)
        {
            temp->next = NULL;
            break;
        }
        temp = temp->next;
    }

    tail->next = head;
    head = tail;

    temp = NULL;
    while (head != 0)
    {
        printf("%d->", head->value);
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("NULL");
}