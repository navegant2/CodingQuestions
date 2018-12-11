#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printArray(int *array, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int partition(int *array, int start, int end, int n) {

    int pivot = array[end];
    int i = start, j = end-1;

    while (i < j) { 
        if (array[i] <= pivot) {
            i++;
        }
        if (array[j] >= pivot) {
            j--;
        }
        if (i >= j) {
            break;
        }
        swap(&array[i], &array[j]);
        i++; j--;
    }
printf("start:%d, end:%d, i:%d\n", start, end, i);
printArray(array,n);
    swap(&array[i], &array[end]);
    return i;
}

    

void quicksort(int *array, int start, int end, int n) {

    if (end > start) {
        int p1 = partition(array, start, end, n); 
        quicksort(array, start, p1-1,n);
        quicksort(array, p1+1, end,n);
    }
}
main() {
    int n;
    scanf("%d",&n);
    int i;
    int *array = (int *)malloc(sizeof(int)*n);

    for(i = 0; i < n; i++) {
        scanf("%d",&array[i]);
    }
    quicksort(array, 0, n-1, n);
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
