#include<bits/stdc++.h>
using namespace std;

class Solution {
    public :
        vector<int> runningSum(vector<int>& nums) {
            int size = nums.size();
            for(int i=1; i < size;i++)
                nums[i] += nums[i-1];
            
            return nums;
        }
        
};

int main() {
    Solution s;
    vector<int> nums = {1,2,3,4};
    nums = s.runningSum(nums);
    for(int num : nums)
        cout<<num<<' ';
    cout<<endl;
    
    nums = {1,1,1,1,1};
    nums = s.runningSum(nums);
    for(int num : nums)
        cout<<num<<' ';
    cout<<endl;
    
    nums = {3,1,2,10,1};
    nums = s.runningSum(nums);
    for(int num : nums)
        cout<<num<<' ';
    cout<<endl;
    return 0;
}