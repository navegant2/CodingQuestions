#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int search_in_circular_sorted_list(int *array, int start, int end, int value) {
    if (start > end) return -1;
 
    int mid = (start + (end - start)/2);
    if (array[mid] == value) return mid;
 
    /* If arr[l...mid] is sorted */
    if (array[start] <= array[mid])
    {
        /* As this subarray is sorted, we can quickly
           check if key lies in half or other half */
        if (value >= array[start] && value <= array[mid])
           return search_in_circular_sorted_list(array, start, mid-1, value);
 
        return search_in_circular_sorted_list(array, mid+1, end, value);
    }
 
    /* If arr[l..mid] is not sorted, then arr[mid... r]
       must be sorted*/
    if (value >= array[mid] && value <= array[end])
        return search_in_circular_sorted_list(array, mid+1, end, value);
 
    return search_in_circular_sorted_list(array, start, mid-1, value);
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
    int value;
    scanf("%d", &value);

    int result = search_in_circular_sorted_list(array1, 0, N-1, value);
    printf("result: %s\n", result==-1?"not-found":"found"); 

}
