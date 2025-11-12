#include <stdio.h>

// Structure to represent an activity
struct Activity {
    int start;
    int finish;
};

// Function to sort activities by their finish times (using simple bubble sort)
void sortByFinishTime(struct Activity arr[], int n) {
    struct Activity temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].finish > arr[j + 1].finish) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to print the maximum set of activities
void activitySelection(struct Activity arr[], int n) {
    // Sort activities by finish time
    sortByFinishTime(arr, n);

    printf("Selected activities are (start, finish):\n");

    // The first activity always gets selected
    int i = 0;
    printf("(%d, %d)\n", arr[i].start, arr[i].finish);

    // Consider the rest of the activities
    for (int j = 1; j < n; j++) {
        if (arr[j].start >= arr[i].finish) {
            printf("(%d, %d)\n", arr[j].start, arr[j].finish);
            i = j; // Update the last selected activity
        }
    }
}

// Driver Code
int main() {
    int n;
    printf("Enter number of activities: ");
    scanf("%d", &n);

    struct Activity arr[n];
    printf("Enter start and finish time of each activity:\n");
    for (int i = 0; i < n; i++) {
        printf("Activity %d: ", i + 1);
        scanf("%d %d", &arr[i].start, &arr[i].finish);
    }

    activitySelection(arr, n);

    return 0;
}
