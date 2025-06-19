#include<stdio.h>

int main(){
    int i, n;
    int sum = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Sum is not defined for negative numbers.\n");
        return 0;
    }
    for (i = 1; i <= n; ++i) {
        sum += i;
    }
    printf("Sum of first %d natural numbers = %d\n", n, sum);
    return 0;
}