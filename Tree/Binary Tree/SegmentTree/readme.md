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

### Creation of Segment Tree

1. **Segment tree implemented with nodes and pointers** (like your original code),
   and
2. **Segment tree implemented using arrays** (like the one I just showed you).

Here’s a clear breakdown of the key differences:

---

### 1. **Segment Tree with Nodes and Pointers**

* **Data structure:** Uses a tree made up of `Node` objects, each having pointers to its left and right children.
* **Memory:** Uses dynamic memory allocation (`new`), creating many small objects (nodes).
* **Code complexity:** More verbose and complex to write because you manage nodes and pointers.
* **Flexibility:** Easier to extend to more complex trees, e.g., when nodes need to store additional info or structure (like persistent segment trees).
* **Navigation:** Navigates using pointers (e.g., `node->left`), which may be less cache-friendly.
* **Usage:** Often used when you want a conceptual tree structure or advanced versions (like persistent segment trees or when intervals are not contiguous).

### 2. **Segment Tree Using Arrays**

* **Data structure:** Uses a single large array (often of size `4*n`), where the segment tree nodes are stored in array indices.
* **Memory:** All nodes are stored contiguously in one array, better cache locality, no dynamic allocation per node.
* **Code complexity:** Simpler and shorter code, usually faster to implement.
* **Navigation:** Uses index arithmetic: for node at index `i`, left child is at `2*i`, right child at `2*i+1`.
* **Efficiency:** Faster due to better cache performance and less overhead from pointer chasing.
* **Usage:** Common in competitive programming and when the tree size is fixed and known upfront.

---

### Summary Table

| Aspect            | Node-based Implementation                        | Array-based Implementation                          |
| ----------------- | ------------------------------------------------ | --------------------------------------------------- |
| Data Structure    | Nodes with pointers                              | Single array                                        |
| Memory Allocation | Dynamic (per node)                               | Static (one big array)                              |
| Code Complexity   | More complex, verbose                            | Simpler, shorter                                    |
| Performance       | Slightly slower due to pointers                  | Faster due to cache locality                        |
| Flexibility       | Easier for persistent/complex trees              | Limited to fixed-size, simpler trees                |
| Use Cases         | Advanced segment trees, non-contiguous intervals | Most segment tree problems, competitive programming |

---

### When to use which?

* **Use array-based** if:

  * You have a fixed size array and want a clean, fast segment tree for sums, min, max, etc.
  * You want simple and efficient code for competitive programming.

* **Use node-based** if:

  * You need complex or persistent segment trees.
  * You want to handle dynamic intervals or advanced operations that benefit from explicit tree structure.


### 1. Node-Pointer Based Segment Tree
- Structure: Uses explicit Node objects with pointers to left and right children.
- Memory: Dynamic allocation; each node stores interval and data.
- Pros: Easy to extend for complex trees (persistent segment trees, dynamic intervals).
- Cons: Pointer overhead, less cache-friendly, more verbose code.

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

### 2. Array-Based Segment Tree
- Structure: Uses a single array tree of size roughly 4*n.
- Memory: Contiguous memory, better cache locality.
- Pros: Simple, fast, common in competitive programming.
- Cons: Less flexible for dynamic/persistent trees.

```c++
#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    int n;

    void build(vector<int>& arr, int idx, int left, int right) {
        if (left == right) {
            tree[idx] = arr[left];
            return;
        }
        int mid = (left + right) / 2;
        build(arr, 2*idx, left, mid);
        build(arr, 2*idx+1, mid+1, right);
        tree[idx] = tree[2*idx] + tree[2*idx+1];
    }

    int query(int idx, int left, int right, int ql, int qr) {
        if (ql > right || qr < left)  // no overlap
            return 0;
        if (ql <= left && right <= qr)  // total overlap
            return tree[idx];
        int mid = (left + right) / 2;
        return query(2*idx, left, mid, ql, qr) + query(2*idx+1, mid+1, right, ql, qr);
    }

    void update(int idx, int left, int right, int pos, int val) {
        if (left == right) {
            tree[idx] = val;
            return;
        }
        int mid = (left + right) / 2;
        if (pos <= mid)
            update(2*idx, left, mid, pos, val);
        else
            update(2*idx+1, mid+1, right, pos, val);
        tree[idx] = tree[2*idx] + tree[2*idx+1];
    }

public:
    SegmentTree(vector<int>& arr) {
        n = (int)arr.size();
        tree.resize(4*n, 0);
        build(arr, 1, 0, n-1);
    }

    int query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }

    void update(int pos, int val) {
        update(1, 0, n-1, pos, val);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    SegmentTree s(arr);

    while (q--) {
        int c, l, r;
        cin >> c >> l >> r;
        if (c == 1) {
            // update position l-1 with value r
            s.update(l - 1, r);
        } else {
            // query sum in range [l-1, r-1]
            cout << s.query(l - 1, r - 1) << "\n";
        }
    }
    return 0;
}
```

**Comparison Summary**

| Feature         | Node-Pointer Tree                                       | Array-Based Tree                          |
| --------------- | ------------------------------------------------------- | ----------------------------------------- |
| Data Structure  | Tree of Node objects (pointers)                         | Single large array                        |
| Memory Usage    | Dynamic, more overhead for pointers                     | Contiguous memory, cache-friendly         |
| Code Complexity | More verbose and explicit                               | Simpler, shorter                          |
| Flexibility     | Supports advanced trees (persistent, dynamic intervals) | Mostly static size                        |
| Performance     | Slightly slower due to pointer chasing                  | Faster due to cache locality              |
| Common Usage    | Complex problems, persistent segment trees              | Competitive programming, simple use cases |



**Key Notes**


| Function       | Description                                    |
| -------------- | ---------------------------------------------- |
| build          | Build the segment tree from the array          |
| queryUtil      | Recursive helper for range sum query           |
| updateUtil     | Recursive helper for point update              |
| query(l, r)    | Public method to query sum in range `[l,r]`    |
| update(i, v)   | Public method to update index `i` to value `v` |

