//Time Complexity
//Worst Case : → O(n²) [In case of sorted array pivot comes to first position only]
//Average Case: → O(n log n).[On random input]
//Best Case : → O(n log n).[Pivot comes at middle after each pass dividing the array in two subparts]

//Space Complexity  (Uses stack space for recursion)
//Best Case : → O(log n)
//Worst Case : → O(n)

// Not Stable
// Not Adaptive
#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];   // choose last element as pivot
    int i = (low - 1);       // index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // if current element is <= pivot
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]); // place pivot in correct position
    return (i + 1);
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // partition the array
        int pi = partition(arr, low, high);

        // recursively sort left and right subarrays
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Utility function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
