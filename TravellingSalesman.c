#include <stdio.h>
#include <limits.h>

#define N 4 // Number of cities
#define INF 99999

int dist[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int dp[1 << N][N]; // DP table

// Recursive function to find the minimum cost
int tsp(int mask, int pos) {
    if (mask == (1 << N) - 1) // All cities visited
        return dist[pos][0];  // Return to starting city

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INF;
    for (int city = 0; city < N; city++) {
        if ((mask & (1 << city)) == 0) { // If city not visited
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            if (newAns < ans)
                ans = newAns;
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    // Initialize dp array
    for (int i = 0; i < (1 << N); i++)
        for (int j = 0; j < N; j++)
            dp[i][j] = -1;

    int result = tsp(1, 0); // Start from city 0 (mask = 0001)
    printf("Minimum cost of Travelling Salesman tour: %d\n", result);

    return 0;
}
