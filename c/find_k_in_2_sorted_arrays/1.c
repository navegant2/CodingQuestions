#include<stdio.h>
#include<string.h>
#include<stdlib.h>



int find_kth_element(int *array1, int *array2, int k, int array1_len, int array2_len) {

    int i;
    int array1_index = 0;
    int array2_index = 0;
    for (i = 0; i < k-1; i++) {
        if (array1_index < array1_len && array1[array1_index] < array2[array2_index]) { 
            array1_index++;
        } else if (array2_index < array2_len) {
            array2_index++;
        } else {
            return -1;
        }
    }
    if (array1_index == array1_len) {
        return array2[array2_index];
    } else if (array2_index == array2_len) {
        return array1[array1_index];
    } else {
        return array1[array1_index]<array2[array2_index]?array1[array1_index]:array2[array2_index];
    }
}

main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int i;
    int *array1, *array2;

    array1 = (int *)malloc(sizeof(int)*N);
    for (i = 0; i < N; i++) {
        scanf("%d", &array1[i]);
    }
    array2 = (int *)malloc(sizeof(int)*M);
    for (i = 0; i < M; i++) {
        scanf("%d", &array2[i]);
    }
    int k;
    scanf("%d", &k);

    int k_element = find_kth_element(array1, array2, k, N, M);
    printf("%d\n", k_element);

}
