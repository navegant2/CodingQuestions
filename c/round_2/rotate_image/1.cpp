#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string>
#include<vector>
#include<list>
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

void rotate_layer(vector<vector<int>> &matrix, int rows, int cols, int layer) {

    for (int i = layer; i < rows - layer-1; i++) {
        int temp = matrix[layer][i];
        matrix[layer][i] = matrix[rows-i-1][layer];
        matrix[rows-i-1][layer] = matrix[rows-layer-1][cols-i-1];
        matrix[rows-layer-1][cols-i-1] = matrix[i][cols-layer-1];
        matrix[i][cols-layer-1] = temp; 
    }
}
void print_matrix(vector<vector<int>> matrix) {
    
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void rotate_clockwise_90(vector<vector<int>> &matrix) {

    int m = matrix.size();
    int n = matrix[0].size();

    print_matrix(matrix);
    for (int i = 0; i < m/2; i++) {
        rotate_layer(matrix, m, n, i);
    }
    print_matrix(matrix);
}

main() {

    vector<vector<int>> matrix;
/*
    matrix.push_back({1, 2, 3, 4, 5, 6});
    matrix.push_back({1, 2, 3, 4, 5, 6});
    matrix.push_back({1, 2, 3, 4, 5, 6});
    // matrix.push_back({1, 2, 3, 4, 5, 6});
*/
    matrix.push_back({1, 2, 3, 4, 5});
    matrix.push_back({11, 12, 13, 14, 15});
    matrix.push_back({21, 22, 23, 24, 25});
    matrix.push_back({31, 32, 33, 34, 35});
    matrix.push_back({41, 42, 43, 44, 45});

    rotate_clockwise_90(matrix);

}
