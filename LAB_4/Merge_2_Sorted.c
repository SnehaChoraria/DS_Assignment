#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

struct Node *createList()
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
    return head;
}
int main()
{
    Node *list1 = createList();
    Node *list2 = createList();

    Node *temp1 = list1;
    Node *temp2 = list2;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->value > temp2->value)
        {
            printf("%d->", temp2->value);
            temp2 = temp2->next;
        }
        else if (temp1->value == temp2->value)
        {
            printf("%d->%d->", temp1->value, temp2->value);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else
        {
            printf("%d->", temp1->value);
            temp1 = temp1->next;
        }
    }

    while (temp1 != NULL)
    {
        printf("%d", temp1->value);
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        printf("%d", temp2->value);
        temp2 = temp2->next;
    }

    temp1 = list1;
    temp2 = list2;
    Node *delete = NULL;

    while (temp1 != NULL)
    {
        delete = temp1;
        temp1 = temp1->next;
        free(delete);
    }

    while (temp2 != NULL)
    {
        delete = temp2;
        temp2 = temp2->next;
        free(delete);
    }
}