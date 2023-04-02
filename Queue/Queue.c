#include<stdio.h>
#include<stdlib.h>

// int *Queue;
// int front,rear,n;

// int is_empty(){
//     return (front == -1 || rear == -1);
// }

// void enqueue(int data){
//     if(is_empty()){
//         front=rear=0;
//         Queue[rear] = data;
//         return;
//     }
//     if(rear == n-1){
//         printf("\nQueue extend limits\n");
//         return;
//     }
//     Queue[++rear] = data;
// }

// int dequeue(){
//     if(is_empty()){
//         printf("\nQueue is empty\n");
//         return -1;
//     }

//     if(front == rear){
//         int data = Queue[front];
//         front = rear = -1;
//         return data;
//     }

//     return Queue[front++];
// }

// int main(){
//     printf("\nEnter a limit of Queue: ");
//     scanf("%d",&n);
    
//     Queue = (int*)malloc(n*sizeof(int));
//     rear = front = -1;

//     enqueue(1);
//     enqueue(2);
//     enqueue(3);
//     enqueue(4);
//     enqueue(5);
//     enqueue(6);
//     enqueue(7);

//     printf("%d\n",dequeue());
//     printf("%d\n",dequeue());
//     printf("%d\n",dequeue());
//     printf("%d\n",dequeue());
//     printf("%d\n",dequeue());
//     printf("%d\n",dequeue());
//     printf("%d\n",dequeue());
//     printf("%d\n",dequeue());
// }

                            // linkedlist module of Queue

struct Queue_node{
    int data;
    struct Queue_node* next;
}*front,*rear;

void enqueue(int data);

int dequeue();

int is_empty();

int main(){
    front = rear = NULL;
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);

    printf("%d\n",dequeue());
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());
}

int is_empty(){
    return (rear == NULL || front == NULL);
}

void enqueue(int data){
    struct Queue_node *newNode;
    newNode = (struct Queue_node*)malloc(sizeof(struct Queue_node));
    newNode->data = data;
    
    if(is_empty()){
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

int dequeue(){
    if(is_empty()){
        printf("\nQueue is empty\n");
        return -1;
    }

    struct Queue_node *temp = front;

    if(front->next == NULL)
        front = rear = NULL;
    else front = front->next;

    int data = temp->data;
    free(temp);
    return data;
}