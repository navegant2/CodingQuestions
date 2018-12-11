#include<stdio.h>
#include<string.h>
#include<stdlib.h>

unsigned int power(unsigned int x, unsigned int y) {

    unsigned int result = 1.0;

    while (y) {
        if (y & 1) {
            result  *= x;
        }
        x *= x ; y >>= 1; 
        printf("Result:%u, X=%u\n", result, x);
    }
    return result;
}

main() {

       unsigned int x = 0;
       int y = 0;

       scanf("%u", &x);
       scanf("%d", &y); 

       unsigned int result = power(x,(unsigned int)y);

       printf("%u\n", result);
}
