#include <bits/stdc++.h>
#define start int i; std::cin >> i; ArjunTripathi h; while(i--) h.solution(); return 0;
using namespace std;

class ArjunTripathi{
    const unsigned int M = 1000000007;
    public:
        int gcd(int a, int b){ //gcd of two no
            if(a == 0)
                return b;
            return gcd(b % a, a);
        }

        int findGCD(int *arr, int n){ //gcd for array
           int result = 0;
           for(int i=0;i<n;i++){
                result = gcd(arr[i],result);
                if (result == 1)
                    return 1;
           }
           return result;
        }

        string solution(string s){
            for(int i=0;i<s.length();i++){
                if(str.empty() or s[i] != str.top())
                    str.push(s[i]);
                else str.pop();
            }
            if(!str.size()) return "-1";
            string ans = "";
            while(!str.empty()){
                ans += str.top();
                str.pop();
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }
};

int main() {
    // start
    ArjunTripathi h;
    string s;
    cin>>s;
    cout<<h.solution(s);
}