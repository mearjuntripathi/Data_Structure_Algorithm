#include <bits/stdc++.h>

using namespace std;

void depth_first_search(unordered_map<char, vector<char>> &adj, const char &source){
	stack<char> st;

	st.push(source);

	while(!st.empty()){
		char curr = st.top();
		st.pop();
		for(char n: adj[curr]){
			st.push(n);
		}
		cout << curr << ' ';
	}
	cout << endl;
}

void breadth_first_search(unordered_map<char, vector<char>> &adj, const char &source){
	queue<char> q;
	
	q.push(source);
	
	while(!q.empty()){
		char curr = q.front();
		q.pop();
		for(char n: adj[curr]){
			q.push(n);
		}
		cout << curr << ' ';
	}
	cout << endl;
}


int main(){
// {
// 	'a' : {'c', 'b'},
// 	'b' : {'d'},
// 	'c' : {'e'},
// 	'd' : {'f'},
// 	'e' : {},
// 	'f' : {}
// }

	unordered_map<char, vector<char>> mp;
	mp['a'] = {'c', 'b'};
	mp['b'] = {'d'};
	mp['c'] = {'e'};
	mp['d'] = {'f'};
	mp['e'] = {};
	mp['f'] = {};

	cout << "Depth First Search: ";
	depth_first_search(mp, 'a');

	cout << "Breadth First Search: ";
		breadth_first_search(mp, 'a');
	
	
}
