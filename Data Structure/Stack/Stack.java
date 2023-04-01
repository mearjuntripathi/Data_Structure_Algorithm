import java.util.*;

class Node{
    public int data;
    public Node next;
    public Node(int data, Node next){
        this.data = data;
        this.next = next;
    }
}

class Stack{
    Node head;

    public Stack(){
        head = null;
    }

    public Boolean isEmpty() {return head == null;}

    public void push(int data){
        Node newNode = new Node(data,head);
        head = newNode;
    }

    public int pop(){
        if(isEmpty()){
            System.out.println("Stack is in underflow");
            return -1;
        }
        int data = head.data;
        head = head.next;
        return data;
    }

    public static void main(String args[]){
        Stack s = new Stack();
        s.push(11);
        s.push(23);
        s.push(1);
        s.push(12);
        System.out.println(s.pop());
        System.out.println(s.pop());
        System.out.println(s.pop());
        System.out.println(s.pop());
        System.out.println(s.pop());
    }
}