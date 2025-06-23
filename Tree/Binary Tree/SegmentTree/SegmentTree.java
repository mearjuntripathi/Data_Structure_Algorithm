import java.util.*;
import java.io.*;

class SegmentTree{
    public class Node{
        public int data;
        public int lrange, rrange;
        Node lchild, rchild;

        public Node(int lrange, int rrange, int data){
            this.lrange = lrange;
            this.rrange = rrange;
            this.data = data;
            lchild = rchild = null;
        }
    }
    public Node head;
    Node costruct_tree(int arr[], int left, int right){
        if(left == right){
            return new Node(left, right, arr[left]);
        }

        Node root = new Node(left, right, 0);
        int mid = (left + right)/2;
        root.lchild = costruct_tree(arr, left, mid);
        root.rchild = costruct_tree(arr, mid+1, right);

        root.data = Math.min(root.lchild.data, root.rchild.data);
        return root;
    }

    int query(Node root, int left, int right){
        if(root == null || root.lrange > right || root.rrange < left)
            return Integer.MAX_VALUE;
        
        if(root.lrange >= left && root.rrange <= right)
            return root.data;
        
        return Math.min(query(root.lchild, left, right), query(root.rchild, left, right));
    }

    void update(Node root, int idx, int value){
        if(root == null || root.lrange > idx || root.rrange < idx)
            return;
        if(root.lrange == idx && root.rrange == idx){
            root.data = value;
            return;
        }

        update(root.lchild, idx, value);
        update(root.rchild, idx, value);

        root.data = Math.min(root.lchild.data, root.rchild.data);
    }

    public SegmentTree(int arr[]){
        head = costruct_tree(arr, 0 , arr.length-1);
    }

    public int query(int left, int right){
        return query(head, left, right);
    }

    public void update(int idx, int value){
        update(head, idx, value);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());

        int[] arr = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++)
            arr[i] = Integer.parseInt(st.nextToken());

        SegmentTree seg = new SegmentTree(arr);

        for (int i = 0; i < q; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            if(a == 1){
                seg.update(b-1, c);
            }else sb.append(seg.query(b - 1, c - 1)).append('\n');
        }

        System.out.print(sb);
    }
}