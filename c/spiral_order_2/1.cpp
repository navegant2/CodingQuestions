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

void print_spiral_order_layer(vector<vector<int> > &Matrix, int layer) {

    int min_row = layer;
    int max_row = Matrix.size()-layer-1;
    int min_column = layer;
    int max_column = Matrix[layer].size()-layer-1;

    for (int i = layer; i < Matrix[layer].size()-layer-1; i++) {
        cout << Matrix[layer][i] << " ";
    }
    for (int i = layer; i < Matrix.size()-layer-1; i++) {
        cout << Matrix[i][Matrix[layer].size()-layer-1] << " ";
    }   
    for (int i = Matrix[layer].size()-layer-1; i > layer; i--) {
        cout << Matrix[Matrix.size()-layer-1][i] << " ";
    }
    for (int i = Matrix.size()-layer-1; i > layer; i--) {
        cout << Matrix[i][layer] << " ";
    }
}

void print_spiral_order(vector<vector<int> > &Matrix) {

    for (int layer = 0; layer < min(Matrix[0].size(),Matrix.size())/2; layer++) {
        print_spiral_order_layer(Matrix, layer);
    }
    // Remaining element in the layer (middle ones).
    // 1 element in square
    // No elements if row or column is even
    // either one row or column if both row and column is odd
    // row > column (we get 1 column, multiple rows) - (column/2 - columns) (rows = row - columns/2 to row + size() - column/2)
    // columns > row (we get 1 row, multiple columns) 
    int row_size = Matrix.size();
    int column_size = Matrix[0].size();
    if (row_size%2 == 1 || column_size%2 == 1) {
        //Both row & column size are odd
        if (row_size >= column_size) { 
            int column = column_size/2;
            for (int i = column_size/2; i < row_size - column_size/2;i++) {
                cout << Matrix[i][column] << " ";
            }
        } else {
            int row = row_size/2;
            for (int i = row_size/2; i < column_size - row_size/2; i++) {
                cout << Matrix[row][i] << " ";
            }
        }
    }
}

main() {

    int M, N;
    cin >> M;
    cin >> N;

    vector< vector<int> > Matrix(M, vector<int>(N));
    for (int i = 0; i < M;i++) {
        for (int j = 0; j < N; j++) {
            cin >> Matrix[i][j];
        }
    }
    print_spiral_order(Matrix); 
}
