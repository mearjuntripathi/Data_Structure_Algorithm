/*
    This is a program to understand a stack with concept of dynamic programming
    use of linklist
*/
#include <bits/stdc++.h>
using namespace std;

class Node{
    public :
        int data;
        Node *next;

        Node (int d, Node* n){
            this->data = d;
            this->next = n;
        }
};

class Stack{
    
    Node *head;

    public:

        Stack() { head = NULL; }

        bool isEmpty();

        void push(int data);

        int pop();

        int peak();
};

bool Stack :: isEmpty(){
    return head == NULL;
}

void Stack :: push(int data){
    Node *newNode = new Node(data, head);
    head = newNode;
}

int Stack :: pop(){
    if(isEmpty()){
        cout<<"Stack is Under-flow condition"<<endl;
        return -1;
    }
    Node *temp = head;
    int data = head->data;
    head = head->next;
    free(temp);
    return data;
}

int Stack :: peak(){
    return head -> data;
}

int main(){
    Stack s;
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);
    cout<<s.pop() << endl;
    cout<<s.pop() << endl;
    cout<<s.pop() << endl;
    s.push(11);
    cout<<s.pop() << endl;
    cout<<s.pop() << endl;
}
