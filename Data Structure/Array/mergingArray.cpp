#include<iostream>
using namespace std;

int* mergeArray(int arr1[], int arr2[], int l1 , int l2){
    int l = l1+l2;
    int arr[l];
    
    int i=0;
    
    for(int j=0;j<l1;j++)
        arr[i++] = arr1[j];
    
    for(int j=0;j<l2;j++)
        arr[i++] = arr2[j];
    
    return arr;
}

int main()
{
  int n,m;
  cin>>n;

  cin>>m;

  int arr1[n],arr2[m],i;

  for(i=0;i<n;i++)
   cin>>arr1[i];

  for(i=0;i<m;i++)
    cin>>arr2[i];
  int l = m+n;
  int arr[l];
  arr = mergeArray(arr1,arr2,n,m);

  for(int i=0;i<(m+n);i++){
    cout<<arr[i] <<',';
  }
  return 0;
}