#include<bits/stdc++.h>
using namespace std;

class Solution {
        bool is_winner(char board[3][3], char player) {
            // Check for a win condition
            for (int i = 0; i < 3; ++i) {
                if (
                    (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == player) ||
                    (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == player)
                ) 
                    return true;
            }
            
            // Check diagonals
            if (
                (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == player) ||
                (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == player)
            )
                return true;
            
            return false;
        }
        
    public:
        string tictactoe(vector<vector<int>>& moves) {
            if (moves.size() < 5)
                return "Pending";
            
            char board[3][3] = {}; // Initialize the 3x3 game board with zeros
            
            for (int i = 0; i < moves.size(); ++i) {
                if (i % 2) {
                    board[moves[i][0]][moves[i][1]] = 'B';
                    if (is_winner(board, 'B'))
                        return "B";
                } else {
                    board[moves[i][0]][moves[i][1]] = 'A';
                    if (is_winner(board, 'A')) 
                        return "A";
                }
            }
            if (moves.size() == 9)
                return "Draw";
            
            return "Pending";
        }
        
};

int main() {
    Solution s;
    vector<vector<int>> moves = {{0,0},{2,0},{1,1},{2,1},{2,2}};
    cout<<s.tictactoe(moves)<<endl;
    
    moves = {{0,0},{1,1},{0,1},{0,2},{1,0},{2,0}};
    cout<<s.tictactoe(moves)<<endl;

    moves = {{0,0},{1,1},{2,0},{1,0},{1,2},{2,1},{0,1},{0,2},{2,2}};
    cout<<s.tictactoe(moves)<<endl;

    moves = {{0,0},{2,0},{1,1},{2,1},{2,2}};
    cout<<s.tictactoe(moves)<<endl;

    moves = {{0,0},{1,1}};
    cout<<s.tictactoe(moves)<<endl;
    return 0;
}