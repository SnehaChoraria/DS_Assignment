#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
    struct Node *bottom;
} Node;

struct Node *createNode(int value)
{
    Node *n = malloc(sizeof(Node));
    n->value = value;
    n->bottom = NULL;
    n->next = NULL;
    return n;
}
int main()
{
    Node *head = NULL;
    head = createNode(5);
    head->bottom = createNode(7);
    head->bottom->bottom = createNode(8);
    head->next = createNode(10);
    head->next->next = createNode(19);
    head->next->next->next = createNode(28);
    head->next->bottom = createNode(20);
    head->next->next->bottom = createNode(22);
    head->next->next->next->bottom = createNode(40);
    head->next->next->next->bottom->bottom = createNode(45);

    printf("To print the list in one line :");

    Node *temp = head;
    Node *horizontal = temp;

    // change this logic its for a different question
    while (horizontal != NULL)
    {
        temp = horizontal;
        while (temp != NULL)
        {
            printf("%d->", temp->value);
            temp = temp->bottom;
        }
        horizontal = horizontal->next;
    }

    temp = head;
    horizontal = temp;
    Node *delete = NULL;
    while (horizontal != NULL)
    {
        temp = horizontal;
        while (temp != NULL)
        {
            delete = temp;
            temp = temp->bottom;
            free(delete);
        }
        horizontal = horizontal->next;
    }
}