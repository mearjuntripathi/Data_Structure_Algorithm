#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums, int left, int right, int mid){
	vector<int> temp(right-left+1);
	int i = left;
	int j = mid + 1;
	int k = 0;

	cout << "left half: ";
	for(int i = left ; i <= mid ; i++) cout << nums[i] << ' ';
	cout << endl;

	cout << "right half: ";
	for(int i = mid+1 ; i <= right ; i++) cout << nums[i] << ' ';
	cout << endl;
	 
	while(i <= mid && j <= right){
		if(nums[i] < nums[j])
			temp[k++] = nums[i++];
		else temp[k++] = nums[j++];
	}

	while(i <= mid) temp[k++] = nums[i++];
	while(j <= right) temp[k++] = nums[j++];

	cout << "After Merging ";
	for(int i = left, k = 0 ; i <= right ; i++, k++){
		cout << temp[k] << ' ';
		nums[i] = temp[k];
	}
	cout << endl;
}

void mergesort(vector<int> &nums, int left, int right){
	if(left >= right) return;
	int mid = (left + right)/2;
	mergesort(nums, left, mid);
	mergesort(nums, mid+1, right);
	merge(nums, left, right, mid);
}


int main(){
	int n;
	cin >> n;
	vector<int> nums;

	for(int i = 0 ;i < n ; i++){
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}

	mergesort(nums, 0, n-1);

	// for(auto num : nums)
	// 	cout << num << ' ';
	
}
