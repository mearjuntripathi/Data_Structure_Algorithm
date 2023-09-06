#include<bits/stdc++.h>
using namespace std;

class Solution {
    public :
        bool validMountainArray(vector<int>& arr) {
            int n = arr.size();
            if(n < 3) return false; // lenght is too small
            if(arr[0] >= arr[1]) return false; // not strictly increase
            if(arr[n-1] >= arr[n-2]) return false; // not strictly decreasing

            int left = 0;
            while(arr[left] < arr[left+1]) left++; // stricatly increment

            int right = n-1;

            while(arr[right] < arr[right-1]) right--; // stricatly decrement

            return (left == right); // check mountain array (chaking low high)
        }        
};

int main() {
    Solution s;
    vector<int> arr = {2,1};
    cout << s.validMountainArray(arr) << endl;

    arr = {3,5,5};
    cout << s.validMountainArray(arr) << endl;

    arr = {0,3,2,1};
    cout << s.validMountainArray(arr) << endl;
    return 0;
}