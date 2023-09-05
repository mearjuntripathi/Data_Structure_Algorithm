#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0)
            return;
        if(m == 0){
            nums1 = nums2;
            return;
        }
        int last_n1 = m - 1;
        int last_n2 = n - 1;
        int last_result = m + n - 1;
        while (last_n2 >= 0) {
            if (last_n1 < 0 || nums1[last_n1] < nums2[last_n2]) {
                nums1[last_result--] = nums2[last_n2--];
            } else {
                nums1[last_result--] = nums1[last_n1--];
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> num1 = {1,2,3,0,0,0}; int m = 3;
    vector<int> num2 = {2,5,6}; int n = 3;
    s.merge(num1,m,num2,n);
    
    for(int num : num1)
        cout<<num<<' ';
    cout<<endl;

    num1 = {1}; m = 1;
    num2 = {}; n = 0;
    s.merge(num1,m,num2,n);
    
    for(int num : num1)
        cout<<num<<' ';
    cout<<endl;

    num1 = {0}; m = 0;
    num2 = {1}; n = 1;
    s.merge(num1,m,num2,n);
    
    for(int num : num1)
        cout<<num<<' ';
    cout<<endl;

    return 0;
}