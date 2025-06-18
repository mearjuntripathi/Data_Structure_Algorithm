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
#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    int n;

    void build(vector<int>& arr, int l, int r, int index) {
        if (l == r) {
            tree[index] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(arr, l, mid, 2 * index + 1);
        build(arr, mid + 1, r, 2 * index + 2);
        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }

    int queryUtil(int l, int r, int ql, int qr, int index) {
        // Total overlap
        if (ql <= l && qr >= r)
            return tree[index];
        // No overlap
        if (qr < l || ql > r)
            return 0;
        // Partial overlap
        int mid = (l + r) / 2;
        int left = queryUtil(l, mid, ql, qr, 2 * index + 1);
        int right = queryUtil(mid + 1, r, ql, qr, 2 * index + 2);
        return left + right;
    }

    void updateUtil(int l, int r, int idx, int val, int index) {
        if (l == r) {
            tree[index] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
            updateUtil(l, mid, idx, val, 2 * index + 1);
        else
            updateUtil(mid + 1, r, idx, val, 2 * index + 2);
        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, n - 1, 0);
    }

    int query(int l, int r) {
        return queryUtil(0, n - 1, l, r, 0);
    }

    void update(int idx, int val) {
        updateUtil(0, n - 1, idx, val, 0);
    }
};

int main() {
    vector<int> arr = {2, 4, 5, 7, 8, 9};
    SegmentTree st(arr);

    cout << "Sum from 1 to 4: " << st.query(1, 4) << endl; // 4 + 5 + 7 + 8 = 24

    st.update(2, 10);  // arr[2] = 10

    cout << "Sum from 1 to 4 after update: " << st.query(1, 4) << endl; // 4 + 10 + 7 + 8 = 29

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

