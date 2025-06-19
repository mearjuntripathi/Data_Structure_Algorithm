A Segment Tree is a data structure that stores information about array intervals as a tree. This allows answering range queries over an array efficiently, while still being flexible enough to allow quick modification of the array. This includes finding the sum of consecutive array elements `a[l... r]`, or finding the minimum element in a such a range in `O(log n)` time. Between answering such queries, the Segment Tree allows modifying the array by replacing one element, or even changing the elements of a whole subsegment (e.g. assigning all elements `a[l...r]` to any value, or adding a value to all element in the subsegment).


## Use-case:

You are given an array A[], and you want to perform:
- Range queries: e.g., find the sum, minimum, or maximum in a subrange A[l...r].
- Point updates: change a value at a specific index.

## Why Segment Tree is Needed?

Let's say:

You have an array of size n.
You need to perform multiple range queries `(O(n) each)` and updates.

-  Brute Force:
  -   Query time: `O(n)`
  -   Update time: `O(1)`
-  Segment Tree:
   -  Query time: `O(log n)`
   -  Update time: `O(log n)`
   -  Build time: `O(n)`

This is why Segment Trees are preferred when both range queries and updates are involved.

## Structure of Segment Tree

- It's a binary tree.
- Each node represents a range (segment).
- The root represents the entire range.
- Leaves represent individual elements.,

Let’s say the array is:
`A = [2, 4, 5, 7, 8, 9]`

The segment tree for sum might look like this:

```css
                [0,5]
              /       \
          [0,2]       [3,5]
         /    \       /   \
     [0,1]  [2,2]  [3,4] [5,5]
     /   \
  [0,0] [1,1]
```
Each node stores the sum of the range it represents.

## How to Implement a Segment Tree?

Here's a complete Segment Tree implementation in C++ for:

- Building the segment tree
- Querying the sum in a range
- Updating a single element

**Problem:**
Given an array `arr[]`, build a segment tree that supports:

- `update(idx, val)` → Update the element at index idx to val
- `query(l, r)` → Return the sum in the range [l, r]

```c++
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
```

**Key Notes**

```
| Function       | Description                                    |
| -------------- | ---------------------------------------------- |
| build          | Build the segment tree from the array          |
| queryUtil      | Recursive helper for range sum query           |
| updateUtil     | Recursive helper for point update              |
| query(l, r)    | Public method to query sum in range `[l,r]`    |
| update(i, v)   | Public method to update index `i` to value `v` |
```
