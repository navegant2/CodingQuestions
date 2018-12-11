#include<stdio.h>
#include<stdlib.h>

main() {

    char *ch;

    ch = (char *)malloc(sizeof(char)*12);

    printf("%lu\n", sizeof(ch));

}
