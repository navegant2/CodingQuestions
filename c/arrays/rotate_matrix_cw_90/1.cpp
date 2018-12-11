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

// rotate nxn matrix by 90 in cw 


void util_rotate_cw_90(int **M, int size, int index) {

    int i = 0;

    for (i = index; i < size-index-1; i++) {
        int temp = M[index][i];
        M[index][i] = M[size-i-1][index];
        M[size-i-1][index] = M[size-index-1][size-i-1];
        M[size-index-1][size-i-1] = M[i][size-index-1];
        M[i][size-index-1] = temp;
    }
}
void rotate_cw_90(int **M, int size) {

    int i;
    int s_index = 0;

    for (i = 0; i < size/2; i++) {
        util_rotate_cw_90(M, size, i);
    }
}
main() {
    int N;
    scanf("%d", &N);
    int i, j;

    int **M;

    M = (int **)malloc(sizeof(int *)*N);
    for (i = 0; i < N; i++) {
        M[i] = (int *)malloc(sizeof(int)*N);
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &M[i][j]);
        }
    }
    rotate_cw_90(M, N);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}
