#include<stdio.h>


int get_no_of_ways_to_climbup(int n) {
    
    if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else if ( n == 3) {
        return 4;
    } else {
        return get_no_of_ways_to_climbup(n-1) + get_no_of_ways_to_climbup(n-2) + get_no_of_ways_to_climbup(n-3);
    }
}

main() {

    int n;
    int no_ways;
    scanf("%d", &n);

    no_ways = get_no_of_ways_to_climbup(n);
    printf("%d\n", no_ways);
    
}
