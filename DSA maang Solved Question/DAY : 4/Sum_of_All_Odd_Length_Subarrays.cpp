#include<bits/stdc++.h>
using namespace std;

class Solution {
    public :
        int sumOddLengthSubarrays(vector<int>& arr) {
            int size = arr.size();

            int totalSum = 0;
            for(int i = 0; i<size; i++){
                int times = (size-i)*(i+1);
                int odd = times/2;
                if(times%2!=0){
                    odd++;
                }
                totalSum+=arr[i]*odd;
            }
            return totalSum;
        }     
};

int main() {
    Solution s;
    vector<int> arr = {3,1,2,4};
    cout << s.sumOddLengthSubarrays(arr) << endl;

    arr = {1,2};
    cout << s.sumOddLengthSubarrays(arr) << endl;

    arr = {10,11,12};
    cout << s.sumOddLengthSubarrays(arr) << endl;
    return 0;
}