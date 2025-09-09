#include <stdio.h>

void BinarySearch(int arr[],int num,int len)
{
    
    int low=0;
    int high=len-1;
    
    int count=0;
    while(low <= high)
    {
        int mid=(low+high)/2;
    if(arr[mid] == num)
    {
        printf("Element found at position %d\n",mid+1);
        count++;
        break;
    }
    else if(arr[mid]< num)
    {
        low=mid+1;
    }
    else if(arr[mid]> num)
    {
        high=mid-1;
    }
    
    
}
if(count ==0)
{
    printf("Element not found");
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
    int num;
    printf("Enter a number to be searched\n");
    scanf("%d",&num);
    BinarySearch(arr,num,len);
    return 0;
}