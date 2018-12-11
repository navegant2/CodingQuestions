#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int count_possible_ways(int N) {

    if (N == 1) {
        return 1;
    } else if (N == 2) {
        return 2;
    } else if (N == 3) {
        return 4;
    } else {
        return count_possible_ways(N-1) + count_possible_ways(N-2) + count_possible_ways(N-3);
    }
    return 0;
}

main() {

    int N;
    scanf("%d", &N);

    int num_of_steps = count_possible_ways(N);
    printf("%d\n", num_of_steps);
}
