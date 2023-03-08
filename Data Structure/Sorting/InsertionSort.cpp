#include <bits/stdc++.h>
#define start int i; std::cin >> i; Sorting h; while(i--) h.InsertionSort(); return 0;
using namespace std;

class Sorting{

        /*
            The array is virtually split into a sorted and an unsorted part. 
            Values from the unsorted part are picked and placed at the correct position in the sorted part. 

            Algorithm :-

                Step 1 − If the element is the first one, it is already sorted.

                Step 2 – Move to next element

                Step 3 − Compare the current element with all elements in the sorted array

                Step 4 – If the element in the sorted array is smaller than the current element, iterate to the next element. Otherwise, shift all the greater element in the array by one position towards the right

                Step 5 − Insert the value at the correct position

                Step 6 − Repeat until the complete list is sorted


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
        void InsertionSort(vector<int> &arr){
            int length = arr.size();
            for(int i = 1 ; i < length - 1 ; i++){
                int j = i;
                while(j){
                    if(arr[j-1] > arr[j]){
                        int temp = arr[j];
                        arr[j] = arr[j-1];
                        arr[j-1] = temp;
                    }else break;
                    j--;
                }
            }
        }
};

int main() {
    // start
    Sorting h;
    vector<int>arr = {11,2,31,40,5,6,14,67,78,12};
    h.InsertionSort(arr);
        printList(arr);
}