#include<stdio.h>
int power(int base, int exp) {
    if (exp < 0) {
        printf("Power is not defined for negative exponents.\n");
        return 0;
    }
    if (exp == 0) {
        return 1; 
    }
    return base * power(base, exp - 1);
}

int main() {
    int base, exp;
    printf("Enter base and exponent: ");
    scanf("%d %d", &base, &exp);
    
    int result = power(base, exp);
    if (result != 0) {
        printf("%d raised to the power of %d = %d\n", base, exp, result);
    }
    
    return 0;
}