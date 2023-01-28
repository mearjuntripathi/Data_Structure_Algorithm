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
            //Code Here
        }
};

int main() {
    // start
    ArjunTripathi h;
    
    h.solution();
}