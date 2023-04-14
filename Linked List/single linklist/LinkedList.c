#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
} *head;

int length = 0;

int empty();

void push_front(int);

void push_back(int);

void insert(int,int);

int pop_front();

int pop_back();

int delete(int);

int deletion(int);

void print_list();

// int find(int);

// void reverse();

int main(void) {
    head = NULL;
    push_back(4);
    push_back(5);
    push_front(3);
    push_front(2);
    push_front(1);
    push_front(0);
    push_back(6);
    push_back(7);
    push_back(8);
    insert(9,9);
    push_back(11);
    push_back(12);
    insert(10,10);
    push_back(13);
    push_back(14);
    print_list();
    printf("first element is: %d\n",pop_front());
    print_list();
    printf("last element is: %d\n",pop_back());
    print_list();
    printf("delete 4th element is: %d\n",delete(4));
    print_list();
    printf("size is: %d",length);
}

int empty(){
    return head == NULL;
}

void push_front(int data){
    struct Node *new_node;
    new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node; 
    length++;
}

void push_back(int data){
    if(empty()){
        push_front(data);
        return;
    }
    struct Node *new_node;
    struct Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    temp->next = new_node;
    length++;
}

void insert(int data, int position){
    if(empty() || length < position){
        printf("List is sort as position please enter valid position\n");
        return;
    }

    if(position == 0){
        push_front(data);
        return;
    }

    if(position == length){
        push_back(data);
        return;
    }

    int i=0;
    struct Node *temp = head;
    while(i < position-1){
        temp = temp->next;
        i++;
    }

    struct Node *new_node;
    new_node = (struct Node*) malloc(sizeof(struct Node));

    length++;

    new_node->data = data;
    new_node->next = temp->next;
    temp->next = new_node;
}


int pop_front(){
    if(empty()){
        printf("List is empty nothing is deleted");
        return -1;
    }
    struct Node *temp = head;
    int data = temp->data;
    head = temp->next;
    length--;
    free(temp);
    return data;
}

int pop_back(){
    if(empty()){
        printf("List is empty nothing is deleted");
        return -1;
    }
    if(length == 1){
        return pop_front();
    }
    struct Node *temp_node = head;
    
    while(temp_node->next->next != NULL){
        temp_node = temp_node->next;
    }

    struct Node *temp = temp_node->next;

    temp_node->next = NULL;

    int data = temp->data;

    free(temp);
    length--;
    return data;
}

int delete(int position){
    if(empty()){
        printf("List is empty nothing is deleted");
        return -1;
    }
    if(position >= length){
        printf("List is too short as yous position so nothing is deleted");
        return -1;
    }

    if(position == 0){
        return pop_front();
    }

    if(position == length-1){
        return pop_back();
    }

    struct Node *temp_node = head;

    int i=0;
    while(i<position-1){
        temp_node = temp_node->next;
        i++;
    }
    struct Node *temp;
    temp = temp_node->next;

    temp_node->next = temp->next;

    int data = temp->data;
    free(temp);
    return data;
}

int deletion(int num){
    if(empty()){
        printf("List is empty nothing is deleted");
        return -1;
    }
    int i=0;
    struct Node temp_node = head;
    while(i<length || temp->next->data != num){
        temp_node = temp_node->next;
        i++;
    }
    if(temp_node->next->data == num){

    }
}

void print_list(){
    if(empty()){
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    while(temp != NULL){
        printf(" %d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}