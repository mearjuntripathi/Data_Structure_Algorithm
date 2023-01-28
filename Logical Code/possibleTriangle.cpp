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

        void solution(vector<int> A){
            int n = A.size();
            sort(A.begin(), A.end());
            int count = 0;

            for(int i=n-1;i>0;i--){
                int l=0,r=i-1;
                while(l<r){
                    if(A[l] + A[r] > A[i]){
                        count += r-l;
                        r--;
                    }else l++;
                }
            }
            cout << "Possible Triangle in array : " << count << endl;
        }
};

int main() {
    // start
    ArjunTripathi h;
    vector<int> A = { 10, 21, 22, 100, 101, 200, 300 };
    h.solution(A);
}