#include<stdio.h>
#include<string.h>

int myAtoi(char* str) {

    int i;
    int len;
    int isNegative = 0;

    if (str == NULL) {
        return 0;
    }
    len = strlen(str);
    if (len == 0) {
        return 0;
    }
    int start = 0;
    while(start < len && str[start] == ' ') {
        start++;
    } 
    if (str[start] == '-') {
        if (len == 1) {
            return 0;
        }
        isNegative = 1;
        start++;
    } else if (str[start] == '+') {
        if (len == 1) {
            return 0;
        }
        start++;
    }
    for (i = start; i < len; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    
    long number = 0;
    for (i = start; i < len; i++) {
        number = number * 10 + (str[i]-'0');
    } 
    if (isNegative) {
        number = -1 * number;
    }
    return (int )number; 
 
}

main() {

    char str[100];
    scanf("%s", str);

    int number = myAtoi(str);
    printf("%d\n", number);
}
