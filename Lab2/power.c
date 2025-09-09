#include <stdio.h>
#include <time.h>

int power(int num1, int num2) 
{
    int f=1;
    for (int i = 1; i <= num2; i++)
     {
        f = f * num1;
    }
    return f;
}

int main() {
    int num1, num2;
    clock_t start, end;
    double cpu_time_used;

    // start time
    start = clock();

    // -------- CODE BLOCK TO TEST --------
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    int x = power(num1, num2);
    printf("%d raise to the power %d is %d\n", num1, num2, x);
    // -------------------------------------

    // end time
    end = clock();

    // calculate execution time
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", cpu_time_used);

    return 0;
}
