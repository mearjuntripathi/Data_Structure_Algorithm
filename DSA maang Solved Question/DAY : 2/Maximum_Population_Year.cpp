#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maximumPopulation(vector<vector<int>>& logs) {
            int year[101] = {0};

            for(int i=0;i<logs.size();i++){
                year[logs[i][0]-1950]++;
                year[logs[i][1]-1950]--;
            }

            for(int i = 1 ; i < 101 ; i++){
                year[i] += year[i-1];
            }

            int max = 0;
            int maxYear = 1950;

            for(int i = 0 ; i < 101 ; i++){
                if(max < year[i]){
                    max = year[i];
                    maxYear = 1950 + i;
                }
            }
            return maxYear;
        }
};

int main() {
    Solution s;
    vector<vector<int>> logs = {{1993,1999},{2000,2010}};
    cout<<s.maximumPopulation(logs)<<endl;
    logs = {{1950,1961},{1960,1971},{1970,1981}};
    cout<<s.maximumPopulation(logs)<<endl;
    return 0;
}