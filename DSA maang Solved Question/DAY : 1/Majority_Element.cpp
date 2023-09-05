#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums[0];
        int count = 0;
        for(int i = 0; i < nums.size() ; i++){
            if(count == 0){
                majority = nums[i];
                count = 1;
            }else{
                if(nums[i] == majority)
                    count ++;
                else count--;
            }

        }
        return majority;        
    }
};

int main() {
    Solution s;
    vector<int> res = {3,2,3};
    cout<<s.majorityElement(res)<<endl;
    res = {2,2,1,1,1,2,2};
    cout<<s.majorityElement(res)<<endl;
    return 0;
}