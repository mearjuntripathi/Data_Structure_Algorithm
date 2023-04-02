#include <bits/stdc++.h>
using namespace std;

class Node{
    
    int data;
    Node *next;
    
    public:
    
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
    
        int get_data() {return data;}

        void set_data(int data) {this->data = data;}

        Node* get_next_node() {return next;}

        void set_next_node(Node *next) {this->next = next;}
};

class Queue{
    
    Node *front,*rear;
    
    public:
    
        Queue(){
            front = NULL;
            rear = NULL; 
        }

        bool isEmpty(){return rear == NULL;}

        void enQueue(int data);

        int deQueue();
};

void Queue :: enQueue(int data){
    
    Node *newNode = new Node(data);

    if(front == NULL){
        front = rear = newNode;
        return;
    }

    rear->set_next_node(newNode);
    rear = newNode;
}

int Queue :: deQueue(){
    if(isEmpty()){
        cout<<"Queue is a empty"<<endl;
        return -1;
    }
    Node *temp = front;
    if(front->get_next_node() == NULL)
        front = rear = NULL;
    else front = front->get_next_node();

    
    int data = temp->get_data();
    delete(temp);
    return data;
}

int main(){
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    q.enQueue(6);

    // cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;

    return 0;
}