#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

int stack[MAX];
int tos = -1;

void push(int data){
    if(tos == MAX-1){
        printf("\nStack is overflow condition");
        return;
    }
    stack[++tos] = data;
}

int pop(){
    if(tos == -1){
        printf("\nStack is underflow condition");
        return -1;
    }
    int data = stack[tos];
    tos--;
    return data;
}

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    printf("\n%d",pop());
    printf("\n%d",pop());
    printf("\n%d",pop());
    printf("\n%d",pop());
    printf("\n%d",pop());
}