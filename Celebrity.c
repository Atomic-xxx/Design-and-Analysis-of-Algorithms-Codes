#include <stdio.h>
#include <stdbool.h>

#define N 4

int M[N][N] = {
    {0, 1, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 0}, // Person 2 is celebrity
    {0, 1, 1, 0}
};

bool knows(int a, int b) {
    return M[a][b] == 1;
}

// Divide & Conquer function to find celebrity in range [start, end]
int findCelebrityDC(int start, int end) {
    if (start == end) return start; // only one person → possible celebrity

    int mid = (start + end) / 2;
    int left_celebrity = findCelebrityDC(start, mid);
    int right_celebrity = findCelebrityDC(mid + 1, end);

    // Combine step
    if (knows(left_celebrity, right_celebrity)) return right_celebrity;
    else if (knows(right_celebrity, left_celebrity)) return left_celebrity;
    else return -1; // no celebrity
}

// Verify candidate
int verifyCelebrity(int n, int candidate) {
    for (int i = 0; i < n; i++) {
        if (i != candidate) {
            if (knows(candidate, i) || !knows(i, candidate))
                return -1;
        }
    }
    return candidate;
}

int main() {
    int candidate = findCelebrityDC(0, N - 1);
    int celeb = (candidate != -1) ? verifyCelebrity(N, candidate) : -1;

    if (celeb == -1)
        printf("No celebrity found\n");
    else
        printf("Celebrity is person %d\n", celeb);

    return 0;
}
