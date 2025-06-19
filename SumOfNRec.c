#include<stdio.h>

int sumOfN(int n) {
    if (n == 0) {
        return 0;
    }
    return n + sumOfN(n - 1);
}

int main(){
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    if(n<0){
        printf("Sum is not defined for negative numbers.\n");
        return 0;
    }
    int sum = 0;
    
    sum = sumOfN(n);
    printf("Sum of first %d natural numbers = %d\n", n, sum);
    return 0;
}