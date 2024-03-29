#include <bits/stdc++.h>
#define start int i; std::cin >> i; Sorting h; while(i--) h.QuickSort(); return 0;
using namespace std;

class Sorting{

        /*
            It is one of the widely used sorting techniques and it is also called the partition-exchange sort. 
            Quick sort is an efficient algorithm and it passes a very good time complexity in average case.  

            Algorithm :-

                Step 1: First check low is less then high
                Step 2: Then make a pivot to lower element
                Step 3: divide a array in two part 
                    Step a: left side has a lower element as pivot 
                    Step b: right side has a greator element as pivot
                Step 4: And repeat step 1-3 for two subarray 
                    Step a: one for greator element as pivot 
                    Step b: one for lower lower element as pivot

            Time Complexity [ wrost case O(n^2) || best case : O(n) || average case : O(n log n)  ]
            Space Complexity : O(log n)
        */

    public :
        void printList(vector<int> &nums){
            for(int num : nums)
                cout<<num<<' ';
            cout << endl;
        }

    public :

        int partition(vector<int> &arr, int low, int high){
            // make pivot lower elemnt
            int pivot = low;
            
            int i = low, j = high;
            while(i < j){
                // making array less element at one side and greater element one side of pivot 
                while(arr[i] <= arr[pivot]) i++;
                while(arr[j] > arr[pivot]) j--;
                if(i < j)
                    swap(arr[i] , arr[j]);
            }

            swap(arr[j] , arr[pivot]); // swaping the value of pivot at their original place

            return j;
        }

        void QuickSort(vector<int> &arr, int low, int high){
            // first i check low is lower then high
            if(low < high){

                int pi = partition(arr,low,high);

                QuickSort(arr, low, pi - 1); // for pivot left

                QuickSort(arr, pi + 1, high); // for pivot right
            }
        }
};

int main() {
    // start
    Sorting h;
    vector<int>arr = {11,2,31,40,5,6,14,67,78,12};
    h.QuickSort(arr, 0, arr.size()-1);
        h.printList(arr);
}