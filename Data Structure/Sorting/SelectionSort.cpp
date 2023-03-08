#include <bits/stdc++.h>
#define start int i; std::cin >> i; Sorting h; while(i--) h.solution(); return 0;

using namespace std;

class Sorting{
    /*
        The algorithm repeatedly selects the smallest (or largest) element 
        from the unsorted portion of the list and swaps it with the first element 
        of the unsorted portion. 
        This process is repeated for the remaining unsorted portion 
        of the list until the entire list is sorted.

        Algorithm :-
            
            STEP 1 − Set MIN to location 0
            
            STEP 2 − Search the minimum element in the list
            
            STEP 3 − Swap with value at location MIN
            
            STEP 4 − Increment MIN to point to next element
            
            STEP 5 − Repeat until list is sorted

        Time Complexity : O(n^2)
        Space Complexity : O(1)
    */ 

    public :
        void printList(vector<int> &nums){
            for(int num : num)
                cout<<num<<' ';
            cout << endl;
        }

    public :
        void SelectionSort(vector<int> &arr){
            int len = arr.size();
            for(int i=0 ; i < len-1 ; i++){
                int min_index = i;
                for(int j = i + 1 ; j < len ; j++)
                    if(arr[min_index] > arr[j])
                        min_index = j;
                int temp = arr[i];
                arr[i] = arr[min_index];
                arr[min_index] = temp;
            }
        }
};

int main() {
    // start
    Sorting h;
    vector<int>arr = {11,2,31,40,5,6,14,67,78,12};
    h.SelectionSort(arr);
    printList(arr);
}