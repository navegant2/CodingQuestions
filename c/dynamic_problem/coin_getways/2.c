#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

long *numways; // numways[x] means # ways to get sum x

long getWays(long n, int c_size, long int* c){

    
    // go thru coins 1-by-1 to build up numways[] dynamically
    // just need to consider cases where sum j>=c[i]    
    for (int i=0;i<c_size;i++) {
        for (int j=c[i];j<=n;j++) {
            // find numways to get sum j given value c[i]
            // it consists of those found earlier plus
            // new ones.
            // E.g. if c[]=1,2,3... and c[i]=3,j=5,
            //      new ones will now include '3' with
            //      numways[2] = 2, that is:
            //      '3' with '2', '3' with '1'+'1'
            numways[j]+=numways[j-c[i]]; 
        }
    }    
    return numways[n];    
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
    numways = (long *)malloc(sizeof(long)*(n+1));
    numways[0]=1; // init base case n=0
    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
    long ways = getWays(n, m, c);
    printf("%ld\n", ways);
    return 0;
}

