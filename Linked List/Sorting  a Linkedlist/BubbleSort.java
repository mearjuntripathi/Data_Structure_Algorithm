class Node{
    private int data;
    private Node next;

    // constructer
    public Node(){
        next = NULL;
    }

    public Node(int data){
        this.data = data;
    }

    public Node(int data, Node next){
        this.next = next;
        this.data = data;
    }

    public int getData() { return data; }

    public Node getNextNode() { return next; }

    public void setData(int data) { this.data = data; }

    public void setNextNode(Node next) { this.next = next; }

}

class BubbleSort{
    Node head;
    int length;

    public BubbleSort(){
        head = null;
        length = 0;
    }

    public void swap(Node first, Node second){
        Node temp = first;
        temp.setNextNode(second.getNextNode());
        second.setNextNode(first.getNextNode());
        first = second;
        second = temp;
    }


    public void pushFront(int data){
        Node newNode = new Node(data,head);
        head = newNode;
        length++;
    }


    public int pop(){
        if(isEmpty()){
            System.out.println("Your list is empty!");
            return -1;
        }
        int data = head.getData();
        head = head.getNextNode();
        length--;
        return data;
    }


    public static void main(String args[]){
        BubbleSort s;
        s.push(11);
        s.push(21);
        s.push(1);
        s.push(51);
        s.push(15);
        s.push(13);
        s.push(34);
    }

}