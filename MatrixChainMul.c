#include <stdio.h>
#include <limits.h>

void printParenthesis(int i, int j, int n, int s[n][n], char *name) {
    if (i == j) {
        printf("%c", (*name)++);  // Print matrix name (A, B, C,...)
        return;
    }

    printf("(");
    printParenthesis(i, s[i][j], n, s, name);
    printParenthesis(s[i][j] + 1, j, n, s, name);
    printf(")");
}

void matrixChainOrder(int p[], int n) {
    int m[n][n];
    int s[n][n];
    int i, j, k, L, q;

    // cost is zero when multiplying one matrix
    for (i = 1; i < n; i++)
        m[i][i] = 0;

    for (L = 2; L < n; L++) { // L = chain length
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;

            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;  // store split point
                }
            }
        }
    }

    printf("Minimum number of multiplications: %d\n", m[1][n - 1]);

    char name = 'A';
    printf("Optimal Parenthesization: ");
    printParenthesis(1, n - 1, n, s, &name);
    printf("\n");
}

int main() {
    int arr[] = {10, 30, 5, 60};
    int n = sizeof(arr) / sizeof(arr[0]);

    matrixChainOrder(arr, n);
    return 0;
}
