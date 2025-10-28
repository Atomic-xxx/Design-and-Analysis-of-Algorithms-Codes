//Time Complexity
//Worst Case : → O(n²) [Reversed array]
//Average Case: → O(n²).
//Best Case : → O(n). [Already sorted]

//Space Complexity → O(1) (no extra array needed)

//Stable
//Adaptive

#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped;  // flag to optimize

    for (i = 0; i < n - 1; i++) {
        swapped = 0;  // assume no swap happened yet

        // Last i elements are already sorted, so we reduce inner loop
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = 1;  // swap happened
            }
        }

        // If no two elements were swapped → array is already sorted
        if (swapped == 0)
            break;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
