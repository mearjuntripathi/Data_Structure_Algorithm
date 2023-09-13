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
            this->left_child = NULL;
            this->right_child = NULL;
        }
    };

    Node* include_array(vector<int>&arr){
        static int i = -1;
        if(arr.size() == 0)return NULL;
        if(arr[++i] == -1)
            return NULL;
        Node *temp = new Node(arr[i]);
        temp->left_child = include_array(arr);
        temp->right_child = include_array(arr);
        return temp;
    }

    public :
        Node *root;
        Binary_tree(){
            root = NULL;
        }
        Binary_tree(int data){
            root = new Node(data);
        }
        Binary_tree(vector<int>&arr){
            root = include_array(arr);
        }

        void insert_array(vector<int> &arr) {
            int i = 0;
            if (arr.empty())
                return;

            stack<Node*> st;
            root = new Node(arr[i++]);
            bool left = true;
            bool right = false;
            st.push(root);

            while (!st.empty() && i < arr.size()) {
                // cout<<arr[i] << " l - " << left << " r - " <<right<<endl;
                Node *temp = st.top();
                if(left){
                    if(arr[i] != -1){
                        
                        temp->left_child = new Node(arr[i]);
                        st.push(temp->left_child);
                    }else{
                        // cout<<temp->data<< " l";
                        left = false;
                        right = true;
                    }
                }else{
                    if(arr[i] != -1){
                        
                        temp->right_child = new Node(arr[i]);
                        st.push(temp->right_child);
                        left = true;
                        right = false;
                    }else{
                        // cout<<temp->data<< " r";
                        st.pop();
                        while(!st.empty() && (st.top()->right_child != NULL))
                            st.pop();
                    }
                }
                
                i++;
            }
        }

        void preorder_traversal(Node *root){
            if(root == NULL){
                cout<< -1 << ' ';
                return ;
            }
            cout << root->data << ' ';
            preorder_traversal(root->left_child);
            preorder_traversal(root->right_child);
        }

        void preorder_traversal(){
            if(root == NULL)
                return;

            stack<Node*> st;
            st.push(root);
            while(!st.empty()){
                Node *curr = st.top();
                st.pop();
                cout << curr->data << ' ';
                if(curr->right_child)
                    st.push(curr->right_child);
                if(curr->left_child)
                    st.push(curr->left_child);
            }
        }
        
};

int main() {

    vector<int> arr = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Binary_tree b;
    b.insert_array(arr);
    b.preorder_traversal();
    cout << endl;
    b.preorder_traversal(b.root);

    return 0;
}