#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    int start_interval, end_interval;
    Node* lchild;
    Node* rchild;

    Node(int start, int end, int val = 0) {
        start_interval = start;
        end_interval = end;
        data = val;
        lchild = rchild = nullptr;
    }
};

class Segment_Tree {
private:
    Node* construct_tree(vector<int>& arr, int left, int right) {
        if (left == right)
            return new Node(left, right, arr[left]);

        Node* node = new Node(left, right);
        int mid = (left + right) / 2;
        node->lchild = construct_tree(arr, left, mid);
        node->rchild = construct_tree(arr, mid + 1, right);
        node->data = node->lchild->data + node->rchild->data;
        return node;
    }

    int query_range(Node* node, int l, int r) {
        if (!node || l > node->end_interval || r < node->start_interval)
            return 0;  // no overlap

        if (l <= node->start_interval && r >= node->end_interval)
            return node->data;  // total overlap

        // partial overlap
        return query_range(node->lchild, l, r) + query_range(node->rchild, l, r);
    }

    void update_point(Node* node, int idx, int new_val) {
        if (!node || idx < node->start_interval || idx > node->end_interval)
            return;

        if (node->start_interval == node->end_interval) {
            node->data = new_val;
            return;
        }

        update_point(node->lchild, idx, new_val);
        update_point(node->rchild, idx, new_val);

        node->data = node->lchild->data + node->rchild->data;
    }

public:
    Node* root;

    Segment_Tree(vector<int>& arr) {
        root = construct_tree(arr, 0, arr.size() - 1);
    }

    int query(int l, int r) {
        return query_range(root, l, r);
    }

    void update(int idx, int val) {
        update_point(root, idx, val);
    }
};


int main(){
	int n,q;
	cin >> n >> q;

	vector<int> arr(n);

	for(int i=0;i<n;i++)
		cin >> arr[i];

	Segment_Tree s(arr);

	for(int i = 0 ; i < q ; i++){
		int c,l,r;

		cin >> c >> l >> r;

		if(c == 1){
			s.update(l-1, r);
		}else{
			cout << s.query(l-1, r-1) << endl;
		}
	}
	return 0;
}
