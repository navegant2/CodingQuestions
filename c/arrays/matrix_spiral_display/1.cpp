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

// print spiral order of a n x n (nxn) matrix !! Extend to n x m


void util_spiral_matrix(int **M, int size, int index, int *spiral_array, int *s_index) {

    int i = 0;
    for (i = index; i < size - index - 1; i++) {
        spiral_array[(*s_index)++] = M[index][i];
    }
    for (i = index; i < size - index - 1; i++) {
        spiral_array[(*s_index)++] = M[i][size-index-1];
    }
    for (i = size - index - 1; i > index; i--) {
        spiral_array[(*s_index)++] = M[size-index-1][i];
    }
    for (i = size - index - 1; i > index; i--) {
        spiral_array[(*s_index)++] = M[i][index];
    }
}
    
void print_spiral_matrix(int **M, int size, int *spiral_array) {

    int i;
    int s_index = 0;

    for (i = 0; i < size/2; i++) {
        util_spiral_matrix(M, size, i, spiral_array, &s_index);
    }
    if (size % 2 != 0) {
        spiral_array[s_index] = M[size/2][size/2];
    }
}
main() {
    int N;
    scanf("%d", &N);
    int i, j;

    int **M;
    int *spiral_array;

    M = (int **)malloc(sizeof(int *)*N);
    for (i = 0; i < N; i++) {
        M[i] = (int *)malloc(sizeof(int)*N);
    }
    spiral_array = (int *)malloc(sizeof(int)*N*N);

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &M[i][j]);
        }
    }
    print_spiral_matrix(M, N, spiral_array);
    for (i = 0; i < N*N; i++) {
        printf("%d ", spiral_array[i]);
    }
}
