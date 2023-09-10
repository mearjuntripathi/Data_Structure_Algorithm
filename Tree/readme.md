# Tree
A **tree data structure** is a hierarchical structure that is used to represent and organize data in a way that is easy to navigate and search. It is a collection of nodes that are connected by edges and has a hierarchical relationship between the nodes. 

The topmost node of the tree is called the root, and the nodes below it are called the child nodes. Each node can have multiple child nodes, and these child nodes can also have their own child nodes, forming a recursive structure.

![Tree data Structure](https://media.geeksforgeeks.org/wp-content/uploads/20221124153129/Treedatastructure.png)

## Basic Terminologies In Tree Data Structure:

* **Parent Node:** The node which is a predecessor of a node is called the parent node of that node. {B} is the parent node of {D, E}.

* **Child Node:** The node which is the immediate successor of a node is called the child node of that node. Examples: {D, E} are the child nodes of {B}.

* **Root Node:** The topmost node of a tree or the node which does not have any parent node is called the root node. {A} is the root node of the tree. A non-empty tree must contain exactly one root node and exactly one path from the root to all other nodes of the tree.

* **Leaf Node or External Node:** The nodes which do not have any child nodes are called leaf nodes. {K, L, M, N, O, P} are the leaf nodes of the tree.

* **Ancestor of a Node:** Any predecessor nodes on the path of the root to that node are called Ancestors of that node. {A,B} are the ancestor nodes of the node {E}

* **Descendant:** Any successor node on the path from the leaf node to that node. {E,I} are the descendants of the node {B}.

* **Sibling:** Children of the same parent node are called siblings. {D,E} are called siblings.

* **Level of a node:** The count of edges on the path from the root node to that node. The root node has level 0.

* **Internal node:** A node with at least one child is called Internal Node.

* **Neighbour of a Node:** Parent or child nodes of that node are called neighbors of that node.

* **Subtree:** Any node of the tree along with its descendant.
---

## Representation of Tree Data Structure:

> A tree consists of a root, and zero or more subtrees T1, T2, … , Tk such that there is an edge from the root of the tree to the root of each subtree.

![tree representation](https://media.geeksforgeeks.org/wp-content/uploads/20221124174349/recurivetree.png)

### Representation of a Node in Tree Data Structure:

```
struct Node
{
   int data;
   struct Node *first_child;
   struct Node *second_child;
   struct Node *third_child;
   .
   .
   .
   struct Node *nth_child;
};
```

### Example of Tree data structure
![binary tree](https://media.geeksforgeeks.org/wp-content/uploads/20221124174432/binary.png)

Here,

- Node 1 is the root node
- 1 is the parent of 2 and 3
- 2 and 3 are the siblings
- 4, 5, 6, and 7 are the leaf nodes
- 1 and 2 are the ancestors of 5

## Types of Tree data structures:
![types of tree](https://media.geeksforgeeks.org/wp-content/uploads/20230111154258/typoes1-768.png)


- **[Binary tree](./Binary%20Tree/readme.md):** In a binary tree, each node can have a maximum of two children linked to it. Some common types of binary trees include full binary trees, complete binary trees, balanced binary trees, and degenerate or pathological binary trees.

- **[Ternary Tree]():** A Ternary Tree is a tree data structure in which each node has at most three child nodes, usually distinguished as “left”, “mid” and “right”.

- **[N-ary Tree or Generic Tree]():** Generic trees are a collection of nodes where each node is a data structure that consists of records and a list of references to its children(duplicate references are not allowed). Unlike the linked list, each node stores the address of multiple nodes.


## Basic Operation of a Tree Data Structure

- **Create** – Create a tree in the data structure.
- **Insert** − Inserts data in a tree.
- **Search** − Searches specific data in a tree to check whether it is present or not.
- **Traversal:**
    - **Preorder Traversal** – Perform Traveling a tree in a pre-order manner in the data structure.
    - **In order Traversal** – Perform Traveling a tree in an in-order manner.
    - **Post-order Traversal** – Perform Traveling a tree in a post-order manner.

## Why Tree is considered a non-linear data structure?
Tree is considered a non-linear data structure because the data elements are not arranged in a sequential order. Instead, they are arranged in a hierarchical manner, with each node having zero or more child nodes. This means that there is no one "next" element in a tree, and the data elements can be accessed in any order.

In contrast, a linear data structure is a data structure where the data elements are arranged in a sequential order. This means that there is always a "next" element in a linear data structure, and the data elements can only be accessed in a sequential order.

Here is a table to summarize the key differences between linear and non-linear data structures:

| Feature | Linear Data Structure | Non-Linear Data Structure |
|---|---|---|
| Data arrangement | Sequential | Hierarchical |
| Access order | Only sequential | Can be sequential or non-sequential |
| Example | List, array | Tree, graph |


## Need and Application of Tree Data Structure

Trees are a versatile data structure with many applications. Here are some of the most common needs and applications of tree data structures:


* **Storing hierarchical data:** Trees are well-suited for storing data that has a natural hierarchical structure, such as the file system on a computer or the syntax of a programming language.

* **Efficient searching:** Trees can be used to efficiently search for data. This is because the data is organized in a hierarchical manner, so it can be quickly found by traversing the tree from the root node to the leaf node that contains the desired data.

* **Sorting:** Trees can be used to sort data. This is because the data can be traversed in a specific order, such as in-order or pre-order, which can be used to sort the data.

* **Algorithms:** Trees can be used to implement a variety of algorithms, such as finding the shortest path between two nodes or finding the common ancestor of two nodes.

* **Compression:** Trees can be used to compress data. This is because the data can be represented in a hierarchical manner, which can be used to reduce the amount of space required to store the data.

* **Decision making:** Trees can be used to make decisions. This is because the data can be organized in a hierarchical manner, which can be used to represent the different possible outcomes of a decision.

### Here are some specific examples of the use of tree data structures:


* **File systems:** File systems use trees to store and organize files. The root node of the tree represents the root directory, and the leaf nodes represent the files in the file system.

* **Compilers:** Compilers use trees to represent the syntax of programming languages. The root node of the tree represents the root of the syntax tree, and the leaf nodes represent the different tokens in the language.

* **Search engines:** Search engines use trees to index and search for documents. The root node of the tree represents the root of the index, and the leaf nodes represent the different documents in the index.

* **Routing algorithms:** Routing algorithms use trees to find the shortest path between two nodes. The root node of the tree represents the source node, and the leaf nodes represent the destination nodes.

* **Compression:** Trees can be used to compress data. For example, the Huffman coding algorithm uses a tree to represent the different symbols in a data stream, and the tree can then be used to encode the data stream.

* **Decision making:** Trees can be used to make decisions. For example, a decision tree can be used to represent the different possible outcomes of a decision, and the tree can then be used to make the decision.


## Advantage and Disadvantage of Tree Data Structure

**Advantages**


* **Efficient searching:** Trees are particularly efficient for searching and retrieving data. This is because the data is organized in a hierarchical manner, so it can be quickly found by traversing the tree from the root node to the leaf node that contains the desired data.

* **Flexible size:** Trees can grow or shrink dynamically depending on the number of nodes that are added or removed. This makes them a good choice for applications where the data size may change frequently.

* **Easy to traverse:** Traversing a tree is a simple operation, and it can be done in several different ways depending on the requirements of the application. This makes them easy to use for a variety of tasks, such as searching, sorting, and printing.

* **Easy to maintain:** Trees are easy to maintain because they enforce a strict hierarchy and relationship between nodes. This makes it easy to keep the tree organized and to add or remove nodes as needed.

* **Natural organization:** Trees have a natural hierarchical organization that can be used to represent many types of relationships. For example, a family tree can be represented as a tree, where each person is a node and the relationships between people are represented by the edges between the nodes.

**Disadvantages**


* **Space inefficiency:** Trees can be space inefficient, especially if they are unbalanced. This is because each node in a tree can have multiple child nodes, which can lead to a lot of wasted space.

* **Complex traversal:** Traversal of a tree can be complex, especially if the tree is unbalanced. This is because the order in which the nodes are traversed can affect the performance of the traversal algorithm.

* **Difficult to implement:** Trees can be difficult to implement, especially if the tree is complex. This is because the implementation of the tree must take into account the hierarchical structure of the tree and the relationships between the nodes.

* **Not suitable for all applications:** Trees are not suitable for all applications. For example, trees are not a good choice for applications where the data is stored in a sequential order.
