#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node *next_node;
    int data;
    struct Node *prev_node;
} Node;

int is_empty(Node* node){
    return node == NULL;
}

// Insertion function prototype in double linkedlist
void add_at_begining(Node*, int);

void add_at_last(Node*, int);

void add_at_position(Node*, int, int);


// Deletion function prototype in double linkedlist
int del_from_begining(Node*);

int del_from_last(Node*);

int del_from_position(Node*,int);


// Traversal function prototype in linkedlist
void seach(Node*);

void reverse(Node*);

int main(){
    Node *head, *tail;
    int length = -1;

}

// Insertion function definition

void add_at_begining(Node *node, int data){
    Node *new = (Node*)malloc(sizeof(Node));
    new->data = data;
    new->prev_node = NULL;
    if(is_empty())
    node->prev_node = new;
    new->next_node = node;
}