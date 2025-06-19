#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int value) {
    if(top >= MAX_SIZE - 1) {
        printf("Stack overflow\n");
    }
    stack[++top] = value;
}

int pop() {
    if(top < 0) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

int peek() {
    if(top<0){
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}

int peep(int position){
    if(position<0 || position>top){
        printf("Invalid position\n");
        return -1;
    }
    return stack[top-position+1];
}

int display() {
    if(top<0){
        printf("Stack is empty\n");
        return 0;
    }
    for(int i=top;i>=0;i--){
        printf("%d ",stack[i]);
    }
    printf("\n");
    return 0;
}

int change(int value,int position){
    if(position <= 0)
    {
        printf("\nError: Index should start from 1\n");
        return -1;
    }
    if((top-position+1) < 0)
    {
        printf("\nError: Underflow on Change\n");
        return -1;
    }
    stack[top-position+1] = value;
    return 0;
}

int main(){
    int choice,value,position;
    while(1){
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Peep\n");
        printf("5. Change\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value to push: ");
                scanf("%d",&value);
                push(value);
                break;
            case 2:
                value = pop();
                if(value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                value = peek();
                if(value != -1) {
                    printf("Top value: %d\n", value);
                }
                break;
            case 4:
                
            case 5:
                printf("Enter the value to change: ");
                scanf("%d",&value);
                printf("Enter the position to change: ");
                scanf("%d",&position);
                change(value,position);
                break;
            case 6:
                display();
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}