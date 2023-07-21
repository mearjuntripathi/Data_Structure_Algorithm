#include<bits/stdc++.h>
using namespace std;

class Sorting {
    /*
        Count Sort is a sorting technique based on keys between a specific range.
        It works by counting the number of objects having distinct key values (a kind of hashing).
        Then do some arithmetic operations to calculate the position of each object in the output sequence.

        Algorithm :-

                Step 1 − I get a max element in array.

                Step 2 – Create a new array of length max with element 0.

                Step 3 − Increase a new array element as frequency of element in array.

                Step 4 – After inserting we get a frequency of each element in array.

                Step 5 − Reinsert the value in old array as their frequency.

        Time Complexity: O(N + K) 
            :: Where N is the number of elements in the input array and K is the range of input. :: 
        Auxiliary Space: O(N + K)
    */
    public :
        void printList(vector<int> &nums){
            for(int num : nums)
                cout<<num<<' ';
            cout << endl;
        }

    public :
        void CountSort(vector<int> &arr){
            int max = arr[0];
            int n = arr.size();
            for(int i = 1 ; i < n ; i++)
                if(max < arr[i])
                    max = arr[i];
            
            int *temp = new int[max+1];

            for(int i = 0 ; i < n ; i++)
                temp[arr[i]]++;
                
            int x = 0;
            for(int i = 0 ; i <= max ; i ++){
                while(temp[i]--)
                    arr[x++] = i;
            }

            delete[] temp;
        }
        
};

int main() {
    Sorting s;
    vector<int>arr = {1,2,7,4,5,9,10,5,6,1,2,8,3,6,4,7,9,10};
    s.CountSort(arr);
        s.printList(arr);
    return 0;
}