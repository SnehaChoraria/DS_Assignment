#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node *next;
} node;

node *createNode(int val)
{
    node *n = (node *)malloc(sizeof(node));
    n->num = val;
    n->next = NULL;
    return n;
}

void insertTail(node **head, int val)
{
    node *n = createNode(val);
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

int getLength(node *head)
{
    int len = 0;
    for (node *ptr = head; ptr != NULL; ptr = ptr->next)
        len++;
    return len;
}

node *findIntersection(node *a, node *b)
{
    if (!a || !b)
        return NULL;

    int lenA = getLength(a);
    int lenB = getLength(b);

    // move the longer list ahead by the difference
    while (lenA > lenB)
    {
        a = a->next;
        lenA--;
    }
    while (lenB > lenA)
    {
        b = b->next;
        lenB--;
    }

    // now move both together until they hit the same node
    while (a != b)
    {
        a = a->next;
        b = b->next;
    }
    // if no intersection, a and b both become NULL and we return NULL
    return a;
}

int main()
{

    node *list1 = NULL;
    insertTail(&list1, 1);
    insertTail(&list1, 2);
    insertTail(&list1, 3);

    node *list2 = NULL;
    insertTail(&list2, 4);
    insertTail(&list2, 5);

    // shared part
    node *shared = NULL;
    insertTail(&shared, 6);
    insertTail(&shared, 7);
    insertTail(&shared, 8);

    // attach shared part to both lists
    node *ptr = list1;
    while (ptr->next)
        ptr = ptr->next;
    ptr->next = shared;

    ptr = list2;
    while (ptr->next)
        ptr = ptr->next;
    ptr->next = shared;

    printf("List1: ");
    display(list1);
    printf("List2: ");
    display(list2);

    node *meet = findIntersection(list1, list2);
    if (meet)
        printf("Intersection at node with value: %d\n", meet->num);
    else
        printf("No intersection\n");

    // test with no intersection
    printf("\n-- No intersection test --\n");
    node *x = NULL;
    insertTail(&x, 1);
    insertTail(&x, 2);
    node *y = NULL;
    insertTail(&y, 3);
    insertTail(&y, 4);
    printf("List x: ");
    display(x);
    printf("List y: ");
    display(y);
    node *res = findIntersection(x, y);
    if (res)
        printf("Intersection at: %d\n", res->num);
    else
        printf("No intersection\n");

    return 0;
}