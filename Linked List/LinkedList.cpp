#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node *next;

    // Constructor
        Node();
        Node(int);
        Node(int,Node*);
        
    // function to get value
        int get_data();
        Node* get_next_node();

    // function to set value
        void set_next_node(Node*);
        void set_data(int);
};

// Constructor
Node :: Node() {};

Node :: Node(int data){
    this->data = data;
    this->next = NULL;
}

Node :: Node(int data, Node *next){
    this->data = data;
    this->next = next;
}

int Node :: get_data() { 
    return data; 
}

Node* Node :: get_next_node() { 
    return next; 
}

void Node :: set_data(int data) { 
    this->data = data; 
}

void Node :: set_next_node(Node *next) { 
    this->next = next; 
}




class LinkedList{
    Node *head;
    int length;

    public:
    // Constructor to create LinkedList
        LinkedList();

    // check is list is empty
        bool empty();

    // Check size

        int size();

    // Insertion
        void push_front(int);

        void push_back(int);

        void insert(int, int); 

    // Deletion
        int pop_front();

        int pop_back();

        int remove(int);

        bool deletion(int);

    // traversal
        void print_list();

        int find(int);

        void reverse();

    // concatenation
        friend void concate(LinkedList,LinkedList);
};

// Constructor
LinkedList :: LinkedList() { head = NULL; length = 0; }


// check empty
bool LinkedList :: empty(){ return head == NULL; }


// check the size of list
int LinkedList :: size(){ return length; }


// Insertion
void LinkedList :: push_front(int data){
    Node *new_node = new Node(data, head);
    head = new_node;
    length++;
}

void LinkedList :: push_back(int data){
    if(empty()){
        push_front(data);
        return;
    }
    Node *new_node = new Node(data);
    Node *temp_node = head;
    while(temp_node->get_next_node() != NULL){
        temp_node = temp_node->get_next_node();
    }
    temp_node->set_next_node(new_node);
    length++;
}

void LinkedList :: insert(int data, int position){
    if( size() < (position-1) ){
        cout<<"List is sort as position please enter valid position"<<endl;
        return;
    }
    if(position == 0){
        push_front(data);
        return;
    }
    if((position-1) == length){
        push_back(data);
        return;
    }

    Node *temp_node = head; 
    Node *new_node = new Node(data);
    int i=1;
    while(i<position-1){
        temp_node = temp_node->get_next_node();
        i++;
    }
    length++;

    new_node->set_next_node(temp_node->get_next_node());

    temp_node->set_next_node(new_node);
}


// deletion
int LinkedList :: pop_front(){
    if(empty()){
        cout << "List is empty" << endl;
        return -1;
    }
    int data = head->get_data();
    head = head->get_next_node();
    length--;
    return data;
}

int LinkedList :: pop_back(){
    if(empty()){
        cout << "List is empty" << endl;
        return -1;
    }
    if(size() == 1){
        return pop_front();
    }

    Node *temp_node = head;

    while(temp_node->get_next_node()->get_next_node() != NULL){
        temp_node = temp_node->get_next_node();
    }

    Node *temp = temp_node->get_next_node();
    int data = temp->get_data();

    temp_node->set_next_node(NULL);
    delete(temp);
    length--;
    return data;
}

int LinkedList :: remove(int position){
    if(empty()){
        cout << "List is empty please insert element" << endl;
        return -1;
    }

    if(position >= size()){
        cout << "List is too short as your position\n enter size 0 to size()-1" << endl;
        return -1;
    }
    
    if(position == 0)
        return pop_front();
    
    Node *temp_node = head;
    int i=1;
    while(i<position){
        temp_node = temp_node->get_next_node();
        i++;
    }

    Node *temp = temp_node->get_next_node();
    temp_node->set_next_node(temp->get_next_node());
    i = temp->get_data();

    delete(temp);
    length--;
    return i;
}

bool LinkedList :: deletion(int num){
    Node *temp_node = head;
    if(temp_node->get_data() == num){
        pop_front();
        return true;
    }

    Node *temp = temp_node->get_next_node();
    while(temp->get_data() != num && temp->get_next_node() != NULL){
        temp = temp->get_next_node();
        temp_node = temp_node->get_next_node(); 
    }

    if(temp->get_data() == num){
        temp_node->set_next_node(temp->get_next_node());
        delete(temp);
        length--;
        return true;
    }
    cout << num << " is not avilable in list" << endl;
    return false;

}

// traversal
void LinkedList :: print_list(){
    if(empty()){
        cout << "List is empty, So Please enter a value in it" << endl;
        return;
    }
    Node *temp_node = head;
    cout << "List data is : ";
    while(temp_node != NULL){
        cout << temp_node->get_data() << " => ";
        temp_node = temp_node->get_next_node();
    }
    cout << "NULL" << endl;
}

int LinkedList :: find(int num){
    Node *temp_node = head;
    int i=1;

    while(temp_node->get_data() != num && temp_node->get_next_node() != NULL){
        temp_node = temp_node->get_next_node();
        i++;
    }

    if(temp_node->get_data() == num){
        return i;
    }
    else return -1;
}

void LinkedList :: reverse(){
    
    if(empty() || size() == 1)
        return;

    Node *prev_node = NULL;
    Node *curr_node = head;
    Node *next_node = curr_node->get_next_node();
    
    curr_node->set_next_node(prev_node);

    while(next_node != NULL){
        prev_node = curr_node;
        curr_node = next_node;
        next_node = next_node->get_next_node();
        curr_node->set_next_node(prev_node);
    }
    head = curr_node;
}


// concatenation
void concate(LinkedList l1, LinkedList l2){
    Node *temp_node = l1.head;
    while(temp_node->get_next_node() != NULL){
        temp_node = temp_node->get_next_node();
    }
    Node *temp = l2.head;
    l1.length += l2.length;
    cout<<l1.length<<endl;
    temp_node->set_next_node(temp);
}

int main() {
    LinkedList l,l1;
    l.push_back(4);
    l.push_back(5);
    l.push_front(3);
    l.push_front(2);
    l.push_front(1);
    l.push_front(0);
    l.push_back(6);
    l.push_back(7);
    l.push_back(8);
    l.insert(10,10);
    l.insert(9,10);
    l1.push_back(11);
    l1.push_back(12);
    l1.push_back(13);
    l1.push_back(14);
    l.print_list();
    cout << "size of list: " << l.size()<<endl;
    cout << l.deletion(3) <<endl;
    concate(l,l1);
    l.print_list();
    l.reverse();
    l.print_list();
    cout << "size of list: " << l.size()<<endl;
}