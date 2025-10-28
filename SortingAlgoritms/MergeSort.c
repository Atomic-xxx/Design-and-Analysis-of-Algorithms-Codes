//Time Complexity
//Worst Case : → O(n log n )
//Average Case: → O(n log n).     //Always divides array into halves → T(n) = 2T(n/2) + O(n) → O(n log n).
//Best Case : → O(n log n).

//Space Complexity → O(n) (extra array needed)

//Stable
// Not Adaptive

#include <stdio.h>

// Function to heapify a subtree rooted at index i for Min Heap
void minHeapify(int arr[], int n, int i) {
    int smallest = i;       // Initialize root as smallest
    int left = 2 * i + 1;   // left child
    int right = 2 * i + 2;  // right child

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;

        minHeapify(arr, n, smallest);
    }
}

// Function to build a Min Heap
void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}

// Heap Sort using Min Heap (stores sorted result in another array)
void heapSort(int arr[], int n) {
    int sorted[n];
    int size = n;

    // Step 1: Build Min Heap
    buildMinHeap(arr, size);

    // Step 2: Extract elements one by one
    for (int i = 0; i < n; i++) {
        // Root (smallest) is at index 0
        sorted[i] = arr[0];

        // Move last element to root
        arr[0] = arr[size - 1];
        size--;

        // Heapify the reduced heap
        minHeapify(arr, size, 0);
    }

    // Copy sorted array back
    for (int i = 0; i < n; i++)
        arr[i] = sorted[i];
}

// Utility function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted array:   ");
    printArray(arr, n);

    return 0;
}
