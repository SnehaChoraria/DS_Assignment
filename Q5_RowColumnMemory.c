#include<stdio.h>
int main()
{
    int i,j,l,m;

	printf("Enter value of i");
	scanf("%d",&i);
	
	printf("Enter value of j");
	scanf("%d",&j);
	
    int a[i][j];
    
    printf("Enter elements row wise\n");
    for(l=0;l<i;l++)
    {
        for(m=0;m<j;m++)
        {
        	printf("Enter the a[%d][%d]:",l,m);
            scanf("%d",&a[l][m]);
        }
    }

    printf("Enter elements column wise\n");
    for(l=0;l<j;l++)
    {
        for(m=0;m<i;m++)
        {
        	printf("Enter the a[%d][%d]:",l,m);
            scanf("%d",&a[l][m]);
        }
    }
    
    
     printf("elements row wise , their actual and calulated address \n");
    for(l=0;l<i;l++)
    {
        for(m=0;m<j;m++)
        {
        	int h=((l*j)+m);
        	
        	printf("a[%d][%d]:%d\tAddress:%u\tCalc:%u\n",l,m,a[l][m],&a[l][m],((&a[0][0]) + h));
        }
    }

    printf("Enter elements column wise\n");
    for(l=0;l<j;l++)
    {
        for(m=0;m<i;m++)
        {
            printf("a[%d][%d]:%d\tAddress:%u\tCalc:%u\n",m,l,a[l][m],&a[l][m],(&a[0][0]+(l*i+m)));

        }
    }
    
    


 
}