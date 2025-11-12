#include <stdio.h>
#include <stdlib.h>

// Structure to represent a lecture or activity
struct Lecture {
    int start;
    int finish;
};

// Function to sort lectures by start time
int compare(const void* a, const void* b) {
    return ((struct Lecture*)a)->start - ((struct Lecture*)b)->start;
}

// Function to find the earliest finishing room that is available
int findAvailableRoom(int rooms[], int roomCount, int startTime) {
    for (int i = 0; i < roomCount; i++) {
        if (rooms[i] <= startTime) {
            return i; // Room available
        }
    }
    return -1; // No room available
}

// Function for interval partitioning
void intervalPartitioning(struct Lecture lectures[], int n) {
    qsort(lectures, n, sizeof(struct Lecture), compare);

    int rooms[n];   // stores finish times of current lectures in each room
    int roomCount = 0;

    printf("\nLecture assignments:\n");

    for (int i = 0; i < n; i++) {
        int room = findAvailableRoom(rooms, roomCount, lectures[i].start);

        if (room == -1) {
            // No existing room available, create a new one
            room = roomCount++;
            printf("Lecture (%d, %d) → Room %d (new)\n",
                   lectures[i].start, lectures[i].finish, room + 1);
        } else {
            printf("Lecture (%d, %d) → Room %d\n",
                   lectures[i].start, lectures[i].finish, room + 1);
        }

        // Update finish time for the assigned room
        rooms[room] = lectures[i].finish;
    }

    printf("\nMinimum number of rooms required = %d\n", roomCount);
}

// Driver Code
int main() {
    int n;
    printf("Enter number of lectures: ");
    scanf("%d", &n);

    struct Lecture lectures[n];
    printf("Enter start and finish time of each lecture:\n");
    for (int i = 0; i < n; i++) {
        printf("Lecture %d: ", i + 1);
        scanf("%d %d", &lectures[i].start, &lectures[i].finish);
    }

    intervalPartitioning(lectures, n);
    return 0;
}
