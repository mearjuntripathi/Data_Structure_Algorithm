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

        void solution(){
            vector <char> a = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
            int length = a.size();
            if(length == 1){
                cout<<a[0];
                return;
            }
            int result=0;
            int count = 1; 
            for(int i=0;i<length-1;i++){
                if(a[i] == a[i+1])
                    count++;
                else{
                    a[result++] = a[i];
                    if(count > 1){
                        string str = to_string(count);
                        for(int j=0;j<str.length();j++)
                            a[result++] = str[j];    
                    }               
                    count = 1;
                }    
            }
            a[result++] = a[length-1];
            if(count > 1){
                string str = to_string(count);
                for(int j=0;j<str.length();j++)
                    a[result++] = str[j];  
            }   
            for(int i=0;i<result;i++){
                cout<<a[i] <<' ';
            }
        }
};

int main() {
    // start
    ArjunTripathi h;
    h.solution();
}