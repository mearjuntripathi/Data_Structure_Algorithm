#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(nums[abs(nums[i])-1] < 0)
                continue;
            nums[abs(nums[i])-1] *= -1;
        }
        
        vector<int> res;

        for(int i=0;i<n;i++)
            if(nums[i]>0)
                res.push_back(i+1);
        
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {4,3,2,7,8,2,3,1};
    nums = s.findDisappearedNumbers(nums);
    for(int num : nums)
        cout << num << ' ';
    cout << endl;

    nums = {1,1};
    nums = s.findDisappearedNumbers(nums);
    for(int num : nums)
        cout << num << ' ';
    cout << endl;
    return 0;
}