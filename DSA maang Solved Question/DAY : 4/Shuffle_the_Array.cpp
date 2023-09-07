#include<bits/stdc++.h>
using namespace std;

class Solution {
    public :
        vector<int> shuffle(vector<int>& nums, int n) {
            int out_range = 1001;
            for(int i = 0 ; i < n ; i++)
                nums[i+n] += out_range * nums[i];
            
            for(int i = 0 ; i < n ; i++){
                nums[2*i] = nums[i + n] / out_range;
                nums[(2*i)+1] = nums[i+n] % out_range; 
            }
            return nums;
        }    
};

int main() {
    Solution s;
    vector<int> nums = {2,5,1,3,4,7};
    int n = 3;
    nums = s.shuffle(nums,n);
    for(int num : nums)
        cout << num << ' ';
    cout << endl;

    nums = {1,2,3,4,4,3,2,1}, n = 4;
    nums = s.shuffle(nums,n);
    for(int num : nums)
        cout << num << ' ';
    cout << endl;

    nums = {1,1,2,2}, n = 2;
    nums = s.shuffle(nums,n);
    for(int num : nums)
        cout << num << ' ';
    cout << endl;
    return 0;
}