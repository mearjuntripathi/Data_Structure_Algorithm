// Check If Circular Linked List

// Question here - 
// https://practice.geeksforgeeks.org/problems/circular-linked-list/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};


/* Function to get the middle of the linked list*/
bool isCircular(struct Node *head);

/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){

        cin>>n>>k;
	    Node *head=NULL, *tail = NULL;
	    int x;
	    cin >> x;
	    head = new Node(x);
	    tail = head;
	    for(int i=0;i<n-1;i++)
	    {
	        cin>>x;
	        tail -> next = new Node(x);
	        tail = tail -> next;
	    }
        if (k==1 && n >= 1)
              tail->next = head;


    printf("%d\n", isCircular(head));
    }
    return 0;
}


// } Driver Code Ends


/* Link list Node 
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; 
*/

/* Should return true if linked list is circular, else false */
bool isCircular(Node *head)
{
    Node *temp = head;
    temp = temp->next;
    
    while(temp != NULL || temp == head){
        if(temp == head)
            return true;
        if(temp == NULL)
            return false;
        
        temp = temp->next;
    }
    
    return false;
}
