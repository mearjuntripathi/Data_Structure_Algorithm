# Day : 5
![Day 5](../images/day5.png)

---

## [Question 1](#question-1): [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/description/)
> Given the `head` of a singly linked list, reverse the list, and return the reversed list.

**Example 1:**

![example1](https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg)

&nbsp; ****Input:**** head = [1,2,3,4,5]

&nbsp; **&nbsp; **Output:**** [5,4,3,2,1]

**Example 2:**

![example2](https://assets.leetcode.com/uploads/2021/02/19/rev1ex2.jpg)

&nbsp; ****Input:**** head = [1,2]

&nbsp; **&nbsp; **Output:**** [2,1]

**Example 3:**


&nbsp; ****Input:**** head = []

&nbsp; **&nbsp; **Output:**** []
 

**Constraints:**

* The number of nodes in the list is the range `[0, 5000]`.
* `-5000 <= Node.val <= 5000`
 

***Follow up:** A linked list can be reversed either iteratively or recursively. Could you implement both?*

## Solution
**Iterative approach:**

1. Initialize two pointers reverse and cycle. Set reverse to NULL and cycle to the head of the linked list.
2. While cycle is not NULL:
    * Create a dummy node and set it to cycle.
    * Move cycle to the next node.
    * Set the dummy node's next node to reverse.
    * Update reverse to the dummy node.
3. Finally, set head to reverse.

**Recursive approach:**

1. Base case: If the linked list is empty or has only one node, return the head node.
1. Recursive step: Recursively reverse the rest of the linked list (i.e., the linked list after the head node). Then, set the next node of the head node to `NULL` and make the head node the next node of the reversed linked list. Return the reversed linked list.

**Here is an explanation of the algorithm:**

1. The iterative approach works by maintaining two pointers, `reverse` and `cycle`. `reverse` points to the reversed part of the linked list, and cycle points to the next node that needs to be reversed.
1. In each iteration, we create a dummy node and set it to the current node `cycle`. Then, we move `cycle` to the next node. We then set the dummy node's next node to `reverse`. Finally, we update `reverse` to the dummy node.
1. This process continues until `cycle` is `NULL`, which means that we have reversed the entire linked list.
1. Finally, we set `head` to `reverse`.

The recursive approach works by recursively reversing the rest of the linked list (i.e., the linked list after the head node). Then, it sets the next node of the head node to `NULL` and makes the head node the next node of the reversed linked list. It returns the reversed linked list.

The **time complexity** of both the `iterative` and `recursive` approaches is $$O(N)$$, where N is the number of nodes in the linked list. The space complexity of the iterative approach is $$O(1)$$, while the space complexity of the recursive approach is $$O(N)$$, where `N` is the number of recursive calls.

**Here is the implementation of the two methods in C++:**

**Iterative Method**

    // Iterative method
    ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr != nullptr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
    }

**Recusive method**

    // Recursive method
    ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode* reversedList = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;

    return reversedList;
    }

---

## [Question 2](#question-2): [Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/)

> Given the `head` of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

**Example 1:**

![example](https://assets.leetcode.com/uploads/2021/03/06/removelinked-list.jpg)

&nbsp; **Input:** head = [1,2,6,3,4,5,6], val = 6

&nbsp; **Output:** [1,2,3,4,5]

**Example 2:**

&nbsp; **Input:** head = [], val = 1

&nbsp; **Output:** []

**Example 3:**

&nbsp; **Input:** head = [7,7,7,7], val = 7

&nbsp; **Output:** []

**Constraints:**

* The number of nodes in the list is in the range `[0, 104]`.
* `1 <= Node.val <= 50`
* `0 <= val <= 50`

## Solution

**Approach 1 (Iterative)**

1. Create a dummy node and set it as the head of the linked list.
1. Initialize a pointer cur to the dummy node.
1. While cur.next is not None:
    * If the value of cur.next is equal to val:
        * Set p to the node pointed to by cur.next.
        * Set cur.next to the node after p.
        * Delete p.
    * Otherwise:
        * Move cur to the next node.
4. If the value of the head node is equal to val:
    * Set p to the head node.
    * Set the head node to the node after p.
    * Delete p.
* Return the head node.

**Algorithm**

    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return head;

        ListNode *dummy = head;

        while(dummy->next != NULL){
            if(dummy->next->val == val){
                ListNode *p = dummy->next;
                dummy->next = dummy->next->next;
                delete p;
            }
            else{
                dummy = dummy->next;
            }
        }
        if(head->val == val){
            ListNode *p = head;
            head = head->next;
            delete p;
        }
        
        return head;
    }

**Approach 2 (Recursive)**

1. If the head node is None, return None.
1. Set the next node of the head node to the result of calling removeElements on the next node and val.
1. If the value of the head node is equal to val, return the next node. Otherwise, return the head node.

**Algorithm**

    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return NULL;
        
        head->next = removeElements(head->next,val);
        if(head->val == val){
            ListNode *p = head;
            head = head->next;
            delete p;
        }
        return head;        
    }
---

## [Question 3](#question-3): [Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)
> Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

 

**Example 1:**

![example1](https://assets.leetcode.com/uploads/2021/01/04/list1.jpg)

**Input:** head = [1,1,2]

&nbsp; **Output:** [1,2]

**Example 2:**

![example2](https://assets.leetcode.com/uploads/2021/01/04/list2.jpg)

**Input:** head = [1,1,2,3,3]

&nbsp; **Output:** [1,2,3]
 

**Constraints:**

* The number of nodes in the list is in the `range [0, 300]`.
* `-100 <= Node.val <= 100`
* The list is guaranteed to be sorted in ascending order.

## Solution

**Approach:**

The approach is to use a dummy node to keep track of the beginning of the linked list. We then have a pointer `curr` that points to the current node in the linked list. We iterate through the linked list, and if the value of the current node is equal to the value of the next node, we remove the next node. Otherwise, we move the `curr` pointer to the next node.

**Algorithm:**

1. Initialize a `dummy` node dummy and set it to the `head` of the linked list.
1. Initialize a pointer curr and set it to the `dummy` node.
1. While `curr` is not `null`:
    * If the value of the `curr` node is equal to the value of the cur`r node's next node:
        * Set the `curr` node's next node to the `curr` node's next node's next node.
    Otherwise:
        * Move the `curr` pointer to the `curr` node's next node.
4. Return the head of the linked list.


        ListNode* deleteDuplicates(ListNode* head) { 
            ListNode *dummy = head;
            while(dummy != NULL && dummy->next != NULL){
                if(dummy->val == dummy->next->val){
                    ListNode *p = dummy->next;
                    dummy->next = dummy->next->next;
                    delete p;
                }
                else{
                    dummy = dummy->next;
                }
            }
            return head;
        }
---
## [Question 4](#question-4): [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)

You are given the heads of two sorted linked lists `list1` and `list2`.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the `head` of the merged linked list.

 

**Example 1:**

![example1](https://assets.leetcode.com/uploads/2020/10/03/merge_ex1.jpg)

&nbsp; **Input:** list1 = [1,2,4], list2 = [1,3,4]

&nbsp; **Output:** [1,1,2,3,4,4]

**Example 2:**

&nbsp; **Input:** list1 = [], list2 = []

&nbsp; **Output:** []

**Example 3:**

&nbsp; **Input:** list1 = [], list2 = [0]

&nbsp; **Output:** [0]

**Constraints:**

* The number of nodes in both lists is in the range `[0, 50]`.
* `-100 <= Node.val <= 100`
* Both `list1` and `list2` are sorted in non-decreasing order.

## Solution

**Approach:**

The `mergeTwoLists()` function takes two linked lists as input and merges them into a single sorted linked list. The function works as follows:

1. Check if either of the input lists is empty. If so, return the other list.
1. Create a new linked list to store the merged list.
1. Initialize a pointer `temp` to the head of the new linked list.
1. Iterate through the two input lists, comparing the values of the current nodes.
    * If the value of the current node in the first list is less than the value of the current node in the second list, then add the node from the first list to the new linked list.
    * Otherwise, add the node from the second list to the new linked list.
1. Move `temp` to the next node in the new linked list.
1. Repeat steps 4 and 5 until one of the input lists is empty.
1. If the first input list is not empty, then add the remaining nodes from the first list to the new linked list.
1. Otherwise, add the remaining nodes from the second list to the new linked list.
1. Return the head of the new linked list.

**Algorithm:**

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        ListNode *sort = new ListNode(0);
        ListNode *temp = sort; 

        while(list2 != NULL && list1 != NULL){
            if(list1->val < list2->val){
                temp->next = list1;
                list1 = list1->next;
            }else{
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        if(list1 != NULL)
            temp->next = list1;
        else
            temp->next = list2;

        temp = sort;
        sort = sort->next;
        delete temp;
        return sort;
    }

---
## [Question 5](#question-5): [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/)
> Given the `head` of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

 

**Example 1:**

![example1](https://assets.leetcode.com/uploads/2021/07/23/lc-midlist1.jpg)


&nbsp; **Input:** head = [1,2,3,4,5]

&nbsp; **Output:** [3,4,5]

Explanation: The middle node of the list is node 3.

**Example 2:**

![example2](https://assets.leetcode.com/uploads/2021/07/23/lc-midlist2.jpg)

&nbsp; **Input:** head = [1,2,3,4,5,6]

&nbsp; **Output:** [4,5,6]

&nbsp; **Explanation:** Since the list has two middle nodes with values 3 and 4, we return the second one.
 

**Constraints:**

* The number of nodes in the list is in the range `[1, 100].`
* `1 <= Node.val <= 100`

## Solution

**Approach:**

The approach is to find the length of the linked list first, and then divide the length by 2. This will give us the index of the middle node. We can then iterate through the linked list until we reach the node at the specified index.

**Algorithm:**

1. Initialize a variable len to 0.
1. Initialize a pointer curr to the head of the linked list.
1. Iterate through the linked list:
    * Increment len by 1.
    * Move curr to the next node.
1. Divide len by 2.
1. Initialize a pointer mid to the head of the linked list.
1. Iterate mid len times:
    * Move mid to the next node.
1. Return mid.

        ListNode* middleNode(ListNode* head) {
            size_t len = 0 ;
            ListNode * curr = head;
            while(curr){
                curr = curr->next;
                len++;
            }
            len /= 2;
            while(len--) head = head->next;

            return head;
        }
**Here is a more detailed explanation of each step:**

* We initialize a variable len to 0 to keep track of the length of the linked list.
* We initialize a pointer curr to the head of the linked list.
* We iterate through the linked list, incrementing len by 1 for each node. This will give us the length of the linked list.
* We divide len by 2 to get the index of the middle node.
* We initialize a pointer mid to the head of the linked list.
* We iterate mid len times, moving it to the next node each time. This will move mid to the node at the specified index.
* We return mid, which is the middle node of the linked list.
---

## [Question 6](#question-6): [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/)

> Given the `head` of a singly linked list, return `true` if it is a 
palindrome or `false` otherwise.

 

**Example 1:**

![example1](https://assets.leetcode.com/uploads/2021/03/03/pal1linked-list.jpg)

&nbsp; **Input:** head = [1,2,2,1]

&nbsp; **Output:** true

**Example 2:**

![example2](https://assets.leetcode.com/uploads/2021/03/03/pal2linked-list.jpg)

&nbsp; **Input:** head = [1,2]

&nbsp; **Output:** false
 

**Constraints:**

* The number of nodes in the list is in the range `[1, 105]`.
* `0 <= Node.val <= 9`
 

***Follow up:** Could you do it in O(n) time and O(1) space?*

## Solution

The code you provided is a C++ implementation of a linked list algorithm to determine whether a given linked list is a palindrome. A palindrome is a sequence that reads the same forwards as backward. In this case, you're treating the linked list as a sequence of values, and you want to check if the values form a palindrome.

Here's an approach and algorithm for this code:

**Approach:**
1. Find the middle of the linked list using two pointers, `fast` and `slow`. `slow` moves one step at a time, and `fast` moves two steps at a time. When `fast` reaches the end of the list, `slow` will be at the middle.
2. Reverse the second half of the linked list (from `slow` to the end).
3. Compare the values of the first half of the original list (from the beginning to `slow`) with the reversed second half.
4. If all values match, the linked list is a palindrome. Otherwise, it's not.

**Algorithm:**
1. Initialize two pointers, `fast` and `slow`, both initially pointing to the head of the linked list.
2. Use a while loop to find the middle of the linked list:
   - Move `slow` one step at a time (`slow = slow->next`).
   - Move `fast` two steps at a time (`fast = fast->next->next`).
   - When `fast` reaches the end (i.e., `fast` or `fast->next` is `nullptr`), `slow` will be at the middle of the list.
3. Reverse the second half of the linked list by calling the `reverseList` function on `slow`. This function recursively reverses the linked list from `slow` to the end.
4. Initialize a pointer `head2` to the reversed second half of the linked list.
5. Compare the values of `head` (which is the first half) and `head2` (reversed second half) one node at a time:
   - If they differ at any point, return `false` as the linked list is not a palindrome.
   - Otherwise, continue comparing and advancing both pointers (`head = head->next`, `head2 = head2->next`).
6. If the loop completes without finding any differences, return `true` as the linked list is a palindrome.

The main idea here is to find the middle of the linked list and reverse the second half to efficiently compare it with the first half. If the values match for all nodes, it's a palindrome; otherwise, it's not.

    bool isPalindrome(ListNode* head) {
        ListNode *fast, *slow;
        slow = fast = head;

        while(fast != NULL && fast->next != NULL){
            slow  = slow->next;
            fast = fast->next->next;
        }

        fast = reverseList(slow);
        
        while(fast != NULL){
            if(fast->val != head->val)
                return false;
            head = head -> next;
            fast = fast->next;
        }
        return true;
    }

**Reverse LinkList**

    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* reversedList = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return reversedList;
    }