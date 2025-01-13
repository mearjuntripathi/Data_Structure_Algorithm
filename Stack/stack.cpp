#include <iostream>
using namespace std;

template <typename T>
class Node {
    T data;     
    Node* next;

public:
    Node(T data, Node* next = NULL) {
        this->data = data;
        this->next = next; 
    }

    T get_data() { return data; }  // Getter for data
    void set_data(T data) { this->data = data; }  // Setter for data

    Node* get_next_node() { return next; }  // Getter for next node
    void set_next_node(Node* next) { this->next = next; }  // Setter for next node
};

template <typename T>
class Stack {
    Node<T>* head;  

public:
    Stack() { head = NULL; }

    bool isEmpty(); 

    void push(T data); 

    T pop();  

    T peak();  
};

template <typename T>
bool Stack<T>::isEmpty() {
    return head == NULL; 
}

template <typename T>
void Stack<T>::push(T data) {
    Node<T>* newNode = new Node<T>(data, head);  
    head = newNode; 
}

template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        cout << "Stack is Under-flow condition" << endl;
        return T(); 
    }
    Node<T>* temp = head; 
    T data = head->get_data(); 
    head = head->get_next_node(); 
    delete temp;  
    return data; 
}

template <typename T>
T Stack<T>::peak() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return T(); 
    }
    return head->get_data(); 
}

int main() {
    Stack<int> s;  

    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);

    cout << s.pop() << endl;  
    cout << s.pop() << endl;  
    cout << s.pop() << endl;  

    s.push(11);

    cout << s.pop() << endl;  
    cout << s.pop() << endl;  


    return 0;
}
