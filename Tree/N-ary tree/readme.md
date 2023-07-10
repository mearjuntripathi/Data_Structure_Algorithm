# <center>N-Array Tree</center>
The N-ary tree data structure is a complex binary tree data structure that allows us to have multiple children at each node, similar to the binary tree data structure, but with n number of children. This structure is slightly more complex than the prevalent binary trees. The only difference between an N-ary and a binary tree is in their shapes. In an N-ary, we can add and remove leaves (and therefore branches) from the root of the system during its construction.

N-ary Trees hold certain advantages over Binary Trees, namely that it takes up significantly less space when there is no more room to grow vertically in a Binary Tree. This also allows for linear storage of data rather than the tree-like structure used in Binary Trees, making it perfect for database files where you would like to save as much space as possible without sacrificing too much speed or efficiency.

### General Idea
N-ary trees are a variety of binary trees. They differ by having a single node at the top which holds multiple children. These children may have their children, themselves being n-ary trees with one "level" of depth less than their parents. Thus, at any level, the maximum number of children a node can have is n.

![Stack implementation ](https://www.enjoyalgorithms.com/static/n-ary-tree-cover-e20ff15211266dad053946933c929330.svg)

## <center>OPERATION PERFORMED ON N-Array Tree</center>

There is four basic operation on N-array tree
1. Insertion

2. Deletion

3. Traversal

4. Merging