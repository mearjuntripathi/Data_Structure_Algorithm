#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size);
        int right = size - 1, left = 0;
        for (int i = size - 1; i >= 0; i--) {
            if (abs(nums[left]) > abs(nums[right])) {
                result[i] = nums[left] * nums[left];
                left++;
            } else {
                result[i] = nums[right] * nums[right];
                right--;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> res = {-4,-1,0,3,10};
    res = s.sortedSquares(res);
    for(int i = 0 ;i < res.size(); i++)
        cout<<res[i]<<' ';
    cout<<endl;
    res = {-7,-3,2,3,11};
    res = s.sortedSquares(res);
    for(int i = 0 ;i < res.size(); i++)
        cout<<res[i]<<' ';
    return 0;
}