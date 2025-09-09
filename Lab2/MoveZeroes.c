#include<stdio.h>

 void movezeroes(int arr[],int size)
 {

    int i;int count=0;
     for(i=0;i<size-1;i++)
    {
       if(arr[i] ==0)
       {
        count++;
       }
    }
    while(count!=0)
    {

    
    for(i=0;i<size-1;i++)
    {
       if(arr[i] ==0)
       {
        arr[i]=arr[i+1];
        arr[i+1]=0;
       }
    }
    count--;
 }
}
int main()
{
    int len1=0;
    printf("Enter number of elements\n ");
    scanf("%d",&len1);
    int arr[len1];
    int len=sizeof(arr) / sizeof(arr[0]);
    printf("Enter %d elements\n",len);
    for(int i=0;i<len;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Array elements:\n");
    for(int i=0;i<len;i++)
    {
        printf( "%d ",arr[i]);
    }
    printf("\n");
    movezeroes(arr,len);
     printf("Array elements after moving zeroes to last:\n");
    for(int i=0;i<len;i++)
    {
        printf( "%d ",arr[i]);
    }
    return 0;
}