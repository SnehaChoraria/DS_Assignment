#include <stdio.h>
#define SUB 10
#define MAIN 20

void display(int a[],int n){
    for(int i=0;i<n;i++) 
    printf("%d ",a[i]);
}

void insertEnd(int a[],int *n,int max){
    if(*n==max) 
    return;
    scanf("%d",&a[(*n)++]);
}

void insertBeg(int a[],int *n,int max){
    if(*n==max) 
    return;
    for(int i=*n;i>0;i--) 
    a[i]=a[i-1];
    scanf("%d",&a[0]);
    (*n)++;
}

void insertPos(int a[],int *n,int max,int p){
    if(*n==max||p<0||p>*n) 
    return;
    for(int i=*n;i>p;i--) 
    a[i]=a[i-1];
    scanf("%d",&a[p]);
    (*n)++;
}

void delEnd(int *n){
    if(*n>0) 
    (*n)--;
}

void delBeg(int a[],int *n){
    if(*n==0) return;
    for(int i=0;i<*n-1;i++) 
    a[i]=a[i+1];
    (*n)--;
}

void delPos(int a[],int *n,int p){
    if(*n==0||p<0||p>=*n) 
    return;
    for(int i=p;i<*n-1;i++) 
    a[i]=a[i+1];
    (*n)--;
}

void reverseTemp(int a[],int n){
    int t[n];
    for(int i=0;i<n;i++) 
    t[i]=a[n-1-i];
    display(t,n);
}

void reverseIn(int a[],int n){
    int t;
    for(int i=0;i<n/2;i++){
        t=a[i];
        a[i]=a[n-1-i];
        a[n-1-i]=t;
    }
}

void copySub(int s[],int sn,int m[],int *mn){
    for(int i=0;i<sn && *mn<MAIN;i++) m[(*mn)++]=s[i];
}

void mergeDesc(int a[],int n1,int b[],int n2){
    int c[n1+n2],i=0,j=0,k=0;
    while(i<n1 && j<n2)
        c[k++]=(a[i]>b[j])?a[i++]:b[j++];
    while(i<n1) c[k++]=a[i++];
    while(j<n2) c[k++]=b[j++];
    display(c,k);
}

int sumIter(int a[],int n){
    int s=0;
    for(int i=0;i<n;i++) s+=a[i];
    return s;
}

int sumRec(int a[],int n){
    if(n==0) return 0;
    return a[n-1]+sumRec(a,n-1);
}

void search(int a[],int n,int x){
    for(int i=0;i<n;i++)
        if(a[i]==x){
            printf("Found at index %d\n",i);
            return;
        }
    printf("Not found\n");
}

void oddEven(int a[],int n){
    printf("Even: ");
    for(int i=0;i<n;i++) if(a[i]%2==0) printf("%d ",a[i]);
    printf("\nOdd: ");
    for(int i=0;i<n;i++) if(a[i]%2!=0) printf("%d ",a[i]);
    printf("\n");
}

void posNeg(int a[],int n){
    printf("Positive: ");
    for(int i=0;i<n;i++) if(a[i]>=0) printf("%d ",a[i]);
    printf("\nNegative: ");
    for(int i=0;i<n;i++) if(a[i]<0) printf("%d ",a[i]);
    printf("\n");
}

int main(){
    int SubArray1[SUB],SubArray2[SUB],MainArray[MAIN];
    int s1=0,s2=0,m=0,ch,p,x;

    while(1){
        printf("\n1 InsertEnd\n2 InsertBeg\n3 InsertPos\n4 DelEnd\n5 DelBeg\n6 DelPos\n");
        printf("\n7 ReverseTemp\n8 ReverseIn\n9 Sum\n10 Search\n11 Separate\n0 Exit\n");
        scanf("%d",&ch);

        switch(ch){
            case 1: insertEnd(MainArray,&m,MainArray); break;
            case 2: insertBeg(MainArray,&m,MainArray); break;
            case 3: scanf("%d",&p); insertPos(MainArray,&m,MainArray,p); break;
            case 4: delEnd(&m); break;
            case 5: delBeg(MainArray,&m); break;
            case 6: scanf("%d",&p); delPos(MainArray,&m,p); break;
            case 7: reverseTemp(MainArray,m); continue;
            case 8: reverseIn(MainArray,m); break;
            case 9: printf("Sum=%d %d\n",sumIter(MainArray,m),sumRec(MainArray,m)); break;
            case 10: scanf("%d",&x); search(MainArray,m,x); break;
            case 11: oddEven(MainArray,m); posNeg(MainArray,m); continue;
            case 0: return 0;
        }
        display(MainArray,m);
    }
}
