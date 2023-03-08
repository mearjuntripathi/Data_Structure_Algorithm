#include <bits/stdc++.h>
#define start int i; std::cin >> i; Sorting h; while(i--) h.MergeSort(); return 0;
using namespace std;

class Sorting{

        /*
           
        */

    public :
        void MergeSort(vector<int> &arr, int start, int end){
            int mid = start + (end - start) / 2 ;
        }
};

int main() {
    // start
    Sorting h;
    vector<int>arr = {11,2,31,40,5,6,14,67,78,12};
    h.MergeSort(arr, 0, arr.size()-1);
    for(int a:arr)
        cout<< a << ' ';
}