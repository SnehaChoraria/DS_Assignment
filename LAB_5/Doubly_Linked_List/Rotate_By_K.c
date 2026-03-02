#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

struct Node *rotate(Node *head, int k)
{
    Node *temp = head;
    int len = 0;
    // to calculate length of linked list
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    temp = head;

    // to make sure its doesnt overflow 
    k = (k % len);

    for (int i = 0; i < k; i++)
    {
        // to reach till kth postion node
        temp = temp->next;
    }
    Node *new_head = temp->next;
    // new head points to K+1th nodes previous one

    temp->next->prev = NULL;
    //the k+1th nodes previous one now stores NULL

    Node* temp1=head;
    while (temp1->next !=NULL)
    {

    }

        return new_head;
}

int main()
{
    int k;
    Node *head = createList();
    printList(head);

    printf("Enter the elements to be rotated :");
    scanf("%d", &k);

    Node *result = rotate(head, k);
    printList(result);
}