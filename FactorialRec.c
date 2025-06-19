#include<stdio.h>

unsigned long long factorial(int n) {
    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 0;
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    
    unsigned long long result = factorial(n);
    if (result != 0) {
        printf("Factorial of %d = %llu\n", n, result);
    }
    
    return 0;
}