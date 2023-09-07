#include<bits/stdc++.h>
using namespace std;

class NumArray {
public:
    vector<int> nums;
    // vector<int> sumNums;
    NumArray(vector<int>& nums) {
        this->nums = nums;
        sumNums();
    }
    void sumNums(){
        for(int i = 1 ; i < nums.size() ; i++)
            nums[i] += nums[i-1];
    }
    
    int sumRange(int left, int right) {
        if(left == 0)   return nums[right];
        return (nums[right] - nums[left-1]); 
    }
};


int main() {
    vector<int> arr = {-2, 0, 3, -5, 2, -1};
    NumArray a(arr);
    cout << a.sumRange(0,2) << endl;
    cout << a.sumRange(2,5) << endl;
    cout << a.sumRange(0,5) << endl;

    return 0;
}