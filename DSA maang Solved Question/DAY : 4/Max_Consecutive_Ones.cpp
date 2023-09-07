#include<bits/stdc++.h>
using namespace std;

class Solution {
    public :
        int findMaxConsecutiveOnes(vector<int>& nums) {
            int consecutive = 0;
            int freq = 0;
            
            for(int num : nums)
                if(num == 1)
                    consecutive = max(consecutive, ++freq);
                else freq = 0;
            
            return consecutive;
        }   
};

int main() {
    Solution s;
    vector<int> nums = {1,1,0,1,1,1};
    cout << s.findMaxConsecutiveOnes(nums) << endl;

    nums = {1,0,1,1,0,1};
    cout << s.findMaxConsecutiveOnes(nums) << endl;

    return 0;
}