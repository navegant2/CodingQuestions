#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

long getWays(long n, int c_size, long int* c){
 
    long value = 0; 
    if (n == 0) {
        return 1;   
    } else if (c_size == 0) {
        return 0;
    } else if (c_size == 1) {
        if (n < c[0]) {
            return 0;
        } 
    }
    if (n - c[0] >= 0 ) {
        value = getWays(n-c[0], c_size, c);
    }  
    return value + getWays(n, c_size-1, &c[1]);
}

int main() {
    int n; 
    int m; 
    int c_i = 0;

    scanf("%d %d", &n, &m);
    long *c = malloc(sizeof(long) * m);
    for(c_i = 0; c_i < m; c_i++){
       scanf("%ld",&c[c_i]);
    }
    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
    long ways = getWays(n, m, c);
    printf("%ld\n", ways);
    return 0;
}

