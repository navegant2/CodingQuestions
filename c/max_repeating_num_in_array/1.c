#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int get_max_repeated_num(int *array, int size) {
    int i;
    
    

main() {
    int n;
    int i; 
    int *array;

    scanf("%d", &n);
    array = (int *)malloc(sizeof(int)*n);
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    int max_repeated_num = get_max_repeated_num(array, n);
    printf("%d\n", max_repeated_num);
}

    
