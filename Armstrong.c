#include <stdio.h>
#include <math.h>

int main() {
    int num;
    int count=0;
    printf("Enter a number: \n");
    scanf("%d", &num);
    int copy=num;
    int x=num;
    int sum=0;
    while(copy>0)
    {
        copy=copy/10;
        count++;
    }
    printf("Number of digits =%d\n",count);
    while(x>0)
    {
        int d=x%10;
        sum = sum + (int)(pow(d, count) + 0.5);

        x=x/10;
    }
    printf("Sum =%d\n",sum);

    if(sum == num)
    {
        printf("The entered number is an Armstrong Number\n");
    }
    else
    {
        printf("The entered number is not an Armstrong Number\n");
    }

    return 0;
}



















































