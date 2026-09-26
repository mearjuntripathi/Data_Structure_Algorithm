#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<char>> &board, string &word, int i, int j, int pos){
	if(pos == word.length()) return true;
	int row = board.size();
	int col = board[0].size();
	if(i < 0 || j < 0 || i >= row || j >= col || board[i][j] != word[pos]) return false;

	char ch = board[i][j];
	board[i][j] = '#';
	bool res = dfs(board, word, i+1, j, pos+1) ||
			   dfs(board, word, i, j+1, pos+1) ||
			   dfs(board, word, i-1, j, pos+1) ||
			   dfs(board, word, i, j-1, pos+1);
	board[i][j] = ch;
	return res;
}

bool search(vector<vector<char>> &board, string &word){
	int row = board.size();
	int col = board[0].size();
	for(int i = 0 ; i < row ; i++){
		for(int j = 0 ; j < col ; j++){
			if(board[i][j] == word[0])
				if(dfs(board,word,i,j,0)) return true;
		}
	}
	return false;
}

int main(){
	int row, col;
	cin >> row >> col;

	vector<vector<char>> board(row, vector<char>(col,0));

	for(int i = 0 ; i < row ; i++){
		for(int j = 0 ; j < col ; j++){
			cin >> board[i][j];
		}
	}

	cout << "Your given input is : \n";
	for(int i = 0 ; i < row ; i++){
		for(int j = 0 ; j < col ; j++){
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
	string word;
	cin >> word;

	cout << "Is word matched in board: ";
	cout << (search(board, word) ? "YES" : "NO")  << endl; 
}
