#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {        
            int res=1;

            for(int i=0 ; i < nums.size()-1 ; i++)

                if(nums[i]!=nums[i+1])
                    
                    nums[res++]=nums[i+1];
            nums.erase(nums.begin()+res,nums.end());
            return res;
        }
};

int main() {
    Solution s;
    vector<int> nums = {1,1,2};
    cout<<s.removeDuplicates(nums)<<endl;
    for(int num : nums)
        cout<<num<<' ';
    cout<<endl;

    nums = {0,0,1,1,1,2,2,3,3,4};
    cout<<s.removeDuplicates(nums)<<endl;
    for(int num : nums)
        cout<<num<<' ';
    cout<<endl;
    
    return 0;
}