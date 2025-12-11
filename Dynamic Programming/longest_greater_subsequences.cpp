#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0 ; i < n ; i++){
        cin >> nums[i];
    }
    int maxCount = 0;
    for(int i = 0 ; i < n ; i++){
        int count = 1;
        int prev = nums[i];
        for(int j = i+1 ; j < n  ; j++){
            if(nums[j] > prev){
                count++;
                prev = nums[j];
            }
        }
        maxCount = max(maxCount, count);
    }
    cout <<  "Max subsequence length is " << maxCount << endl;
    return 0;
}