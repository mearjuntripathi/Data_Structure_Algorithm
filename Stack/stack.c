#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack_node{
    int data;
    struct Stack_node *next;
} *head;

void push(int data);

int pop();

int isEmpty();

int main(){
    head = NULL;
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
    printf("\n%d",pop());
}

int isEmpty(){
    return head == NULL;
}

void push(int d){
    struct Stack_node *newNode;
    newNode = (struct Stack_node*)malloc(sizeof(struct Stack_node));
    newNode->data = d;
    newNode->next = head;
    head = newNode;
}

int pop(){
    if(isEmpty()){
        printf("\nStact is in underflow condition");
        return -1;
    }
    struct Stack_node *temp;
    temp = head;
    int d = head->data;
    head = head->next;
    free(temp);
    return d;
}

                                        //normal stack operation using array implementation


// int *stack;
// int len;
// int tos = -1;

// void push(int data){
//     if(tos == len-1){
//         printf("\nStack is overflow condition");
//         return;
//     }
//     stack[++tos] = data;
// }

// int pop(){
//     if(tos == -1){
//         printf("\nStack is underflow condition");
//         return -1;
//     }
//     int data = stack[tos];
//     tos--;
//     return data;
// }

// int main(){
//     printf("Enter how many length of stack you want to implement: ");
//     scanf("%d",&len);
//     stack = (int*)malloc(len*sizeof(int));
//     push(1);
//     push(2);
//     push(3);
//     push(4);
//     push(5);

//     printf("\n%d",pop());
//     printf("\n%d",pop());
//     printf("\n%d",pop());
//     printf("\n%d",pop());
//     printf("\n%d",pop());
// }