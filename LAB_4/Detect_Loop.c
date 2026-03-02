#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

int main()
{
    int num, pos;
    Node *head = NULL;
    Node *loop = NULL;

    printf("Enter the number of nodes");
    scanf("%d", &num);

    printf("Enter the position where loop is to be formed from last node (-1 if not) :");
    scanf("%d", &pos);

    printf("Enter the elements:\n");

    for (int i = 0; i < num; i++)
    {
        Node *n = malloc(sizeof(Node));
        if (n == NULL)
        {
            // free all previous nodes here
            printf("Memory not allocated");
            exit(1);
        }
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

        if (i == pos - 1)
        {
            loop = n;
        }
        if (i == num - 1)
        {
            n->next = loop;
        }
    }

    Node *fast = head;
    Node *slow = head;

    int flag = 0;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            flag = 1;
            break;
        }
    }
    Node *temp = head;
    while (temp != NULL)
    {
        Node *next = temp->next;
        free(temp);
        temp = next;
    }
    if (flag == 1)
        printf("The string has a loop");
    else
        printf("The string doesnt have a loop");
}