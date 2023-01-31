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

        int isPalindrom(string &s, int l, int r){
            while(l>=0 and r<s.length() and s[l] == s[r]){
                l--;
                r++;
            }
            return r-l-1;
        }

        string solution(string s){
            int n=s.length();
            string str = "";
            if(n==1)
                return s;
            if(n==2)
                if(s[0] == s[1])
                    return s;
                else{str += s[0]; return str;}
            
            int ans = 0, st = 0;

            for(int i=0;i<n;i++){
                int l1 = isPalindrom(s,i,i);
                int l2 = isPalindrom(s,i,i+1);
                int l = max(l1, l2);

                if(l > ans){
                    ans = l;
                    st = i - (l-1)/2;
                }
            }
            return s.substr(st,ans);

        }
};

int main() {
    // start
    ArjunTripathi h;
    string s;
    cin>>s;
    cout<<h.solution(s);
}