#include <stdio.h>
#include <limits.h>

// Function to find maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find maximum of three numbers
int max3(int a, int b, int c) {
    return max(max(a, b), c);
}

// Function to find the maximum subarray sum that crosses the midpoint
int maxCrossingSum(int arr[], int low, int mid, int high) {
    // Left sum (must include arr[mid])
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > left_sum) {
            left_sum = sum;
        }
    }

    // Right sum (must include arr[mid+1])
    sum = 0;
    int right_sum = INT_MIN;
    for (int j = mid + 1; j <= high; j++) {
        sum += arr[j];
        if (sum > right_sum) {
            right_sum = sum;
        }
    }

    // Return sum of elements on left and right of mid
    return left_sum + right_sum;
}

// Function to return maximum subarray sum using Divide and Conquer
int maxSubArraySum(int arr[], int low, int high) {
    // Base case: only one element
    if (low == high) {
        return arr[low];
    }

    // Find middle point
    int mid = (low + high) / 2;

    // Return maximum of three cases:
    // 1. Maximum subarray sum in left half
    // 2. Maximum subarray sum in right half
    // 3. Maximum subarray sum crossing the midpoint
    return max3(
        maxSubArraySum(arr, low, mid),
        maxSubArraySum(arr, mid + 1, high),
        maxCrossingSum(arr, low, mid, high)
    );
}

// Driver code
int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int max_sum = maxSubArraySum(arr, 0, n - 1);
    printf("Maximum Subarray Sum is %d\n", max_sum);

    return 0;
}
