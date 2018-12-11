#include<stdio.h>
#include<string.h>
#include<stdlib.h>



int lis(int *array , int index, int size, int *max_ref) {

    int i;

    for (i = index; i < size; i++) {
        if (array[i-1] < array[i]) {
            max_ref++;
            int result = lis(array, i+1, size, max_ref);
            if (result > *max_ref) {
                *max_ref = result;
            }
        }
    }
    return *max_ref;
}
int max_long_subsequence(int *array, int size) {

    int i;
    int max_reference = 1;

    max_reference = lis(array, 1, size, &max_reference);
    
    return max_reference;
} 

int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of lis is %dn",
           max_long_subsequence( arr, n ));
    return 0;
}
