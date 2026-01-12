#include<stdio.h>
int main()
{
    int a=10;
    float b=10.0;
    char c='s';
    int arr[3]={1,2,3};

    printf("The values , address and size of memory is : \n");
    printf("a=%d\tAddress=%u\tsize=%u\n",a,&a,sizeof(a));
    printf("b=%d\tAddress=%u\tsize=%lu\n",b,&b,sizeof(b));
    printf("c=%d\tAddress=%u\tsize=%lu\n",c,&c,sizeof(c));

    for(int i=0;i<3;i++)
    {
        printf("a[%d]=%d\taddress=%u\n",i,arr[i],&arr[i]);
    }
}