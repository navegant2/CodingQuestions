#include<stdio.h>
#include<stdlib.h>
int verify(int size, int *array, int total) {

    int i;
    for (i = 0; i < size; i++) {
        if (array[i] == total) {
            return 1;
        }
    }
    return 0;
}

int verify_3sum(int size, int *array, int total) {

    int i, j, k;
    int result; 

    for (i = 0; i < size; i++) {
        if (array[i] >= total) {
            continue;
        }
        for (j = 0; j < size; j++) {
            int temp2 = array[i] + array[j];
            if (temp2 >= total) {
                continue;
            }
            for (k = 0; k < size; k++) {
                result = verify(size, array, temp2 + array[k]);
                if (result == 1) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {

    int size;
    int *array;
    int sum;
    int i;

    scanf("%d", &size);
    array = (int *)malloc(sizeof(int)*size);
    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    scanf("%d", &sum);

    int result = verify_3sum(size, array, sum);
    if (result == 1) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
}
