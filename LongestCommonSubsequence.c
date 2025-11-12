#include <stdio.h>
#include <string.h>

// Function to find length of LCS
int lcs(char X[], char Y[], int m, int n) {
    int L[m + 1][n + 1];  // DP table

    // Build the table in bottom-up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = 1 + L[i - 1][j - 1];
            else
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
        }
    }

    // L[m][n] contains length of LCS
    return L[m][n];
}

// Function to print LCS string as well
void printLCS(char X[], char Y[], int m, int n) {
    int L[m + 1][n + 1];

    // Fill L[][] using DP
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = 1 + L[i - 1][j - 1];
            else
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
        }
    }

    // Now construct the LCS string from the table
    int index = L[m][n];
    char lcsStr[index + 1];
    lcsStr[index] = '\0';  // null terminate the string

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcsStr[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    printf("\nLongest Common Subsequence: %s\n", lcsStr);
    printf("Length of LCS: %d\n", L[m][n]);
}

int main() {
    char X[100], Y[100];

    printf("Enter first string: ");
    scanf("%s", X);
    printf("Enter second string: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    printLCS(X, Y, m, n);

    return 0;
}
