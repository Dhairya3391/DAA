#include<stdio.h>

int Factors(int n, int i) {
    if (i > n) {
        return 0;
    }
    if (n % i == 0) {
        printf("%d ", i);
    }
    return Factors(n, i + 1);
}

int main(){
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    printf("Factors of %d are: ", n);
    Factors(n, 1);
    printf("\n");
    return 0;

}