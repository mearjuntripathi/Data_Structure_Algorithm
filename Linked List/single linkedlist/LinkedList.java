class Node{
    int data;
    Node next;

    public Node(int data){
        this.data = data;
        this.next = null;
    }

    public Node(int data, Node next){
        this.data = data;
        this.next = next;
    }

    public Node getNextNode(){ return next; }

    public int getData() {return data;}

    public void setNextNode(Node next) {this.next = next;}

    public void setData(int data) {this.data = data;}
}


class LinkedList{
    Node head;
    int length;

    // Constructor to create LinkedList
        public LinkedList(){
            head = null;
            length = 0;
        }


    // check is list is empty
        public boolean isEmpty(){
            return head == null;
        }


    // Check size
        public int size(){
            return length;
        }


    // Insertion
        public void pushFront(int data){
            Node newNode = new Node(data,head);
            head = newNode;
            length++;
        }

        public void pushBack(int data){
            if(isEmpty()){
                pushFront(data);
                return;
            }
            Node tempNode = head;
            while(tempNode.getNextNode() != null){
                tempNode = tempNode.getNextNode();
            }
            Node newNode = new Node(data);
            tempNode.setNextNode(newNode);
            length++;
        }

        public void insert(int data, int position){
            if(position > size()){
                System.out.println("We can't store this data at position: "+ position +", because list size is only "+size());
                return;
            }
            if(position == size()){
                pushBack(data);
                return;
            }
            if(position == 0){
                pushFront(data);
                return;
            }

            int i=0;
            Node tempNode = head;
            
            while(i != position - 1){
                i++;
                tempNode = tempNode.getNextNode();
            }
            
            Node newNode = new Node(data, tempNode.getNextNode());
            tempNode.setNextNode(newNode);
            length++;
        }

    // Deletion
        public int popFront(){
            if(isEmpty()){
                System.out.println("Your list is empty!");
                return -1;
            }
            int data = head.getData();
            head = head.getNextNode();
            length--;
            return data;
        }

        public int popBack(){
            if(isEmpty()){
                System.out.println("Your list is empty!");
                return -1;
            }
            if(size() == 1){
                return popFront();
            }
            Node tempNode = head;
            while(tempNode.getNextNode().getNextNode() != null){
                tempNode = tempNode.getNextNode();
            }

            int data = tempNode.getNextNode().getData();
            tempNode.setNextNode(null);
            length--;
            return data;
        }

        public int remove(int position){
            if(position >= size()){
                System.out.println("List is no long as position");
                return -1;
            }
            if(position == 0){
                return popFront();
            }
            if(position == size()-1){
                return popBack();
            }
            int i=0;
            Node tempNode = head;
            while(i<position-1){
                tempNode = tempNode.getNextNode();
                i++;
            }
            int data = tempNode.getNextNode().getData();
            tempNode.setNextNode(tempNode.getNextNode().getNextNode());
            return data;
        }

        public boolean deletion(int num){
            if(isEmpty()){
                System.out.println("List is empty!");
                return false;
            }
            Node tempNode = head;
            if(tempNode.getData() == num){
                tempNode = tempNode.getNextNode();
                head = tempNode;
                length--;
                return true;
            }
            while((tempNode.getNextNode().getData() != num) && (tempNode.getNextNode() != null)){
                tempNode = tempNode.getNextNode();
            }
            if(tempNode.getNextNode().getData() == num){
                tempNode.setNextNode(tempNode.getNextNode().getNextNode());
                length--;
                return true;
            }
            else return false;
        }

    // // traversal
        public void printList(){
            if(isEmpty()){
                System.out.println("NULL");
                return;
            }

            Node tempNode = head;
            while(tempNode != null){
                System.out.print(tempNode.getData() + " => ");
                tempNode = tempNode.getNextNode();
            }
            System.out.print("NULL\n");
        }

        public int find(int num){
            if(isEmpty()){
                System.out.println("List is empty");
                return -1;
            }
            Node tempNode = head;
            int i=0;
            while((tempNode.getData() != num) && (tempNode.getNextNode() != null)){
                tempNode = tempNode.getNextNode();
                i++;
            }
            if(tempNode.getData() == num)
                return i;
            System.out.println(num+" is not avilable in list");
            return -1;
        }

        public void reverse(){
            if(isEmpty()||size()==1)
                return;
            
            Node prevNode = null;
            Node currNode = head;
            Node nextNode = currNode.getNextNode();

            currNode.setNextNode(prevNode);

            while(nextNode != null){
                prevNode = currNode;
                currNode = nextNode;
                nextNode = nextNode.getNextNode();
                currNode.setNextNode(prevNode);
            }
            head = currNode;
        }

    // concatenation
        public static void concate(LinkedList l1, LinkedList l2){
            Node tempNode = l1.head;
            while(tempNode.getNextNode() != null){
                tempNode = tempNode.getNextNode();
            }

            tempNode.setNextNode(l2.head);
            l1.length += l2.length;
        }

    public static void main(String[] arjun){
        LinkedList l = new LinkedList();
        l.printList();
        l.pushFront(4);
        l.printList();
        l.pushFront(3);
        l.printList();
        l.pushFront(2);
        l.printList();
        l.pushFront(1);
        l.printList();
        l.pushFront(0);
        l.printList();
        l.pushBack(5);
        l.printList();
        l.pushBack(6);
        l.printList();
        l.pushBack(7);
        l.printList();
        l.pushBack(8);
        l.printList();
        l.pushBack(9);
        l.printList();
        System.out.println(l.deletion(0));
        l.printList();
        System.out.println("Position of "+9+" is "+l.find(9));
        System.out.println("size is :"+l.size());
        l.reverse();
        l.printList();
        LinkedList l1 = new LinkedList();
        l1.pushBack(10);
        l1.pushBack(11);
        l1.pushBack(12);
        l1.pushBack(13);
        l1.printList();
        System.out.println("size is :"+l1.size());
        concate(l,l1);
        l.printList();
    }
}