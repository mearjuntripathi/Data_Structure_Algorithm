#include <bits/stdc++.h>

using namespace std;

void swap (int *n1, int *n2){
    *n1 += *n2;
    *n2 = *n1-*n2;
    *n1 -= *n2;
}

// Selection Sorting Techniquices;
/*
    select small element
    and make it first
    concept used in 
    mergeing concept
*/
void selectionSort(int arr[], int n){
    cout<<"using selection sort"<<endl;
    for(int i=0;i<n;i++){
        int min_indx = i;
        for(int j=i+1 ;j<n;j++)
            if(arr[j]<arr[min_indx])
                min_indx = j;
        if(min_indx!=i)
            swap(&arr[i],&arr[min_indx]);
    }
}

// Bubble sorting Techniques;

/*
    repeatedly swaping 
    concept used in 
    mergeing concept
*/

void bubbleSort(int arr[], int n){
    cout<<"using bubble sort"<<endl;
    for(int i=0;i<n-1;i++){
        int update = 0;
        for(int j=0;j<n-i-1;j++)
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                update++;
            }
        if(!update)
            return;
    }
}

// Recurtion Bubble Sort Techniques;
/*
    recurtion swaping
    concept used in 
    mergeing concept
*/

void recurtionBubbleSort(int arr[], int n){
    if(n == 1)
        return;
    int update = 0;
    for(int i=0;i<n-1;i++)
        if(arr[i]>arr[i+1]){
            swap(&arr[i],&arr[i+1]);
            update++;
        }
    if(!update)
        return;
    recurtionBubbleSort(arr,n-1);
}

//Insertion Sort Techniques;
/*
    swapping with
    begning elements 
    concept used in 
    mergeing concept
*/

void insertionSort(int arr[], int n){
    for(int i=1;i<n;i++){
        int j=i;
        while(j){
            if(arr[j-1]>arr[j])
                swap(&arr[j],&arr[j-1]);
            else break;
            j--;
        }
    }
}

// Quicksort Techniques
/*
    Pivot & Partition
    concept used in 
    quicksort concept
*/
void quickSort(){}


int main(void) {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Before sorting array"<<endl;
    for(int i=0 ; i < n ; i++)
        cout << arr[i] << ", " ;
    cout<<endl;
    insertionSort(arr,n);
    cout<<"Before sorting array"<<endl;
    for(int i=0 ; i < n ; i++)
        cout << arr[i] << ", " ;
    cout<<endl;
}