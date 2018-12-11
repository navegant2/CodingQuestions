#include<stdio.h>
#include<stdlib.h>
#include<std>

int get_largest_histogram(int *array, int n) {
    std::stack position;
    std::stack value;

    for (int i = 0; i < n; i++) {
        if (value.empty() ||  


main() {
    int n;
    int *array;
    scanf("%d", &n);
    array = (int *)malloc(sizeof(int)*n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    int max_value = get_largest_histogram(array, n);
    printf("%d\n", max_value);
}
    
