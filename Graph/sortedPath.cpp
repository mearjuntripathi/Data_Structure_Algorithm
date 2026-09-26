#inlcude<bits/stdc++.h>
using namespace std;

int main(){
// a : {b, c},
// b : {a, c, d},
// c : {a, b},
// d : {b, e},
// e : {d}
	unordered_map<char, vector<char>> mp;
	mp['a'] = {'b','c'};
	mp['b'] = {'a', 'c', 'd'};
	mp['c']
}
