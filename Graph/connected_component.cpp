#include <bits/stdc++.h>
using namespace std;

void traversal(unordered_map<int, vector<int>> &adj, const int &source, unordered_set<int> &visited){
	queue<int> q;
	q.push(source);

	while(!q.empty()){
		int curr = q.front();
		q.pop();
		visited.insert(curr);
		for(int ch : adj[curr]){
			if(!visited.count(ch)){
				visited.insert(ch);
				q.push(ch);
			}
		}
	}
}

int connected_components(unordered_map<int, vector<int>>& adj) {
    unordered_set<int> visited;
    int cnt = 0;

    for (auto& node : adj) {
        if (!visited.count(node.first)) {
            cnt++;
            traversal(adj,node.first,visited);
        }
    }
    return cnt;
}


int main() {
    unordered_map<int, vector<int>> adj;

    // Build graph
    adj[0] = {8, 1, 5};
    adj[1] = {0};
    adj[2] = {3, 4};
    adj[3] = {2, 4};
    adj[4] = {3, 2};
    adj[5] = {0, 8};
    adj[8] = {0, 5};


    cout << "Count of connected component: "
         << connected_components(adj) << endl;
}
