#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int pivotIndex(vector<int>& nums) {
            int left = 0;
            int right = 0;

            for(int i : nums)
                left += i;
            
            for(int i = 0 ; i < nums.size() ; i++){
                left -= nums[i];
                if(left == right)
                    return i;
                right += nums[i];
            }
            return -1;
        }
};

int main() {
    Solution s;
    vector<int> nums = {1,7,3,6,5,6};
    cout<<s.pivotIndex(nums)<<endl;

    nums = {1,2,3};
    cout<<s.pivotIndex(nums)<<endl;

    nums = {2,1,-1};
    cout<<s.pivotIndex(nums)<<endl;
    return 0;
}