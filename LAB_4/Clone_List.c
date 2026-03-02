#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node *next;
    struct node *random;
} node;

node *createNode(int val)
{
    node *n = (node *)malloc(sizeof(node));
    n->num = val;
    n->next = NULL;
    n->random = NULL;
    return n;
}

// step 1: put each clone right after its original node
// 1->1'->2->2'->3->3'
void insertClones(node *head)
{
    node *cur = head;
    while (cur)
    {
        node *clone = createNode(cur->num);
        clone->next = cur->next;
        cur->next = clone;
        cur = clone->next;
    }
}

// step 2: fix random pointers for each clone
void setRandoms(node *head)
{
    node *cur = head;
    while (cur)
    {
        if (cur->random)
            cur->next->random = cur->random->next;
        cur = cur->next->next;
    }
}

// step 3: split them back into two separate lists
node *splitLists(node *head)
{
    node *cloneHead = head->next;
    node *cur = head;
    while (cur)
    {
        node *clone = cur->next;
        cur->next = clone->next;
        if (clone->next)
            clone->next = clone->next->next;
        cur = cur->next;
    }
    return cloneHead;
}

node *cloneList(node *head)
{
    if (!head)
        return NULL;
    insertClones(head);
    setRandoms(head);
    return splitLists(head);
}

void display(node *head)
{
    if (!head)
    {
        printf("(empty)\n");
        return;
    }
    for (node *ptr = head; ptr != NULL; ptr = ptr->next)
        printf("[%d|random->%d] ", ptr->num, ptr->random ? ptr->random->num : -1);
    printf("\n");
}

int main()
{

    // making list
    node *head = NULL;
    node *nodes[5];
    for (int i = 0; i < 5; i++)
    {
        nodes[i] = createNode(i + 1);
        if (i == 0)
            head = nodes[i];
        else
            nodes[i - 1]->next = nodes[i];
    }

    // set random pointers
    // 1->3, 2->1, 3->5, 4->2, 5->4
    nodes[0]->random = nodes[2];
    nodes[1]->random = nodes[0];
    nodes[2]->random = nodes[4];
    nodes[3]->random = nodes[1];
    nodes[4]->random = nodes[3];

    printf("Original: ");
    display(head);

    node *clone = cloneList(head);

    printf("Clone:    ");
    display(clone);

    // verify they are different addresses
    printf("\nAddress check (must differ):\n");
    node *a = head, *b = clone;
    while (a && b)
    {
        printf("original=%p  clone=%p  same?%s\n", (void *)a, (void *)b, a == b ? "YES - BUG" : "no - ok");
        a = a->next;
        b = b->next;
    }

    return 0;
}