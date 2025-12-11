#include<bits/stdc++.h>
using namespace std;


class BST{
    class Node{
      private:
        int val, height;
        Node *left, *right;

      public:
        Node(int val){
            this->val = val;
            this->height = 1;
            this->left = this->right = nullptr;
        }

        int getVal(){return this->val;}

        void setVal(int val){this->val = val;}

        int getHeight(){return this->height;}

        void setHeight(int height){this->height = height;}

        void setLeft(Node *left){this->left = left;}

        void setRight(Node *right){this->right = right;}
        
        Node* getLeft(){return this->left;}

        Node* getRight(){return this->right;}
    };

    Node *root;

    Node* createBSTWithSortedArray(vector<int> arr, int start, int end){
        if(start > end) return NULL;

        int mid = (start+end)/2;
        Node *root = new Node(arr[mid]);

        root->setLeft(createBSTWithSortedArray(arr,start,mid-1));
        root->setRight(createBSTWithSortedArray(arr,mid+1,end));

        return root;
    }

    void insertValue(Node *root, int val){
        if(val < root->getVal()){
            if(root->getLeft() == nullptr){
                root->setLeft(new Node(val));
                return;
            }
            insertValue(root->getLeft(),val);
        }else{
            if(root->getRight() == nullptr){
                root->setRight(new Node(val));
                return;
            }
            insertValue(root->getRight(),val);
        }
    }

    Node* deleteNode(Node* root, int val) {
        if (root == nullptr) 
            return root;

        if (val < root->getVal()) {
            root->setLeft(deleteNode(root->getLeft(), val));
        } 
        else if (val > root->getVal()) {
            root->setRight(deleteNode(root->getRight(), val));
        } 
        else {
            // Case 1: no child
            if (root->getLeft() == nullptr && root->getRight() == nullptr) {
                delete root;
                return nullptr;
            }

            // Case 2: one child
            else if (root->getLeft() == nullptr) {
                Node* temp = root->getRight();
                delete root;
                return temp;
            }

            else if (root->getRight() == nullptr) {
                Node* temp = root->getLeft();
                delete root;
                return temp;
            }

            // Case 3: two children
            else {
                Node* temp = root->getRight();
                while (temp->getLeft() != nullptr)
                    temp = temp->getLeft();

                root->setVal(temp->getVal());
                root->setRight(deleteNode(root->getRight(), temp->getVal()));
            }
        }
        return root;
    }


    void print2DTree(Node* root, int space = 0, int indent = 8) {
        if (root == nullptr) return;

        // Increase distance between levels
        space += indent;

        // Print right child first
        print2DTree(root->getRight(), space);

        // Print current node after spaces
        cout << string(space - indent, ' ') << root->getVal() << "\n";

        // Print left child
        print2DTree(root->getLeft(), space);
    }

    public:
    BST(){
        this->root = nullptr;
    }

    BST(vector<int> arr){
        this->root = createBSTWithSortedArray(arr,0,arr.size()-1);
    }


    void insertValue(int val){
        if(root == nullptr){
            root = new Node(val);
            return;
        }
        insertValue(root,val);
    }

    void deleteNode(int val){
        root = deleteNode(root, val);
    }

    void print2DTree() {
        print2DTree(root);
    }

    void printTree() {
        if (root == nullptr) {
            cout << "null\n";
            return;
        }

        queue<Node*> q;
        q.push(root);

        bool hasNonNull = true;  // track if further levels contain non-null nodes

        while (hasNonNull) {
            int n = q.size();
            hasNonNull = false;

            for (int i = 0; i < n; i++) {
                Node* temp = q.front();
                q.pop();

                if (temp == nullptr) {
                    cout << "null ";
                    q.push(nullptr);
                    q.push(nullptr);
                } else {
                    cout << temp->getVal() << " ";
                    q.push(temp->getLeft());
                    q.push(temp->getRight());

                    if (temp->getLeft() != nullptr || temp->getRight() != nullptr)
                        hasNonNull = true;
                }
            }
            cout << endl;
        }
    }

};


int main(){

    BST b;
    b.insertValue(5);
    b.insertValue(2);
    b.insertValue(9);
    b.insertValue(1);
    b.insertValue(3);
    b.insertValue(7);
    b.insertValue(10);
    b.insertValue(4);
    b.insertValue(6);
    b.insertValue(8);

    b.printTree();
    b.print2DTree();

    cout << "\n\n After deleting a Number 9:\n";
    b.deleteNode(9);
    b.printTree();
    b.print2DTree();

    
    return 0;
}