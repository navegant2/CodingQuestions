#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int utility_function(char c, char prev_char) {
    int count;

    if (c == '0' && prev_char >= '3') {
        return -1;
    }
    if (c >= '1' && c <= '9') {
        count = 0;
    }
    if (prev_char >= '1' && prev_char <= '2'  && c >= '0' && c <= '6') {
        count = 1;
    }
    return count;
}

int get_possible_interpretations(char *string) {

    int len = strlen(string);
    int i = 0;
    int count = 0;

    if (string[0] == '0') {
        return 0;
    }
    if (len == 1 && string[0] != '0' ) {
        count = 1;
    }
    count = 1;
    for (i = 1; i < len; i++) {
        int temp = utility_function(string[i], string[i-1]);
        if (temp == -1) {
            return 0;
        }
        count += temp;
    }
    return count;
} 
main() {
    char string[100];
    scanf("%s", string);
    int count = 0;

    count = get_possible_interpretations(string);
    printf("%d\n", count);
}
