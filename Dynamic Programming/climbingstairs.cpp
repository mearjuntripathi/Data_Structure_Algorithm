#include<bits/stdc++.h>
using namespace std;

int climbStair(int n, vector<int> &arr){
	// Recurtion Approach
	// if(n == 1) return arr[1] = 1 ;
	// if(n == 2) return arr[2] = 2;
	// if(arr[n] != -1) return arr[n];
	// return arr[n] = climbStair(n-1,arr) + climbStair(n-2,arr);

	// Iteration Approach
	arr[1] = 1;
	arr[2] = 2;
	for(int i = 3 ; i <= n ; i++){
		arr[i] = arr[i-1] + arr[i-2];
	}
	return arr[n];
}

int main(){
	// you have to take 1 step or 2 step to reached to the top hwo many step you have to go on top
	int n;
	cin >> n;
	vector<int> arr(n+1, -1);
	cout << climbStair(n, arr) << endl;
}
