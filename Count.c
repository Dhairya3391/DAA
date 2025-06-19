#include<stdio.h>
int main() {
    int i;
    printf("Enter a number: ");
    scanf("%d", &i);

    int count = 0;
    if (i == 0) {
        count = 1;
    } else {
        while (i != 0) {
            i /= 10;
            count++;
        }
    }
    printf("Number of digits = %d\n", count);
    return 0;
}