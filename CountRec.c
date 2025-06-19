#include<stdio.h>
int countDigits(int n) {
    if (n < 0) {
        n = -n;
    }
    if (n == 0) {
        return 1;
    }
    return 1 + countDigits(n / 10);
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    
    int digitCount = countDigits(number) - 1 ;
    printf("Number of digits = %d\n", digitCount);
    
    return 0;
}