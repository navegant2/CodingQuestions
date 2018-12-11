#include<stdio.h>

int get_min_cost_to_fill_bag(int n, int *cost_array) {
    int i = 0;



}
main() {
    int n;
    int i;
    scanf("%d", &n);
    
    int *cost_array = (int *)malloc(sizeof(int)*n);
    for (i = 0; i < n; i++) {
        scanf("%d", &cost_array[i]);
    }
    int result = get_min_cost_to_fill_bag(n, cost_array);
    printf("output is %d\n", result);

}
