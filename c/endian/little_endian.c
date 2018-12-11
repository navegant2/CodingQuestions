#include<stdio.h>

main() {
    int n = 1;
    char *c = (char *)&n;

    printf("%p=%x %p=%x %p=%x %p=%x\n", &c[0],c[0], &c[1], c[1], &c[2], c[2], &c[3], c[3]);

}
