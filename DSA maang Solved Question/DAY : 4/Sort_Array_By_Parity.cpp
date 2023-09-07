#include<bits/stdc++.h>
using namespace std;

class Solution {
    public :
        vector<int> sortArrayByParity(vector<int>& nums) {
            int n = nums.size();
            // vector<int> res(n);
            int j = 0;
            for(int i = 0 ; i < n ; i++){
                if(nums[i]%2 == 0){
                    swap(nums[i],nums[j++]);
                }
            }

            return nums;
        }     
};

int main() {
    Solution s;
    vector<int> nums = {3,1,2,4};
    nums = s.sortArrayByParity(nums);
    for(int num : nums)
        cout << num << ' ';
        cout << endl;
    
    nums = {0};
    nums = s.sortArrayByParity(nums);
    for(int num : nums)
        cout << num << ' ';
        cout << endl;

    return 0;
}