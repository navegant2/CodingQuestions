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

// print spiral order of a rectangular = tryout 


void util_spiral_matrix(int **M, int size_x, int size_y, int index, int *spiral_array, int *s_index) {

    int i = 0;
    for (i = index; i < size_y - index - 1; i++) {
        spiral_array[(*s_index)++] = M[index][i];
    }
    for (i = index; i < size_x - index - 1; i++) {
        spiral_array[(*s_index)++] = M[i][size_y-index-1];
    }
    for (i = size_y - index - 1; i > index; i--) {
        spiral_array[(*s_index)++] = M[size_x-index-1][i];
    }
    for (i = size_x - index - 1; i > index; i--) {
        spiral_array[(*s_index)++] = M[i][index];
    }
}
    
void print_spiral_matrix(int **M, int size_x, int size_y, int *spiral_array) {

    int i;
    int s_index = 0;

    for (i = 0; i < size_x/2; i++) {
        util_spiral_matrix(M, size_x, size_y, i, spiral_array, &s_index);
    }
    if (size_x % 2 != 0 || size_y % 2 != 0) { // odd row or odd column 
        if (size_x > size_y) {
            for (i = size_x/2; i < size_x - size_y/2; i++) {
                spiral_array[s_index++] = M[i][size_y/2];
            }
        } else {
            for (i = size_x/2; i < size_y - size_x/2; i++) {
                spiral_array[s_index++] = M[size_x/2][i];
            }
        }
    }
}
main() {
    int X, Y;
    scanf("%d %d", &X, &Y);
    int i, j;

    int **M;
    int *spiral_array;

    M = (int **)malloc(sizeof(int *)*X);
    for (i = 0; i < X; i++) {
        M[i] = (int *)malloc(sizeof(int)*Y);
    }
    spiral_array = (int *)malloc(sizeof(int)*X*Y);

    for (i = 0; i < X; i++) {
        for (j = 0; j < Y; j++) {
            scanf("%d", &M[i][j]);
        }
    }
    print_spiral_matrix(M, X, Y, spiral_array);
    for (i = 0; i < X*Y; i++) {
        printf("%d ", spiral_array[i]);
    }
}
