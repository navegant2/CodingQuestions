#include<stdio.h>
#include<string.h>
#include<stdlib.h>

long swap_bits(long N, unsigned int x, unsigned int y) {

    unsigned long x_y_bits = (1L << x)  | (1L << y);
    if ( (N >> x) & 0x1 != (N >> y) & 0x1 ) { 
        // Flip x_bit and y_bit
        N = N ^ x_y_bits;
    }
    return N;
}

main() {

    long N;
    scanf("%ld", &N);
    unsigned int x, y;
    scanf("%u %u", &x, &y);

    long result = swap_bits(N, x, y);
    printf("swapped : %ld\n", result);
    result = swap_bits(result, x, y);
    printf("swapped : %ld\n", result);
}
