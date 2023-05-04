// A Node class this create as a double linkedList
class Node{

    private Node prevNode; // this is Node which store prev Node's address
    private int data; // it store data
    private Node nextNode; // this is a node which store next Node's address;
    
    // Node constructer ---------------------

    public Node(){
        // when we create a new node so we make their previous and next node with null
        this.prevNode = null;
        this.nextNode = null;
    }

    public Node(int data){
        // it is constructer overloading which take input data value of created new node
        this.data = data;
        this.prevNode = null;
        this.nextNode = null;
    }

    // Function Decleration ------------------

    // it tell what data of that node
    public int getData() { return data; }

    // it tell which node is next
    public Node getNextNode() { return nextNode; }

    // it tell what node is pre of this node
    public Node getPrevNode() { return prevNode; }

    // it set data inside a node
    public void setData(int data) { this.data = data; }

    // it set previous node
    public void setNextNode(Node node) { this.nextNode = node; }

    // it set the next node
    public void setPrevNode(Node node) { this.prevNode = node; }
}

class LinkedList{
    // create a two node one for head and another for tail
    Node head,tail;
    int length;

    // constructer
    public LinkedList(){
        head = tail = null; // make both head and tail null when object is creted
        length=0; // assign length with zero
    }

    // check a list is empty or not
    public boolean isEmpty(){
        return (head == null || tail == null);
    }


    // insertion

    // enter data at front of list
    public void pushFront(int data){
        Node newNode = new Node(data);
        // checking node is empty or not
        if(isEmpty()){
            head = tail = newNode;
            length++;
            return;
        }
        // making connction from new note to all node at begining
        newNode.setNextNode(head);
        head.setPrevNode(newNode);
        length++;
        head = newNode;
    }

    // enter data at last of list
    public void pushBack(int data){
        Node newNode = new Node(data);
        // checking list is empty or not
        if(isEmpty()){
            head = tail = newNode;
            length++;
            return;
        }
        // make connection from new node to all rest node at last
        newNode.setPrevNode(tail);
        tail.setNextNode(newNode);
        length++;
        tail = newNode;
    }

    // this function is used to insert data at specific position
    public void insert(int data, int position){
        if(isEmpty()){
            System.out.println("List is empty");
            return;
        }
        // check given position is valid or not
        if(position > length || position < 0){
            System.out.println("Enter position well fromat");
            return;
        }
        
        if(position == 0){
            pushFront(data);
            return;
        }

        if(position == length){
            pushBack(data);
        }
        /*
            Logic is that first run loop from head to tail
            and check postion is specific postion where 
            i have to store data so i keep a addres of 
            previous and nexd of that node and put node their and 
            make connection with both node
        */
        int i = 0;
        Node tempNode = head;
        Node temp = tempNode.getNextNode();
        // travel to specific position
        while(i<position-1){
            temp = temp.getNextNode();
            tempNode = tempNode.getNextNode();
            i++;
        }

        // create a new node and make connection with it
        Node newNode = new Node(data);
        tempNode.setNextNode(newNode);
        newNode.setNextNode(temp);
        newNode.setPrevNode(tempNode);
        temp.setPrevNode(newNode);
    }


    // Deletion

    // to delete a data from front
    public int popFront(){
        // check list is empty or not
        if(isEmpty()){
            System.out.println("List is Empty");
            return -1;
        }

        // if list is only one element so make head and tali null 
        Node temp = head;
        if(head == tail){
            head = tail = null;
            length--;
            return temp.getData();
        }    
        
        // otherwise we remove link from first node to another node 
        head = head.getNextNode();
        head.setPrevNode(null);
        length--;
        return temp.getData();
    }

    // to delete from back
    public int popBack(){
        // check list is empty or not
        if(isEmpty()){
            System.out.println("Your List is Empty...");
            return -1;
        }
        
        // if list is only one element so make head and tali null 
        Node temp = tail;
        if(head == tail){
            head = tail = null;
            return temp.getData();
        }

        // otherwise we remove link from last node to another node
        tail = tail.getPrevNode();
        tail.setNextNode(null);
        length--;
        return temp.getData();
    }

    public int delete(int position){
        // check list is empty or not
        if(isEmpty()){
            System.out.println("Your List is Empty...");
            return -1;
        }
        // check position value is not a inlegal
        if(position < 0 || position > length){
            System.out.println("Enter position well fromat");
            return -1;
        }
        
        if(position == 0){
            return popFront();
        }

        if(position == length){
            return popBack();
        }

        // got to that which one want to delete and remove it
        int i = 0;
        Node tempNode = head;
        Node temp = tempNode.getNextNode();
        while(i<position-1){
            tempNode = tempNode.getNextNode();
            temp = temp.getNextNode();
            i++;
        }
        int data = temp.getData();
        temp = temp.getNextNode();
        tempNode.setNextNode(temp);
        temp.setPrevNode(tempNode);
        return data;
    }
    
     // traversal
    public void print(){
        if(isEmpty()){
            System.out.println("Your List is empty");
            return;
        }

        Node tempNode = head;
        System.out.print("Yor inserted List is from head : NULL <=> ");
        while(tempNode != null){
            System.out.print(tempNode.getData() + " <=> ");
            tempNode = tempNode.getNextNode();
        }
        System.out.print("NULL\n");
    }

    public void printReverse(){
        if(isEmpty()){
            System.out.println("Your List is empty");
            return;
        }

        Node tempNode = tail;
        System.out.print("Yor inserted List is from tail : NULL <=> ");
        while(tempNode != null){
            System.out.print(tempNode.getData() + " <=> ");
            tempNode = tempNode.getPrevNode();
        }
        System.out.print("NULL\n");
    }


    public int find(int num){
        if(isEmpty()){
            System.out.println("Your List is empty");
            return -1;
        }

        int i=0,j=length;
        Node start = head,end = tail;
        while(i != j){
            if(start.getData() == num){
                return i;
            }
            i++;
            start = start.getNextNode();
            if(end.getData() == num){
                return j;
            }
            j--;
            end = end.getPrevNode();
        }
        
        if(start.getData() == num)
            return i;

        return -1;
    }



    public static void main(String []arg){
        LinkedList l = new LinkedList();
        l.pushBack(4);
        l.pushBack(5);
        l.pushBack(6);
        l.pushFront(3);
        l.pushFront(2);
        l.pushFront(1);
        l.pushBack(7);
        l.pushBack(8);
        l.pushBack(9);
        l.pushFront(0);
        l.print();
        l.printReverse();
        System.out.println("Data is inserted in list at position 8: ");
        l.insert(8,8);
        l.print();
        l.printReverse();
        System.out.println("Length of length is : "+ l.length);
        System.out.println("Data deleted at position from 8 is: "+l.delete(8));
        l.print();
        l.printReverse();
        if(l.find(9) != -1)
            System.out.println("9 is avilable at position: "+l.find(9));
        else System.out.println("9 is n0t avilable in list");
    }
}