#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int findSmallestInCircularList(int *array, int start, int end) {

    while (start < end) {
        int mid = start + ((end-start)/2);
        if (array[mid] > array[end]) { 
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    printf("start:%d, end:%d\n", start, end);
    return array[start];
}
main() {

    int N;
    int *array1;
    int i;

    scanf("%d", &N);
    array1 = (int *)malloc(sizeof(int)*N);
    for(i = 0; i < N; i++) {
        scanf("%d", &array1[i]);
    }

    int result = findSmallestInCircularList(array1, 0, N-1);
    printf("smallest: %d\n", result); 

}
