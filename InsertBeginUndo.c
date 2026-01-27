#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int num;
    struct node *next;
}node;

void InsertFront(node **list);
void Undo(node **list);

int main(){

    int ch;
    node *list=NULL;
    do{
        printf("\nEnter choice:\n0-Exit\n1-Insert node at beggining\n2-Undo the last step\n3-Display\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                    InsertFront(&list);
                    break;
            
            case 2:
                    Undo(&list);
                    break;
            
            case 3:
                    for(node *ptr=list;ptr!=NULL;ptr=ptr->next)
                    {
                        printf("->%d",ptr->num);
                    }
                    break;
                    

            default:
                    printf("Wrong choice\n");
        }

    }while(ch!=0);
}
void InsertFront(node **list)
{
    int a;
    printf("Number:");
    scanf("%d",&a);

    node *n=malloc(sizeof(node));
    if(n==NULL)
    {
        printf("\nMemory not allocated\n");
        return;
    }
    n->num=a;
    n->next=*list;
    *list=n;
    
}
void Undo(node **list)
{
    if(*list==NULL)
    {
        printf("No steps to undo\n");
        return;
    }
    else{
    node *temp = *list;
    *list = (*list)->next;
    free(temp);
    printf("Last step undone\n");
    }
}
