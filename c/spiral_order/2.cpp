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

vector<int> spiralOrder(vector<vector<int> >matrix) {
    vector<int> result;
    
    if (matrix.size() == 0) {
        return result;
    }
    int rowBegin = 0;
    int rowEnd = matrix.size()-1;
    int colBegin = 0;
    int colEnd = matrix[0].size() - 1;

    while(rowBegin <= rowEnd && colBegin <= colEnd) {

        // left to right
        for(int i = colBegin; i < colEnd; i++) {
            result.push_back(matrix[rowBegin][i]);
        }
        // top to bottom
        for (int i = rowBegin; i < rowEnd; i++) {
            result.push_back(matrix[i][colEnd]);
        }
        // right to left
        for(int i = colEnd; i > colBegin; i--) {
            result.push_back(matrix[rowEnd][i]);
        }
        // bottom to top 
        for (int i = colEnd; i > colBegin; i--) {
            result.push_back(matrix[i][colBegin]);
        }
        rowBegin++;
        rowEnd--;
        colBegin++;
        colEnd--;
    }
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
