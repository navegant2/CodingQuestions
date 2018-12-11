#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void convert_to_roman(int n) {

    while(n > 0) {
        if (n >= 1000) {
            printf("M");
            n = n - 1000;
        } else if (n >= 500) {
            if (n < 900) {
                printf("D");
                n = n - 500;
            } else {
                printf("CM");
                n = n - 900;
            }
        } else if (n >= 100) {
            if (n < 400) {
                printf("C"); 
                n = n - 100;
            } else {
                printf("CD");
                n = n - 400;
            }
        } else if (n >= 50) {
            if (n < 40) {
                printf("L");
                n = n - 50;
            } else {
                printf("XL");
                n = n - 40;
            }
        } else if (n >= 10) {
            if (n < 9) {
                printf("X");
                n = n - 10;
            } else {
                printf("IX");
                n = n - 9;
            }
        } else if (n >= 5) {
            if (n < 9) {
                printf("V");
                n = n - 5;
            } else {
                printf("IX");
                n = n - 9;
            }
        } else {
            if (n < 4) {
                printf("I");
                n = n - 1;
            } else {
                printf("IV");
                n = n - 4;
            }
        }
    }
} 
main() {
    
    int n;
    scanf("%d",&n);
    int *array;

    int i;
    array = (int *)malloc(sizeof(int)*n);
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    for (i = 0; i < n; i++) {
        convert_to_roman(array[i]);
        printf("\n");
    }
}
    
