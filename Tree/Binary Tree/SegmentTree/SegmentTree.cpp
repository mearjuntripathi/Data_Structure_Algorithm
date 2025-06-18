#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* lchild;
		Node* rchild;
		int start_interval;
		int end_interval;
	Node(int start_interval, int end_enterval){
		this->data = data;
		this->start_interval = start_enterval;
		this->end_enterval = end_enterval;
		lchild = rchild = NULL;
	}
};

class Segment_Tree{
	public:
		Node* root;
		SegmentTree(vector<int> &arr){
			
		}
		
}

int main(){
	int n;
	cin >> 
	vector<int> arr(n);
	for(int i=0; i<n ; i++){
		cin >> arr[i];
	}

	SegmentTree s(arr);

	return 0;
}
