# Single Linked List

A singly linked list is a linear data structure in which the elements are not stored in contiguous memory locations and each element is connected only to its next element using a address.

![img](https://media.geeksforgeeks.org/wp-content/uploads/singly-linkedlist.png)

## Operation on Single Linked List
There is four basic operation on linkedlist
1. Insertion

2. Deletion

3. Traversal

4. Merging

### 1. Insertion Algorithm
In insertion we do it tree type in linked list
1. At begining

        create a new node
        if(list is empty){
            head = new node
            return
        }
        new node -> next = head
        head = new node

2. At last

        create a new node
        if(list is empty){
            head = new node
            return
        }
        // create a new node temp initilized with head
        node temp = head
        while(temp -> next != null)
            temp = temp -> next
        temp -> next = new node

3. At specific position

        // check specific position is valid or not
        if(not valid position){
            print("your position is not valid")
            exit
        }
        i=0
        node temp = head
        while(i < l){
            temp = temp -> next
            i++
        }
        new node -> next = temp -> next;
        temp -> next = new node

this is a algorithm of inserion in single linked list

### 2. Deletion Algorithm
We also do a deletion in linklist as a four types

1. At begining

        if(List is empty){
            print("List is empty so you are in underflow condition")
            exit
        }
        head = head -> next

2. At last

        if(List is empty){
            print("List is empty so you are in underflow condition")
            exit
        }

        // corner case
        if(head -> next == null){
            head = null
            return
        }

        temp = head
        while(temp -> next -> next != null)
            temp = temp -> next
        temp -> next = null

3. At specific position

        if(List is empty){
            print("List is empty so you are in underflow condition")
            exit
        }

        if(not valid position){
            print("your position is not valid")
            exit
        }

        i=0
        temp = head
        while(i < position){
            temp = temp -> next
            i++
        }
        temp -> next = temp -> next -> next


4. A alloted number is avilable in list

        if(List is empty){
            print("List is empty so you are in underflow condition")
            exit
        }
        if(head -> next = null)
            if(head -> data = null){
                head = null
                return
            }
            return
        
        temp = head
        while(temp -> next -> data != num || temp -> next != null){
            temp = temp -> next
        }
        if(temp -> next -> data != num){
            temp -> next = temp -> next -> next
            return true
        }
        return false

### 3. Traversal
In traversal we travel to each node.