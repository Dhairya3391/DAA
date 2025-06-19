#include <stdio.h>
int main(){
    int a[100000];
    int n, i, j = 0;
    printf("Enter the number: ");
    scanf("%d", &n);
    printf("Factors of %d are: ", n);
    for(i = 1; i <= n; i++){    
        if(n % i == 0){
            a[j] = i;
            j++;
        }
    }
    for(i = 0; i < j; i++){
        printf("%d ", a[i]);
    }
}