#include<bits/stdc++.h>
using namespace std;

int dfs(unordered_map<int, vector<int>> &adj, const int &source, unordered_set<int> &visited){
	stack<int> st;
	st.push(source);
	visited.insert(source);
	int cnt = 0;
	while(!st.empty()){
		int curr = st.top();
		st.pop();
		for(int node : adj[curr]){
			if(visited.find(node) == visited.end())
				st.push(node);
			visited.insert(node);
		}
		cnt++;
	}
	return cnt;
}

int largestComponent(unordered_map<int, vector<int>> &adj){
	unordered_set<int> visited;
	int max_component = 0;
	for(auto &list : adj){
		if(visited.find(list.first) == visited.end()){
			max_component = max(dfs(adj, list.first, visited), max_component);
		}
	}
	return max_component;
}

int main(){
	unordered_map<int, vector<int>> mp;
	mp[0] = {1,5,8};
	mp[1] = {0};
	mp[2] = {4,3};
	mp[3] = {2,4};
	mp[4] = {2,3};
	mp[5] = {0,8};
	mp[8] = {0,5};

	cout << "Largest Component of given graph: " << largestComponent(mp) << endl;
}
