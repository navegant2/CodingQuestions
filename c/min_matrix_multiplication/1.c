#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>


int min_matrix_multiplication(int *matrix_info, int start, int end) {

    int i = 0;
    int grand_matrix_result = INT_MAX;

    if (end == start) {
        return 0;
    }
    for (i = start; i < end; i++) {
        int matrix_result = 0;
        matrix_result = min_matrix_multiplication(matrix_info, start, i) + 
                        min_matrix_multiplication(matrix_info, i+1, end) + 
                        matrix_info[start-1] * matrix_info[i] * matrix_info[end] ;
        if (matrix_result < grand_matrix_result) {
            grand_matrix_result = matrix_result;
        }
    }
    return grand_matrix_result;
}
main() {

    int n;
    int i;
    scanf("%d", &n);
    int *matrix_info;

    matrix_info = (int *)malloc(sizeof(int)*(n+1));
    for (i = 0; i <= n; i++) {
        scanf("%d", &matrix_info[i]);
    }
    int result = min_matrix_multiplication(matrix_info, 1, n);
    printf("%d\n", result);
}
