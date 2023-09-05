#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
            sort(nums1.begin(), nums1.end());
            sort(nums2.begin(), nums2.end());

            int l1 = 0;
            int l2 = 0;
            int pos = 0;
            while(l1 < nums1.size() && l2 < nums2.size()){
                if(nums1[l1] < nums2[l2])
                    l1++;
                else if(nums1[l1]>nums2[l2])
                    l2++;
                else{ 
                    if(nums1[l1] == nums2[l2]){
                        // if((pos > 0 && nums1[pos-1] != nums1[l1]) || pos == 0)
                        nums1[pos++] = nums1[l1];
                    }
                    l1++;
                    l2++;
                }
            }
            nums1.erase(nums1.begin()+pos,nums1.end());
            return nums1;
        }
};

int main() {
    Solution s;
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    nums1 = s.intersect(nums1,nums2);
    for(int num : nums1)
        cout << num << ' ';
    cout << endl;

    nums1 = {9,4,9,8,4};
    nums2 = {9,4,5};
    nums1 = s.intersect(nums1,nums2);
    for(int num : nums1)
        cout << num << ' ';
    cout << endl;
    return 0;
}