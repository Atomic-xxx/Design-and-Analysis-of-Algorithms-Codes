#include <stdio.h>

int sl(int arr[], int len)
 {
    int l=arr[0];
    int sl=arr[0];
    for(int i=1;i<len;i++)
    {
        if(arr[i]> l)
        {
            sl=l;
            l=arr[i];
        }
        else if (arr[i] > sl && arr[i] != l)
        {
            sl = arr[i];  
        }
    }
    return sl;

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
   int num= sl(arr,len);
     printf("Second largest :%d\n",num);
    
    return 0;
}
