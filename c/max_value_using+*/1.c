#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int to_number(char c) {
    return c - '0';
}
int max_value_using_addmul(char *string) {

    int result = to_number(string[0]);
    int i = 0;

    for (i = 1; i < strlen(string); i++) {
        
        if (string[i] == '0' || string[i] == '1' || 
                string[i-1] == '0' || string[i-1] == '1'){
            result = result + to_number(string[i]);
        } else {
            result = result * to_number(string[i]);
        }
    }
    return result;
}

main() {
    char string[100];
    scanf("%s", string);

    int result = max_value_using_addmul(string);
    printf("%d\n", result);
}

