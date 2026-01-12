#include<stdio.h>
int main()
{
    int i,j,a[2][2];
    
    printf("Enter elements row wise\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
        	printf("Enter the a[%d][%d]:",i,j);
            scanf("%d",&a[i][j]);
        }
    }

    printf("Printing elements row wise\n");

    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }


}