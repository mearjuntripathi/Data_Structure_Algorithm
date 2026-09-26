#include <bits/stdc++.h>
using namespace std;

// using queue
// bool has_path(unordered_map<char, vector<char>> mp, const char &source, const char &destination){
// 	if(source == destination) return true;
// 	queue<char> q;
// 	q.push(source);
// 	bool reached = false;
// 	while(!q.empty() && !reached){
// 		char curr = q.front();
// 		q.pop();
// 		for(auto ch : mp[curr]){
// 			if(ch == destination) reached = true;
// 			q.push(ch);
// 		}
// 	}
// 	return reached;
// }

// usign stack
// bool has_path(unordered_map<char, vector<char>> mp, const char &source, const char &destination){
// 	if(source == destination) return true;
// 	stack<char> st;
// 	st.push(source);
// 	bool reached = false;
// 	while(!st.empty() && !reached){
// 		char curr = st.top();
// 		st.pop();
// 		for(auto ch : mp[curr]){
// 			if(ch == destination) reached = true;
// 			st.push(ch);
// 		}
// 	}
// 	return reached;
// }

// using recursion
bool has_path(unordered_map<char, vector<char>> mp, const char &source, const char &destination){
	if(source == destination) return true;
	for(auto ch : mp[source]){
		if(has_path(mp, ch, destination)) return true;
	}
	return false;
}

int main(){
	unordered_map<char, vector<char>> mp;
	mp['f'] = {'g', 'i'};
	mp['g'] = {'h'};
	mp['h'] = {};
	mp['i'] = {'g', 'k'};
	mp['j'] = {'i'};
	mp['k'] = {};

	cout << "Chacking is their is a path between g to j: ";
	cout << (has_path(mp, 'j', 'f') ? "Yes" : "NO") << endl;
}
