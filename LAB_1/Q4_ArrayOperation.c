#include<stdio.h>
int main()
{
	int n;
	printf("Enter value of n");
	scanf("%d",&n);
	

    int a[n];
	double sum=0;
    
    for(int i=0;i<n;i++)
    {
        	printf("Enter the a[%d]:",i);
            scanf("%d",&a[i]);   
            sum=sum+a[i];
    }
    
    int max=a[0],min=a[0],key,flag=0;
    
    for(int i=1;i<n;i++)
    {
    	if(a[i]>max)
    	max=a[i];
    	if(a[i]<min)
    	min=a[i];           
    }
	    printf("Largest:%d\n",max);
	    printf("Smallest:%d\n",min);
	    printf("Average:%lf\n",(sum/n));
	    
	    printf("Enter the term to be searched");
	    scanf("%d",&key);
	    
	    for(int i=0;i<n;i++)
	    {
	    	if(a[i]==key)
	    	{
	    		break;
	    		flag=1;
			}	
		}
		
		if(flag==0)
		printf("Key is present");
		else
				printf("Key is absent");

}