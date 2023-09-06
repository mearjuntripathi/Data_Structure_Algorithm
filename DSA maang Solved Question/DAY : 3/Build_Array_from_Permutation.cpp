#include<bits/stdc++.h>
using namespace std;

class Solution {
    public :
        vector<int> buildArray(vector<int>& nums) {
            // Brout forse Algorithm
            // vector<int> ans(nums.size());
            // for(int i=0 ; i<nums.size() ; i++)
            //         ans[i] += nums[nums[i]];
            // return ans;
            int n = nums.size();
            for(int i = 0 ; i < n ; i++)
                nums[i] += (n * (nums[nums[i]]%n));
            
            for(int i=0;i<n;i++)
                nums[i] /= n;
            
            return nums;
        }        
};

int main() {
    Solution s;
    vector<int> nums = {0,2,1,5,3,4};
    nums = s.buildArray(nums);
    for(int num : nums)
        cout << num << ' ';
    cout << endl;

    nums = {5,0,1,2,3,4};
    nums = s.buildArray(nums);
    for(int num : nums)
        cout << num << ' ';
    cout << endl;
    return 0;
}