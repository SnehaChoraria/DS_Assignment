#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

void sum(Node *head, int k)
{
    Node *slow = head;
    Node *fast = slow;

    while (slow != NULL && slow->next != NULL)
    {
        Node *fast = slow->next;
        while (fast != NULL)
        {
            int sum = slow->value + fast->value;
            if (sum == k)
            {
                printf("(%d,%d)", slow->value, fast->value);
            }
            fast = fast->next;
        }
        slow = slow->next;
    }
}

int main()
{
    int k;
    Node *head = createList();
    printList(head);

    printf("Sum to be found :");
    scanf("%d", &k);

    printf("The pairs are:");
    sum(head, k);
}