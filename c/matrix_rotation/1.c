#include<stdio.h>
#include<stdlib.h>


void print_matrix(int **matrix, int n) {
    int i;
    for (i = 0; i < n; i++) {
        int j;
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("---------------\n");
}
void rotate_matrix_90_clockwise(int **matrix, int n) {
    int layer = 0;
    int index = 0;

    for (layer = 0; layer < n/2; layer++) {
        int start = layer;
        int end = n - layer - 1;
        for (index = start; index < end; index++) {
            int top = matrix[layer][index];
            matrix[layer][index]= matrix[n-index-1][layer];
            matrix[n-index-1][layer] = matrix[n-layer-1][n-index-1];
            matrix[n-layer-1][n-index-1] = matrix[index][n-layer-1];
            matrix[index][n-layer-1] = top;
            print_matrix(matrix, n);
        }
    }
}
main() {
    int n;
    int i;
    scanf("%d", &n);

    int **matrix;

    matrix = (int **)malloc(sizeof(int *)*n);
    for (i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(sizeof(int)*n);
    }
    for (i = 0; i < n; i++) {
        int j;
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    rotate_matrix_90_clockwise(matrix,n);
    print_matrix(matrix, n);
}
