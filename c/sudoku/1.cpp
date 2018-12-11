#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<deque>
#include<map>

using namespace std;

string s;
vector<string> vs;
vector<int> vs1;
map<char,int> first;


bool HasDuplicate(vector<vector<int> >*result, int begin_row, int end_row, int begin_col, int end_col) {

    deque<bool> numbers(9, false);
    for (int a = begin_row; a < end_row; a++) {
        for (int b = begin_col; b < end_col; b++) {
            if (numbers[(*result)[a][b]-1]) {
                return false;
            }
            numbers[(*result)[a][b]-1] = true;
        }
    }
    return false;
}
bool isValidSudoku(vector<vector<int> >*result) {
    for (int k = 0; k < 9; k++) {
        if (HasDuplicate(result, k, k+1, 0, 9)) {
            return false;
        }
    }
    for (int k = 0; k < 9; k++) {
        if ( HasDuplicate(result, 0, 9, k, k+1)) { 
            return false;
        }
    }
    int region_size = 3;
    int I = 0; 
    for (int I = 0; I < 3; I++) {
        for (int J = 0; J < 3; J++) {
            if ( HasDuplicate(result, I*3, I*3+3 , J*3, J*3+3)) { 
                return false;
            }
        }
    }
    return true;

}
bool isValid (int i, int j, vector<vector<int> > *result, int val) {

    for (int k = 0; k < 9; k++) {
        if ((*result)[k][j] == val) {
            return false;
        }
    }
    for (int k = 0; k < 9; k++) {
        if ((*result)[i][k] == val) {
            return false;
        }
    }
    int region_size = 3;
    int I = i/3; int J = j/3;
    for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 3; b++) {
            if (val == (*result)[I*3 + a][J*3 + b]) {
                return false;
            }
        }
    }
    return true;
}


// 9 x 9 sudoku
bool solve_sudoku(int i, int j, vector<vector<int> > *result) {

    if (i == 9 ) {
        i = 0; j++;
        if (j == 9) {
            return true;
        }
    }
    if ((*result)[i][j] != 0) {
        return solve_sudoku(i+1, j, result);
    }
    int val = 1;
    for (val = 1; val <= 9; val++) {
        if (isValid(i, j, result, val)) {
            (*result)[i][j] = val;
            if(solve_sudoku(i+1, j, result)) {
                return true;
            }
        }
    }
    (*result)[i][j] = 0;
    return false;
}
main() {

    vector<int> temp(9);
    vector<vector<int> > result(9, temp);
    for (int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            result[i][j] = 0;
        }
    }
    solve_sudoku(0, 0, &result);    
    for (int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    bool isSudoku = isValidSudoku(&result);
    printf("%s\n", isSudoku?"Sudoku":"Not a Sudoku");
}
