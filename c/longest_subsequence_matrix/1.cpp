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

int longestIncreasingPathHelper(vector<vector<int> >& matrix, int r, int c, int *len) {
       

cout << "row:column: " << r << ":" << c  << " len: " << *len << endl;
 
        vector<vector<int> > dirs = {{-1, 0}, {1,0}, {0, -1}, {0, 1}};
        for (int i = 0; i < dirs.size(); i++) {
            int rr = r + dirs[i][0]; int cc = c + dirs[i][1];
            if (rr < 0 || rr >= matrix.size() || cc < 0 || cc >= matrix[0].size()) { continue;}
            if (matrix[r][c] < matrix[rr][cc]) {
                longestIncreasingPathHelper(matrix, rr, cc, (*len)+1);
            }
        }
        return len;
    }
    int longestIncreasingPath(vector<vector<int> >& matrix) {
        
        int max_len = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                int len = 0;
                longestIncreasingPathHelper(matrix, i, j, &len);
                max_len = max(max_len, len);
            }
        }
        return max_len;
    }

main() {

    vector<vector<int>> matrix(3, vector<int>(3));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << longestIncreasingPath(matrix) << endl; 
}
