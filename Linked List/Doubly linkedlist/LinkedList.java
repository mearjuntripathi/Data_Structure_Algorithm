class Node{
    Node prevNode;
    int data;
    Node nextNode;
    
    public Node(){
        this.prevNode = null;
        this.nextNode = null;
    }

    public Node(int data){
        this.data = data;
        this.prevNode = null;
        this.nextNode = null;
    }

    public int getData() { return data; }

    public Node getNextNode() { return nextNode; }

    public Node getPrevNode() { return prevNode; }

    public void setData(int data) { this.data = data; }

    public void setNextNode(Node node) { this.nextNode = node; }

    public void setPrevNode(Node node) { this.prevNode = node; }
}

class LinkedList{
    Node head,tail;

    public LinkedList(){
        head = tail = null;
    }

    public boolean isEmpty(){
        return (head == null || tail == null);
    }

    public void pushFront(int data){
        Node newNode = new Node(data);
        
        if(isEmpty()){
            head = tail = newNode;
            return;
        }

        newNode.setNextNode(head);
        head.setPrevNode(newNode);
        head = newNode;
    }

    public void pushBack(int data){
        Node newNode = new Node(data);

        if(isEmpty()){
            head = tail = newNode;
            return;
        }

        newNode.setPrevNode(tail);
        tail.setNextNode(newNode);
        tail = newNode;
    }

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
    }
}