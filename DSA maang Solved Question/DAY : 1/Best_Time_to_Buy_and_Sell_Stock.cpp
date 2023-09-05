#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int max (int n1,int n2){return n1>n2?n1:n2;}
        int min (int n1,int n2){return n1<n2?n1:n2;}
        int maxProfit(vector<int>&prices ){
            int ans = 0;
            int m = prices[0];
            for(int i=1;i<prices.size();i++){
                m = min(prices[i],m);
                ans = max(ans, (prices[i]-m));
            }
            return ans;
        }
};

int main() {
    Solution s1;
    vector<int> res = {7,1,5,3,6,4};
    cout<<s1.maxProfit(res)<<endl;
    res = {7,6,4,3,1};
    cout<<s1.maxProfit(res)<<endl;
    return 0;
}