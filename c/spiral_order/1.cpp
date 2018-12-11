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

vector<int> get_spiral_order_for_leaf(vector<vector<int> > &matrix, int leaf, vector<int> *result_ptr, int n_rows, int n_cols) {

    vector<int> &result = *result_ptr;

    // Left to right 
cout <<  " leaf:" << leaf << " n_rows-leaf-1:" << n_rows-leaf-1 << " n_cols-leaf-1:" << n_cols-leaf-1 << endl;

    for (int i = leaf; i < n_cols-leaf-1; i++) {
cout << "leaf:i->" << leaf << ":" << i  << endl;
        result.push_back(matrix[leaf][i]);
    }
    // top to bottom to the right
    for (int i = leaf; i < n_rows-leaf-1; i++) {
cout << "i:n_cols-leaf-1->" << i << ":" << n_cols-leaf-1  << endl;
        result.push_back(matrix[i][n_cols-leaf-1]);
    }
    // right to left, on the bottom
    for (int i = n_cols-leaf-1; i > leaf; i--) {
cout << "n_rows-leaf-1:i->" << n_rows-leaf-1 << ":" << i  << endl;
        result.push_back(matrix[n_rows-leaf-1][i]);
    }
    // bottom to top, to the left
    for (int i = n_rows-leaf-1; i > leaf; i--) {
cout << "i:leaf->" << i << ":" << leaf << endl;
        result.push_back(matrix[i][leaf]); 
    }
cout << "------------------------" << endl;
}

vector<int> spiralOrder(vector<vector<int> >& matrix) {

    int n_rows = matrix.size();
    int n_cols = matrix[0].size();
    vector<int> result;

    for (int i = 0; i < n_rows/2; i++) {
cout << "i :" << i << endl;
        get_spiral_order_for_leaf(matrix, i, &result, n_rows, n_cols);
    }
/*
    // If both rows & cols are odd, we have middle to take care of 
    if (n_rows % 2 == 1 && n_cols % 2 == 1) {
        if (n_rows > n_cols) {
            int col = n_cols/2;
            for (int i = 0; i < n_rows - n_cols - 1; i++) {
                result.push_back(matrix[col+i][col]); 
            }
        } else {
            int row = n_rows/2;
            for (int i = 0; i < n_cols - n_rows - 1; i++) {
                result.push_back(matrix[row][row+i]); 
            }
        } 
    }
*/
    return result;
}

main() {
    int N;
    int M;
    cin >> N; 
    cin >> M; 

    vector<vector<int> >matrix(N,vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }
    vector<int> result = spiralOrder(matrix);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << "  ";
    }
    cout << endl;
}
