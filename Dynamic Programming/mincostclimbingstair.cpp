#include<bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
        
}

int main(){
	int n;
	cin >> n;
	vector<int> cost(n);
	
	for(int i = 0 ;i < n ;i++){
		cin >> cost[i];
	}

	cout << minCostClimbingStairs(cost) << endl;
}
