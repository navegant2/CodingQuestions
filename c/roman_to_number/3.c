#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int value_of(char c) {
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
                printf("---------------ERROR---------------\n");
                exit(1);
                break;
    }
}
int get_number_from_roman(char *roman) {
    int len = strlen(roman);
    int i = 0;
    int number = 0;

    for(i = 0; i < len; i++) {
        if (i+1 < len && value_of(roman[i+1]) > value_of(roman[i])) {
            number = value_of(roman[i+1]) - value_of(roman[i]) + number;
            i++;
        } else {
            number = number + value_of(roman[i]);
        }
    }
    return number;
}
main() {
    char roman[1000];
    scanf("%s", roman);

    int value = get_number_from_roman(roman);
    printf("%d\n", value);
}
