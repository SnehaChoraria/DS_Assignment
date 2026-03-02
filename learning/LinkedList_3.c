#include<stdio.h>
#include<stdlib.h>

typedef struct node
    {
        int num;
        struct node *next;
    }node;

int main(){

    printf("Here is the linked list diagram for 3 members :");
    node *list=NULL;

    for(int i=0;i<3;i++)
    {
        node *n=malloc(sizeof(node));
        
        printf("Enter the value of %d node ",i+1);
        scanf("%d",&n->num);

        n->next=list;
        list=n;
    }

    /*for(int i=0;i<3;i++)
    {
        printf("%d\t",n->num);
    }
    printf("\n");
    for(int i=0;i<3;i++)
    {
        printf("%d\t",n->next);
    }*/
}
