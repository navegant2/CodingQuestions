#include<stdio.h>
#include<stdlib.h>

void swap(int *array, int a, int b) {

    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

void mutate_index(int *array, int *mutate_index_array, int size) {
    int i;

    for (i = 0; i < size; i++) {
        if (i != mutate_index_array[i]) {
            int temp = mutate_index_array[i];
            swap(mutate_index_array, i, temp);
            swap(array, i, temp); 
        }
    }
}
int main() {

    int size;
    int *array;
    int *mutate_index_array;
    int i;

    scanf("%d",&size);
    array = (int *)malloc(sizeof(int)*size);
    mutate_index_array = (int *)malloc(sizeof(int)*size);
    for (i = 0; i < size;i++) {
        scanf("%d",&array[i]);
    }
    for (i = 0; i < size;i++) {
        scanf("%d",&mutate_index_array[i]);
    }
    mutate_index(array, mutate_index_array, size);
    for (i = 0; i < size;i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    for (i = 0; i < size;i++) {
        printf("%d ", mutate_index_array[i]);
    }
    printf("\n");
}
        
