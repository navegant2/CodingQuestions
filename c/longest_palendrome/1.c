#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int longest_palendrome(char *string) {
    int i;
    int size = strlen(string);

    for (i = 0; i < size; i++) {
        if (string[i] != string[size-i-1]) {
            return 0;
        }
    }
    return 1;
}
    

main() {

    char string[100];
    scanf("%s", string);

    longest_palendrome(string);
}

