#include<stdio.h>
int main() {
    int base, exp;
    long long result = 1;

    printf("Enter base and exponent: ");
    scanf("%d %d", &base, &exp);

    if (exp < 0) {
        printf("Power is not defined for negative exponents.\n");
        return 0;
    }

    for (int i = 0; i < exp; ++i) {
        result *= base;
    }

    printf("%d raised to the power of %d = %lld\n", base, exp, result);
    return 0;
}