import java.util.*;

class Node{
    int data;
    Node next;

    public Node(int data){
        this.data = data;
        this.next = null;
    }

    public int getData() {return data;}

    public void setData(int data) {this.data = data;}

    public Node getNextNode(){return next;}

    public void setNextNode(Node next){this.next = next;}
}

class Queue{
    Node front,rear;
    
    public Queue(){
        front = rear = null;
    }

    public boolean isEmpty(){
        return (rear == null || front == null);
    }

    public void EnQueue(int data){
        Node newNode = new Node(data);
        
        if(isEmpty()){
            front = rear = newNode;
            return;
        }

        rear.setNextNode(newNode);
        rear = newNode;
    }

    public int DeQueue(){
        if(isEmpty()){
            System.out.println("Queue is empty");
            return -1;
        }

        int data = front.getData();

        if(front.getNextNode() == null)
            front = rear = null;
        else front = front.getNextNode();

        return data;
    }

    public static void main(String []arg){
        Queue q = new Queue();
        q.EnQueue(1);
        q.EnQueue(2);
        q.EnQueue(3);
        q.EnQueue(4);
        q.EnQueue(5);
        q.EnQueue(6);

        System.out.println(q.DeQueue());
        System.out.println(q.DeQueue());
        System.out.println(q.DeQueue());
        System.out.println(q.DeQueue());
        System.out.println(q.DeQueue());
        System.out.println(q.DeQueue());
        System.out.println(q.DeQueue());
    }
}