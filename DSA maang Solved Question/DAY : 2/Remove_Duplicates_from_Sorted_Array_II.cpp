#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int n = 1;
            int times=0;
            for(int i=1;i<nums.size();i++){
                if(nums[i] == nums[i-1]){
                    times++;
                    if(times < 2){
                        nums[n++] = nums[i];
                    }
                }
                else{ 
                    times = 0;
                    nums[n++] = nums[i];
                }
            }
            nums.erase(nums.begin()+n,nums.end());
            return n;
        }
};

int main() {
    Solution s;
    vector<int> nums = {1,1,21,1,1,2,2,3};
    cout<<s.removeDuplicates(nums)<<endl;
    for(int num : nums)
        cout<<num<<' ';
    cout<<endl;

    nums = {0,0,1,1,1,1,2,3,3};
    cout<<s.removeDuplicates(nums)<<endl;
    for(int num : nums)
        cout<<num<<' ';
    cout<<endl;
    
    return 0;
}