import java.util.*;

class BST{
    class Node{
        int data;
        Node left;
        Node right;

        Node(int data){
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }

    Node root;

    private Node BuildTree(ArrayList<Integer> arr, int s, int e){
        if(s > e) return null;
        int m = (s+e)/2;
        Node root = new Node(arr.get(m));
        root.left = BuildTree(arr, s, m-1);
        root.right = BuildTree(arr, m+1, e);
        return root;
    }

    private void insert(Node root, int data){
        if(root.data > data){
            if(root.left != null){
                insert(root.left, data);
            }else{
                root.left = new Node(data);
            }
        }else{
            if(root.right != null){
                insert(root.right, data);
            }else{
                root.right = new Node(data);
            }
        }
    }

    BST(){
        this.root = null;
    }

    BST(ArrayList<Integer> arr){
        this.root = BuildTree(arr, 0, arr.size()-1);
    }

    void insert(int data){
        if(root == null){
            root = new Node(data);
            return;
        }

        insert(root, data);
    }


    void printTree(){
        if(root == null){
            return;
        }
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()){
            int n = q.size();
            while(n-- > 0){
                Node curr = q.poll();
                System.out.print(curr.data + " ");
                if(curr.left != null) q.add(curr.left);
                if(curr.right != null) q.add(curr.right);
            }
            System.out.println();
        }
    }

    public static void main(String []args){
        BST b = new BST();

        ArrayList<Integer> arr = new ArrayList<>(Arrays.asList(1,2,3,4,5,6,7));
        BST b1 = new BST(arr);


        b.insert(5);
        b.insert(2);
        b.insert(9);
        b.insert(1);
        b.insert(4);
        b.insert(7);
        b.insert(14);
        b.insert(3);
        b.insert(6);
        b.insert(8);
        b.insert(11);

        b1.insert(8);

        b1.printTree();

    }
}