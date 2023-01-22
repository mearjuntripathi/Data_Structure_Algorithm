#include<bits/stdc++.h>
using namespace std;

class GFG{
    public:
        void solution(int *arr, int n){
            if(n<3){
                cout<<"Invalid Formate"<<endl;
                return;
            }
            int first,second,third;
            int i;
            first = second = third = INT_MIN;
            for(i=0;i<n;i++){
                if(arr[i]>first){
                    third = second;
                    second = first;
                    first = arr[i];
                }
                else if(arr[i] > second && arr[i] != first){
                    third = second;
                    second = arr[i];
                }
                else if(arr[i] > third && arr[i] != second){
                    third = arr[i];
                }
            }
            cout<<first<<' '<<second<<' '<<third<<endl;
        }
};

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    GFG g;
    g.solution(arr,n);
    return 0;
}