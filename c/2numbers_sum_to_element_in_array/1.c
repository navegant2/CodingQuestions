#include<stdio.h>
#include<stdlib.h>

//array is sorted

int verify (int sum, int *array, int size, int begin_index) {
    int i = 0;
    for (i = begin_index; i < size && sum <= array[i]; i++) {
        if (sum == array[i]) {
            printf("sum: %d\n", sum);
            return 1;
        }
    }
    return 0;
}
      

int verify_2numbers_sum_in_array(int size, int *array) {
    int i = 0;
    int j = 0;
    int result = 0;
    
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            result = verify(array[i] + array[j], array, size, j+1); 
            if (result == 1) {
                return 1;
            }
        }
    }
    return 0;
}
main() {

    int *array;
    int i = 0;
    int num = 0;

    scanf("%d",&num);
    array = (int *)malloc(sizeof(int)*num);
    for(i = 0; i < num; i++) {
        scanf("%d", &array[i]);
    }
    int result = verify_2numbers_sum_in_array(num, array);
    if (result == 1) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
}
    
