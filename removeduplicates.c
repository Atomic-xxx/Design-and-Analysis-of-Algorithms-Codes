#include <stdio.h>

int removeduplicates(int arr[], int n)
 {
    int i=0;
    
        for(int j=1;j<n;j++)
        {
            if(arr[j] !=arr[i])
            {
                arr[++i]=arr[j];
            }
        }
        return i+1;
    
  
}

int main() {
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
    int x=removeduplicates(arr, len);
     printf("Array elements after removing duplicates:\n");
    for(int i=0;i<x;i++)
    {
        printf( "%d ",arr[i]);
    }
    return 0;
}
