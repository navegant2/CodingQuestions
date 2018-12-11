#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int get_max_ways_of_reaching_n(int n) {
    if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else if (n == 3) {
        return 4;
    } else {
        return get_max_ways_of_reaching_n(n-3) + get_max_ways_of_reaching_n(n-2) + get_max_ways_of_reaching_n(n-1);
    }
}
main() {
    int n;
    scanf("%d", &n);
    int max_ways = get_max_ways_of_reaching_n(n);
    printf("%d\n", max_ways);
}
