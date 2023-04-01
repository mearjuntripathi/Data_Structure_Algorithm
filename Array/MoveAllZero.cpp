#include<bits/stdc++.h>

using namespace std;

int main (void) {
    int arr[] = { 5, 6, 0, 4, 6, 0, 9, 0, 8 };
    int n = sizeof(arr) / sizeof (arr[0]);
    int j=0;
    for(int i=0;i<n;i++)
        if(arr[i]!=0)
            arr[j++] = arr[i];
    while(j<n)
        arr[j++]=0;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<", ";
    cout<<endl;
}