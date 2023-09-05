#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int low = 0;
        int pos = 0; 
        int size = nums.size();
        while(low < size && pos < size){
            if(nums[low] == 0 && nums[pos] == 0){
                pos++;
            }
            else{
                if(nums[low] == 0 && nums[pos] != 0){
                    nums[low] = nums[pos];
                    nums[pos] = 0;
                }
                low++;
                pos++;
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> res = {0,1,0,3,12};
    s.moveZeroes(res);
    for(int r : res)
        cout<<r << ' ';
    cout<<endl;
    res = {0};
    s.moveZeroes(res);
    for(int r : res)
        cout<<r << ' ';
    cout<<endl;
    return 0;
}