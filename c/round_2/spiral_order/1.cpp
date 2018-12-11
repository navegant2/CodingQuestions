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

void print_layer(vector<vector<int>> matrix, int m, int n, int layer) {

    for (int i = layer; i < n - layer-1; i++) {
        cout << matrix[layer][i] << " ";
    }
    for (int i = layer; i < m - layer -1; i++) {
        cout << matrix[i][n-layer-1] << " ";
    }
    for (int i = n - layer - 1; i > layer; i--) {
        cout << matrix[m-layer-1][i] <<  " ";
    }
    for (int i = m - layer - 1; i > layer; i--) {
        cout << matrix[i][layer] << " ";
    }
} 

void print_remaining(vector<vector<int>> matrix, int m, int n) {

    cout << "rem: " << endl;

    if (n >= m) {
        int row = m/2;
        int start = m/2;
        int end = n - (m/2)-1;
        for (int i = start; i <= end; i++) {
            cout << matrix[row][i] << " ";
        }
    } else {
        int col = n/2;
        int start = n/2;
        int end = m - (n/2)-1;
        for (int i = start; i <= end; i++) {
            cout << matrix[i][col] << " ";
        }
    }
}
void spiral_order(vector<vector<int>> matrix) {

    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < m/2; i++) {
        print_layer(matrix, m, n, i);
    }
    if (m%2 == 1 || n %2 == 1) {
        print_remaining(matrix, m, n);
    }
    cout << endl << endl;
}

          

main() {

    vector<vector<int>> matrix;
/*
    matrix.push_back({1, 2, 3, 4, 5, 6});
    matrix.push_back({1, 2, 3, 4, 5, 6});
    matrix.push_back({1, 2, 3, 4, 5, 6});
    // matrix.push_back({1, 2, 3, 4, 5, 6});
*/
    matrix.push_back({1, 2, 3});
    matrix.push_back({11, 12, 13});
    matrix.push_back({21, 22, 23});
    matrix.push_back({31, 32, 33});
    matrix.push_back({41, 42, 43});
    matrix.push_back({51, 52, 53});
    matrix.push_back({61, 62, 63});

    spiral_order(matrix);

}
