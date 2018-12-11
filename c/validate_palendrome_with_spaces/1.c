#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int is_palendrome_with_spaces(char *string) {

    int len = strlen(string);
    int i = 0;
    int j = len - 1;

    while (i < j) {

        if (string[i] == ' ') {
            i++;
            continue;
        }
        if (string[j] == ' ') {
            j--;
            continue;
        }
        if (string[i] != string[j]) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}   
main() {

    char string[1000];

    fgets(string, 1000, stdin);
    string[strlen(string)-1] = '\0';

    int result = is_palendrome_with_spaces(string);
    if (result == 1) {
        printf("Palendrome\n");
    } else {
        printf("Not palendrome\n");
    }
}
