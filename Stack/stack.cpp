/*
    This is a program to understand a stack with concept of dynamic programming
    use of linklist
*/
#include <bits/stdc++.h>
using namespace std;

class Node{
    
        int data;
        Node *next;

    public :
        Node (int data, Node* next){
            this->data = data;
            this->next = next;
        }

        int get_data(){return data;}

        void set_data(int data){this->data = data;}

        Node* get_next_node(){return next;}

        void set_next_node(Node *next){this->next = next;}
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
    int data = head->get_data();
    head = head->get_next_node();
    free(temp);
    return data;
}

int Stack :: peak(){
    return head -> get_data();
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
