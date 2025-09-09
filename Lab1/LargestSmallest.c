#include <stdio.h>

int main() {
    int n, arr[100], max, min;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    max =arr[0];
     min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
         max = arr[i];
        if (arr[i] < min) 
        min = arr[i];
    }

    printf("Largest: %d\n", max);
    printf("Smallest: %d\n", min);
    return 0;
}
