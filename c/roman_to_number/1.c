#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int
get_number(char c) {
// I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000 
    switch(c) {
        case 'I':
                return 1;
        case 'V':
                return 5; 
        case 'X':
                return 10; 
        case 'L':
                return 50; 
        case 'C':
                return 100; 
        case 'D':
                return 500; 
        case 'M':
                return 1000; 
        default:
            exit(0);
    }
}

int get_roman_to_number(char *roman) {

    int i = 0; 
    int temp = 0, temp2 = 0;
    int len = strlen(roman);
    int result = 0;

    for (i = 0; i < len; i++) {
        temp = get_number(roman[i]);
        if ( i+1 < len) {
            temp2 = get_number(roman[i+1]);
            if (temp < temp2) {
                    result += temp2 - temp;
                    i++;
            } else {
                    result += temp;
            }
        } else {
            result += temp;
        }
    }
    return result;
}

main() {

    char roman_string[100];
    scanf("%s", roman_string);

    int number = get_roman_to_number(roman_string);
    printf("%d\n", number);
}
