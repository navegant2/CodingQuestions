#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int get_min_multiplication(int *array, int size, int i) {

    int result = 0;
    
    if (i == size-1) {
        return array[i]*array[i-1];
    } 
    return 

main() {

    int *array;
    int N;
    scanf("%d", &N);

    array = (int *)malloc(sizeof(int)*N);
    int i;
    for (i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }
    int result = get_min_multiplication(array, N);
    printf("%d\n", result);
}
