#include<bits/stdc++.h>
using namespace std;

class Solution {
    public :
        vector<string> commonChars(vector<string>& words) {
            vector<int> falfa (26, INT_MAX);
        
            for(auto word : words){
                int alfa[26] = {0};
                
                for(auto c : word)
                    alfa[c - 'a']++;

                for(auto i=0;i<26;i++)
                    falfa[i] = min(falfa[i],alfa[i]);
            }
            
            vector<string> common;
            
            for(auto i = 0 ; i < 26 ; i++)
                for(auto j = 0 ; j < falfa[i] ; j++)
                    common.push_back(string(1,i+'a'));
            
            return common;
        }        
};

int main() {
    Solution s;
    vector<string> words = {"bella","label","roller"};
    words = s.commonChars(words);
    for(auto word : words)
        cout << word << ' ';
    cout << endl;

    words = {"cool","lock","cook"};
    words = s.commonChars(words);
    for(auto word : words)
        cout << word << ' ';
    cout << endl;
    return 0;
}