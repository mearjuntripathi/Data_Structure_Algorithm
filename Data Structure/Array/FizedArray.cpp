#include<bits/stdc++.h>

using namespace std;

void fixedarray(int arr[] , int n){
    int temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[j] == i){
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
                break;
            }
        }
    }
    cout<<"Before shifting array"<<endl;
    for(int i=0;i<n;i++){
        cout << arr[i] << ", ";
    }
    cout<<endl;
    for(int i=0;i<n;i++)
        if(arr[i] != i )
            arr[i] = -1;
}

int main (void) {
    int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
         11, 12, 13, 14, 15, 16, 17, 18, 19 };
    cout<<"array"<<endl;
    int n = sizeof(arr) / sizeof(arr[0]);
    for(int i=0 ; i < n ; i++)
        cout << arr[i] << ", " ;
    cout<<endl;
    fixedarray(arr , n);
    cout<<"After shifting array"<<endl;
    for(int i=0 ; i < n ; i++)
        cout << arr[i] << ", " ;
    cout<<endl;
} 