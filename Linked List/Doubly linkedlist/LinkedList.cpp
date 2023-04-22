#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        Node *prev_node;
        int data;
        Node *next_node;
    
        Node(){prev_node = NULL; next_node = NULL;}
        Node(int data);
        
        Node* get_next_node();
        Node* get_prev_node();
        int get_data();

        void set_next_node(Node*);
        void set_prev_node(Node*);
        void set_data(int);
};

Node :: Node(int data){this->data = data;}

Node* Node :: get_next_node(){return next_node;}

Node* Node :: get_prev_node(){return prev_node;}

int Node :: get_data(){return data;}

void Node :: set_next_node(Node *next_node){this->next_node = next_node;}

void Node :: set_prev_node(Node *prev_node){this->prev_node = prev_node;}

void Node :: set_data(int data){this->data = data;}

class LinkList{
    public:
        Node *head,*tail;

        int length;

        LinkList() {
            head = tail = NULL;
            length = 0;
        }

        bool empty();

        void push_front(int);

        void push_back(int);

        void insert(int, int);

        int pop_front();

        int pop_back();

	    int remove(int);

        bool deletion(int);

        void print();

        void print_reverse();
};

bool LinkList ::empty(){
    return (head == NULL || tail == NULL);
}

void LinkList :: push_front(int data){
    Node *new_node = new Node(data);
    if(empty()){
        head = tail = new_node;
        return;
    }
    new_node->set_next_node(head);
    head->set_prev_node(new_node);
    length++;
    head = new_node;
}

void LinkList :: push_back(int data){
    Node *new_node = new Node(data);
    if(empty()){
        head = tail = new_node;
        return;
    }
    new_node->set_prev_node(tail);
    tail->set_next_node(new_node);
    length++;
    tail = new_node;
}

void LinkList :: insert(int data, int position){
    if(position > length){
        cout<< "Sorry your position is much big as length of list" << endl;
        return;
    }
    if(position == 0){
        push_front(data);
        return;
    }
    if(position == length+1){
        push_back(data);
        return;
    }
    Node *new_node = new Node(data);
    Node *temp_node = head;
    int i=0;
    while(i<position-1){
        temp_node = temp_node->get_next_node();
        i++;
    }
    new_node->set_next_node(temp_node->get_next_node());
    new_node->set_prev_node(temp_node);

    temp_node->get_next_node()->set_prev_node(new_node);
    temp_node->set_next_node(new_node);
}

int LinkList :: pop_front(){
    if(empty()){
        cout << "Your list is empty" << endl;
        return -1;
    }
    if(head->get_next_node() == NULL)
    {
        int data = head->get_data();
        head = tail = NULL;
        return data;
    }
    Node *temp_node = head;
    head = temp_node->get_next_node();
    head->set_prev_node(NULL);
    int data = temp_node->get_data();
    delete(temp_node);
    length--;
    return data;
}

int LinkList :: pop_back(){
    if(empty()){
        cout << "Your list is empty" << endl;
        return -1;
    }
    if(tail->get_prev_node() == NULL)
    {
        int data = tail->get_data();
        head = tail = NULL;
        return data;
    }
    Node *temp_node = tail;
    tail = temp_node->get_prev_node();
    tail->set_next_node(NULL);
    int data = temp_node->get_data();
    delete(temp_node);
    length--;
    return data;
}

int LinkList :: remove(int position){
    if(empty()){
        cout << "Your List is Empty" <<endl;
        return -1;
    }
    if(position > length || position < 0){
        cout<<"Enter valid Position"<<endl;
        return -1;
    }
    if(position == 0)   return pop_front();

    if(position == length)   return pop_back();

    int i = 0;
    Node* temp_node = head;
    while(i<position-1){
        temp_node = temp_node->get_next_node();
        i++;
    }
    Node *temp = temp_node->get_next_node();
    temp_node->set_next_node(temp->get_next_node());
    temp->get_next_node()->set_prev_node(temp_node);

    int data = temp->data;
    delete(temp);
    length--;
    return data;
}

bool LinkList :: deletion(int num){
    if(empty()){
        cout << "Your List is Empty" <<endl;
        return false;
    }
    if(head->get_data() == num){
        pop_front();
        return true;
    }
    Node *temp_node = head;
    Node *temp = temp_node->get_next_node();
    while(temp->get_data() != num && temp->get_next_node() != NULL){
        temp = temp->get_next_node();
        temp_node = temp_node->get_next_node();
    }
    if(temp->get_data() == num){
        temp_node->set_next_node(temp->get_next_node());
        temp->get_next_node()->set_prev_node(temp_node);
        delete(temp);
        length--;
        return true;
    }
    return false;
}

void LinkList :: print(){
    if(empty()){
        cout<<"Your list is empty"<<endl;
        return;
    }
    cout << "Your entered list is from head : NULL <=> ";
    Node *temp_node = head;
    while(temp_node != NULL){
        cout << temp_node->get_data() << " <=> ";
        temp_node = temp_node->get_next_node();
    }
        cout << "NULL" << endl;
}

void LinkList :: print_reverse(){
    if(empty()){
        cout<<"Your list is empty"<<endl;
        return;
    }
    cout << "Your entered list is from tail : NULL <=> ";
    Node *temp_node = tail;
    while(temp_node != NULL){
        cout << temp_node->get_data() << " <=> ";
        temp_node = temp_node->get_prev_node();
    }
        cout << "NULL" << endl;
}


int main(){
    LinkList l;
    l.push_front(2);
    l.push_front(1);
    l.push_front(0);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    l.insert(1,1);
    cout << "length is " << l.length << endl;
    l.print();
    l.print_reverse();
    cout << "removing index 1 is " << l.deletion(1) << endl;
    cout << "length is " << l.length << endl;
    l.print();
    l.print_reverse();
}
