#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<deque>
#include<map>
#include<iostream>
#include<limits>
#include<algorithm>

using namespace std;

string s;
vector<string> vs;
vector<int> vs1;
map<char,int> first;

void check_reachability_and_modify(vector<vector<char>> &board, int r, int c) {
    
    if (board[r][c] == '1' || board[r][c] == 'X') {
        return;
    }
    board[r][c] = '1';
    if (r + 1 < board.size() && c < board[0].size()) {
        check_reachability_and_modify(board, r+1, c);
    }
    if (r - 1 >= 0 && c < board[0].size()) {
        check_reachability_and_modify(board, r-1, c);
    }
    if (r < board.size() && c + 1 < board[0].size()) {
        check_reachability_and_modify(board, r, c+1);
    }
    if (r < board.size() && c - 1 >= 0) { 
        check_reachability_and_modify(board, r, c-1);
    }

}
void solve(vector<vector<char>>& board) {

    for (int i = 0; i < board.size(); i++) {
        check_reachability_and_modify(board, i, 0);
        check_reachability_and_modify(board, i, board[0].size()-1);
    }
    for (int j = 0; j < board[i].size(); j++) {
        check_reachability_and_modify(board, 0, j);
        check_reachability_and_modify(board, board.size()-1, j);
    }
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
        }
    }
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == '1') {
                board[i][j] = 'O';
            }
        }
    }
    return board;
}

main() {


}
