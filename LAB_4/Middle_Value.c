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
    Node *head = NULL;

    printf("Enter the number of nodes");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        Node *n = malloc(sizeof(Node));

        if (n == NULL)
        {
            // for effectiveness free all nodes here
            printf("Memory allocation failed\n");
            return 1;
        }

        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &n->value);
        n->next = NULL;

        if (head == NULL)
        {
            head = n;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = n;
        }
    }

    int mid = num / 2, mid_value = 0, mid_value2 = 0;
    int count = 1;
    struct Node *temp = head;

    while (count <= mid)
    {
        temp = temp->next;
        count++;
    }
    mid_value = temp->value;
    mid_value2 = temp->next->value;

    if (num % 2 == 0)
    {
        printf("The first middle value is %d", mid_value);
        printf("\nThe second middle value is %d", mid_value2);
    }
    else
    {
        printf("The middle value is %d", mid_value);
    }
    temp = head;

    while (temp != NULL)
    {
        Node *next = temp->next;
        free(temp);
        temp = next;
    }
}