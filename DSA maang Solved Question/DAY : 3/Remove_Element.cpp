#include<bits/stdc++.h>
using namespace std;

class Solution {
    public :
        int removeElement(vector<int>& nums, int val) {
            int n=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i] != val){
                    nums[n++] = nums[i];
                }
            }
            nums.erase(nums.begin()+n,nums.end());
            return n;
        }
};

int main() {
    Solution s;
    int val;
    vector<int> nums = {3,2,2,3};
    val = 3;
    cout << s.removeElement(nums,val) << endl;
    for(int num : nums)
        cout << num << ' ';
    cout << endl;

    nums = {0,1,2,2,3,0,4,2};
    val = 2;
    cout << s.removeElement(nums,val) << endl;
    for(int num : nums)
        cout << num << ' ';
    cout << endl;

    return 0;
}