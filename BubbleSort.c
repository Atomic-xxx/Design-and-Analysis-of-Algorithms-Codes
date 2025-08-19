#include <stdio.h>

void bubbleSort(int arr[], int n)
 {
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
     {
        for (j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
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
    bubbleSort(arr, len);
     printf("Array elements after sorting:\n");
    for(int i=0;i<len;i++)
    {
        printf( "%d ",arr[i]);
    }
    return 0;
}

