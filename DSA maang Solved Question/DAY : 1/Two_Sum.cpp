#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size() ;i++){
            if(mp.count((target-nums[i])))
                return {mp[(target-nums[i])],i};
            mp[nums[i]] = i;
        }
            return {-1,-1};
    }
};

int main() {
    Solution s1;
    vector<int> res = {2,7,11,15};
    res = s1.twoSum(res,9);
    for(int i = 0 ;i < 2; i++)
        cout<<res[i]<<' ';
    cout<<endl;
    res = {3,2,4};
    res = s1.twoSum(res,6);
    for(int i = 0 ;i < 2; i++)
        cout<<res[i]<<' ';
    return 0;
}