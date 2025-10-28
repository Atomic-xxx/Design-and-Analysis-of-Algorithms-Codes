#include <stdio.h>

// Function to compute x^n using divide and conquer
double power(double x, int n) {
    if (n == 0) return 1;          // base case
    if (n == 1) return x;          // base case

    double half = power(x, n / 2);

    if (n % 2 == 0)
        return half * half;        // n is even
    else
        return x * half * half;    // n is odd
}

int main() {
    double x;
    int n;

    printf("Enter base x: ");
    scanf("%lf", &x);

    printf("Enter exponent n: ");
    scanf("%d", &n);

    double result = power(x, n);

    printf("%.2lf ^ %d = %.2lf\n", x, n, result);

    return 0;
}
