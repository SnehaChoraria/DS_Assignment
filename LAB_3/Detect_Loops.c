#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node *next;
} node;

void createCycle(node *head, int pos)
{
    node *tail = head, *cycleNode = NULL;
    int idx = 0;
    while (tail->next)
    {
        if (idx == pos)
            cycleNode = tail;
        tail = tail->next;
        idx++;
    }
    if (cycleNode)
        tail->next = cycleNode;
}

void detectAndRemoveCycle(node *head)
{
    if (!head)
        return;
    node *slow = head, *fast = head;
    int hasCycle = 0;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            hasCycle = 1;
            break;
        }
    }
    if (!hasCycle)
    {
        printf("No cycle detected\n");
        return;
    }
    slow = head;
    if (slow == fast)
    {
        while (fast->next != slow)
            fast = fast->next;
        fast->next = NULL;
    }
    else
    {
        while (slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
    }
    printf("Cycle detected and removed\n");
}

void insertTail(node **head, int val)
{
    node *n = (node *)malloc(sizeof(node));
    n->num = val;
    n->next = NULL;
    if (*head == NULL)
    {
        *head = n;
        return;
    }
    node *ptr = *head;
    while (ptr->next)
        ptr = ptr->next;
    ptr->next = n;
}

void display(node *head)
{
    if (!head)
    {
        printf("(empty)\n");
        return;
    }
    for (node *ptr = head; ptr != NULL; ptr = ptr->next)
        printf("->%d", ptr->num);
    printf("\n");
}

int main()
{
    node *head6 = NULL;
    for (int i = 1; i <= 5; i++)
        insertTail(&head6, i);
    createCycle(head6, 1);
    printf("Cycle before removal? %s\n", detectCycle(head6) ? "Yes" : "No");
    detectAndRemoveCycle(head6);
    printf("Cycle after removal? %s\n", detectCycle(head6) ? "Yes" : "No");
    printf("List after removal: ");
    display(head6);
}