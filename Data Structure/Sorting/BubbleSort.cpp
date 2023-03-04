#include <bits/stdc++.h>
#define start int i; std::cin >> i; Sorting h; while(i--) h.BubbleSort(); return 0;
using namespace std;

class Sorting{

        /*
            Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping 
            the adjacent elements if they are in the wrong order. 
            This algorithm is not suitable for large data sets as its average and 
            worst-case time complexity is quite high.

            Algorithm :- 

                STEP 1: Start with the first element.

                STEP 2: Compare the current element with the next element.

                STEP 3: If the current element is greater than the next element, then swap both the elements. If not, move to the next element.

                STEP 4: Repeat steps 1 – 3 until we get the sorted list.

            Time Complexity : O(n^2)
            Space Complexity : O(1)
        */

    public :
        void BubbleSort(vector<int> &arr){
            int length = arr.size();
            for(int i=0;i<length-1;i++){
                int update = 0;
                for(int j=0;j<length-1-i;j++){
                    if(arr[j] > arr[j+1]){
                        int temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                        update++;
                    }
                }
                if(!update)
                    break;
            }
        }
};

int main() {
    // start
    Sorting h;
    vector<int>arr = {11,2,31,40,5,6,14,67,78,12};
    h.BubbleSort(arr);
    for(int a:arr)
        cout<< a << ' ';
}