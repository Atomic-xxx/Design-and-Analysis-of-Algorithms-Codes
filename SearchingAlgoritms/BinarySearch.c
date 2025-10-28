//Time Complexity
//Worst Case : → O( log n) 
//Average Case: → O(log n). 
//Best Case : → O(1). [Element is exactly at the middle]

//Space Complexity → 
// Iterative → O(1)
// Recursive → O(log n)

#include <stdio.h>

int binarySearchRecursive(int arr[], int left, int right, int key) {
    if (left > right)
        return -1; // not found

    int mid = left + (right - left) / 2;

    if (arr[mid] == key)
        return mid;

    if (arr[mid] > key)
        return binarySearchRecursive(arr, left, mid - 1, key);
    else
        return binarySearchRecursive(arr, mid + 1, right, key);
}
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;

    int result = binarySearchRecursive(arr, n, key);

    if (result != -1)
        printf("Element %d found at index %d\n", key, result);
    else
        printf("Element %d not found\n", key);

    return 0;
}