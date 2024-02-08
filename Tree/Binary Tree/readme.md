# Binary Tree

A binary tree is a tree data structure in which each node has at most two child nodes, called the left child and the right child. The root node is the topmost node of the tree, and the leaf nodes are the nodes that do not have any child nodes.

Here is a formal definition of a binary tree:

```
A binary tree is a finite set of nodes T = {v1, v2, ..., vn}, where:

* There is a unique node r, called the root of T.
* For each node v in T, there is a unique subset of nodes, called the children of v.
* The children of v are disjoint from each other and from T \ {v}.
* The root has no children is know as leaf.
* Each child of v is either a left child or a right child, but not both.
```

Binary trees are a widely used data structure in computer science. They are used in a variety of applications, such as:

* **Search:** Binary trees can be used to efficiently search for data. This is because the data is organized in a hierarchical manner, so it can be quickly found by traversing the tree from the root node to the leaf node that contains the desired data.
* **Sorting:** Binary trees can be used to sort data. This is because the data can be traversed in a specific order, such as in-order or pre-order, which can be used to sort the data.
* **Algorithms:** Binary trees can be used to implement a variety of algorithms, such as finding the shortest path between two nodes or finding the common ancestor of two nodes.
* **Compression:** Binary trees can be used to compress data. This is because the data can be represented in a hierarchical manner, which can be used to reduce the amount of space required to store the data.

## Types of Binary Tree

1. **[Fully Binary Tree]()** A full Binary tree is a special type of binary tree in which every parent node/internal node has either two or no children.

2. **[Perfect Binary Tree]()** A perfect binary tree is a type of binary tree in which every internal node has exactly two child nodes and all the leaf nodes are at the same level.

3. **[Complete Binary Tree]()** A complete binary tree is just like a full binary tree, but with two major differences

    1. Every level must be completely filled
    2. All the leaf elements must lean towards the left.
    3. The last leaf element might not have a right sibling i.e. a complete binary tree doesn't have to be a full binary tree.

4. **[Degenrated or Phythological Tree]()** A degenerate or pathological tree is the tree having a single child either left or right.

5. **[Skewed Binary Tree]()** A skewed binary tree is a pathological/degenerate tree in which the tree is either dominated by the left nodes or the right nodes. Thus, there are two types of skewed binary tree: **left-skewed binary tree** and **right-skewed binary tree**.

6. **[Balanced Binary Tree]()** It is a type of binary tree in which the difference between the height of the left and the right subtree for each node is either 0 or 1.
---
## Binary Tree Representation

1. **Sequential Representation using array**
2. **Linked Representation using Nodes**

### 1. Array Representation
An array can be used to store the nodes of a binary tree. The nodes stored in an array of memory can be accessed sequentially.

Suppose a binary tree T of depth d. Then at most 2<sup>d – 1</sup> nodes can be there in T.(i.e., SIZE = 2<sup>d – 1</sup>) So the array of size “SIZE” to represent the binary tree. Consider a binary tree of depth 3. Then SIZE = 22<sup>3</sup> – 1 = 7. Then the array A[7] is declared to hold the
nodes.
```
                       0
                      [A]
                     /   \
                    /     \  
                   /       \   
              1 [B]         [C] 2
                / \         / \
               /   \       /   \
           3  /     \ 4 5 /     \  6
           [D]       [E][_]      [G]

    A[7] = [A][B][C][D][E][_][G]
            0  1  2  3  4  5  6
```
The array representation of the binary tree is shown in diagram To perform any operation often we have to identify the father, the left child and right child of an arbitrary node.

1. The father of a node having index n can be obtained by (n – 1)/2. For example to find the father of D, where array index n = 3. Then the father nodes index can be obtained

            = (n – 1)/2
            = 3 – 1/2
            = 2/2
            = 1
    i.e., A[1] is the father D, which is B.

2. The left child of a node having index n can be obtained by (2n+1). For example to find the left child of C, where array index n = 2. Then it can be obtained by

            = (2n +1)
            = 2*2 + 1
            = 4 + 1
            = 5
    i.e., A[5] is the left child of C, which is NULL. So no left child for C.

3. The right child of a node having array index n can be obtained by the formula (2n+ 2). For example to find the right child of B, where the array index n = 1. Then

            = (2n + 2)
            = 2*1 + 2
            = 4
    i.e., A[4] is the right child of B, which is E.

4. If the left child is at array index n, then its right brother is at (n + 1). Similarly, if the right child is at index n, then its left brother is at (n – 1)

The array representation is more ideal for the complete binary tree. The diagram is not a complete binary tree. Since there is no left child for node C, i.e., A[5] is vacant. Even though memory is allocated for A[5] it is not used, so wasted unnecessarily.

### 2. Nodes Repesentation

A node of a binary tree is represented by a structure containing a data part and two pointers to other structures of the same type.

```cpp
struct Node{
    int data;
    struct Node *left_child;
    struct Node *right_child;
};
```
```java
class Node{
    int data;
    Node *left_child;
    Node *right_child;
}
```

![Binary tree Repersentation](https://cdn.programiz.com/sites/tutorial2program/files/binary-tree-representation_0.png)
---
## Operation on Binary Tree


* **Search:** This operation finds a node in the tree that contains a given value.

* **Insert:** This operation inserts a new node into the tree.

* **Delete:** This operation deletes a node from the tree.

* **Traverse:** This operation visits all the nodes in the tree in a specific order. There are many different ways to traverse a binary tree, such as in-order, pre-order, and post-order traversal.

* **Height:** This operation finds the height of the tree, which is the number of levels in the tree.

* **Depth:** This operation finds the depth of a node, which is the number of levels from the node to the root node.

* **Balanced:** This operation checks if the tree is balanced, which means that the heights of the left and right subtrees of any node differ by at most 1.

**Here are some of the more advanced operations that can be performed on binary trees:**


* **Find the minimum and maximum element:** This operation finds the node with the minimum and maximum value in the tree.

* **Find the successor and predecessor:** This operation finds the node that comes immediately after and before a given node in the tree.

* **Find the common ancestor:** This operation finds the node that is the ancestor of two given nodes.

* **Convert to a binary search tree:** This operation converts a binary tree to a binary search tree, which is a special type of binary tree where the nodes are arranged in sorted order.

* **Balance the tree:** This operation balances the tree, which ensures that the tree remains balanced.


## Psudo code and explenation of Operation of Binary Tree

### Create a Empty Binary tree
The `Binary_tree` class has a `Root` field, which is a pointer to the root node of the tree. The `Binary_tree()` constructor initializes the `Root` field to `NULL`, which indicates that the tree is empty.

```cpp
class Node{
    public:
        int data;
        Node *left_child;
        Node *right_child;

        Node(int data){
            this->data = data;
            left_child = right_child = NULL;
        }
};

class Binary_tree {
    public :
    Node *Root;
        Binary_tree(){
            Root = NULL;
        }
        Binary_tree(int data){
            Root = new Node(data);
        }
};
```

The `Binary_tree(int data)` constructor creates a new binary tree with a root node that has the specified data. The root node's left and right child nodes are set to `NULL`.

### Depth first value
