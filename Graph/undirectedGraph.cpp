#include<bits/stdc++.h>
using namespace std;

void depth_first_traversal(unordered_map<char, vector<char>> &mp, const char &source, vector<bool> visited){
	stack<char> st;
	st.push(source);
	visited[source-'a'] = true;

	while(!st.empty()){
		char curr = st.top();
		st.pop();
		for(auto ch: mp[curr]){
			if(!visited[ch-'a'])
				st.push(ch);
			visited[ch-'a'] = true;
		}
		cout << curr << ' ';
	}
	cout << endl;
}
/* Recursive Approach */

// void depth_first_traversal(unordered_map<char, vector<char>> &mp, const char& source, vector<bool> &visited){
// 	if(visited[source-'a']) return;
// 	cout << source << ' ';
// 	visited[source-'a'] = true;
// 	for(auto ch : mp[source]){
// 		depth_first_traversal(mp, ch, visited);
// 	}
// }

void breadth_first_traversal(unordered_map<char, vector<char>> &mp, const char &source, vector<bool> visited){
	queue<char> q;
	q.push(source);
	visited[source-'a'] = true;
	
	while(!q.empty()){
		char curr = q.front();
		q.pop();
		for(auto ch: mp[curr]){
			if(!visited[ch-'a'])
				q.push(ch);
			visited[ch-'a'] = true;
		}
		cout << curr << ' ';
	}
	cout << endl;
}

bool has_path(unordered_map<char, vector<char>> &mp, const char &source, const char &destination, vector<bool> visited){
	// recursion
	if(source == destination) return true;
	visited[source-'a']=true;
	for(auto ch : mp[source]){
		if(!visited[ch-'a'])
			return has_path(mp, ch, destination, visited);
	}
	return false;
	
	// dfs
// 	if(source == destination) return true;
// 	stack<char> st;
// 	visited[source-'a'] = true;
// 
// 	st.push(source);
// 	while(!st.empty()){
// 		char curr = st.top();
// 		st.pop();
// 		for(auto ch : mp[curr]){
// 			if(!visited[ch-'a']) st.push(ch);
// 			visited[ch-'a'] = true;
// 			if(ch == destination) return true;
// 		}
// 	}
// 	return false;

	// bfs
	// if(source == destination) return true;
	// 	queue<char> q;
	// 	visited[source-'a'] = true;
	// 
	// 	q.push(source);
	// 	while(!q.empty()){
	// 		char curr = q.front();
	// 		q.pop();
	// 		for(auto ch : mp[curr]){
	// 			if(!visited[ch-'a']) q.push(ch);
	// 			visited[ch-'a'] = true;
	// 			if(ch == destination) return true;
	// 		}
	// 	}
	// 	return false;
	
}

int main(){
	vector<pair<char, char>> edge = {{'i','j'},
									 {'k','i'},
									 {'m','k'},
									 {'k','l'},
									 {'o','n'},
									 {'j','k'}};

	cout << "Edge to adjacency List conversion: \n";
	unordered_map<char, vector<char>> mp;
	for(auto it : edge){
		mp[it.first].push_back(it.second);
		mp[it.second].push_back(it.first);
	}
	/* Adjacency list Conversion */
	cout<<"{\n";
	for(auto it : mp){
		cout << "  " << it.first << ": [";
		for(auto i : it.second) cout << i << ',';
		cout << "],\n";
	}
	cout<<"}\n";
	vector<bool> visited(26, false);

	cout << "Depth First Traversal: ";
	depth_first_traversal(mp, 'i', visited);

	cout << "Breadth First Traversal: ";
	breadth_first_traversal(mp, 'i', visited);


	cout << "Has Path from i to n: ";
	cout << ((has_path(mp, 'i','n',visited)) ? "YES" : "NO");
	cout << endl;
}
