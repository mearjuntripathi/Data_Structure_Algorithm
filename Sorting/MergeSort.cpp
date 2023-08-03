#include <bits/stdc++.h>
// #define start int i; std::cin >> i; Sorting h; while(i--) h.MergeSort(); return 0;
using namespace std;

class Sorting{

        /*
            Merging is the process of combining two or more sorted array into a third sorted array.
            Divide the array into approximately n/2 sub-arrays of size two and set the element in each sub array. 
            Merging each sub-array with the adjacent sub-array will get another sorted sub-array of size four. 
            Repeat this process until there is only one array remaining of size n.

            Algotithm :- 
                STEP 1 − if it is only one element in the list it is already sorted, return.
                STEP 2 − divide the list recursively into two halves until it can no more be divided.
                STEP 3 − merge the smaller lists into new list in sorted order.

            Time Complexity : O(nlog(n))
            Space Complexity : O(n)
        */

    public :
        void printList(vector<int> &nums){
            for(int num : nums)
                cout<<num<<' ';
            cout << endl;
        }

    public :

        void Merge(vector<int> &arr, int start, int mid, int end){
            //first we create a temp variable
            int temp [(end-start)+1];
            //we create three variable
            int i=start,j=mid+1,k=0;
            // arrang array element in well formate
            while(i <= mid && j <= end){
                if(arr[i] < arr[j]){
                    temp[k++] = arr[i++];
                }
                else{
                    temp[k++] = arr[j++];
                }
            }
            while(j<=end){
                temp[k++] = arr[j++];
            }
            while(i<=mid){
                temp[k++] = arr[i++];
            }
            k=0;
            for(int l = start ; l <= end ; l++)
                arr[l] = temp[k++];
        }

        void MergeSort(vector<int> &arr, int start, int end){
            if(end>start){

                int mid = start + (end - start) / 2 ;

                //for start to mid
                MergeSort(arr,start,mid);

                //for mid to end
                MergeSort(arr,mid+1,end);
                
                //now we merge both
                Merge(arr,start,mid,end);
            }
        }
};

int main() {
    // start
    Sorting h;
    vector<int>arr = {11,2,31,40,5,6,14,67,78,12};
    h.MergeSort(arr, 0, arr.size()-1);
    h.printList(arr);
}