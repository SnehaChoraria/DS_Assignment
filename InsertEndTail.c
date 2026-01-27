#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int num;
    struct node *next;
}node;

int main(){

    node *head=NULL;
    node *tail=NULL;

    int ch;
    while(ch!=0)
    { 
    printf("\nEnter choice\n1-Insert\n2-Display\n0-Exit\n");
    scanf("%d",&ch);

    switch(ch){
        case 1:
            int x;
            printf("\nEnter value to be inserted\n");
            scanf("%d",&x);
            node *n=(node *)malloc(sizeof(node));
            if(n==NULL){
                printf("\nMemory not allocated\n");
                return -1;
            }
            n->num=x;
            n->next=NULL;

            if(head==NULL){
                head=n;
                tail=n;
            }
            else{
                tail->next=n;
                tail=n;
            }

            break;
        case 2:
            for(node *ptr=head;ptr!=0;ptr=ptr->next)
            {
                printf("->%d",ptr->num);
            }
            break;
        default:
            printf("\nInvalid choice\n");
        }
    }
    return 0;
}
