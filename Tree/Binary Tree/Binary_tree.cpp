#include<bits/stdc++.h>
using namespace std;



class Binary_tree {
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
    public :
        Node *root;
        Binary_tree(){
            root = NULL;
        }
        Binary_tree(int data){
            root = new Node(data);
        }

        void depth_first_value(int arr[]){
            if(arr.length() == 0)
                return ;

            int i = 0;
            stack<Node *> st;
            st.push(root);

            while(!st.empty()){
                Node * curr = st.top();
                st.pop();
                if(arr[i] != -1){
                    curr = NULL;
                }
                else{
                    curr = new Node[i++];
                }

            }
        }
        
};

int main() {
    Binary_tree a(1);
    Binary_tree b(2);
    Binary_tree c(3);
    
    a.root->right_child = b.root;
    a.root->left_child = c.root;
    return 0;
}