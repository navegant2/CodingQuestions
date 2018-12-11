#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int verify_palendrome(char *string) {
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

    int result;
    char string[100];
    scanf("%s", string);

    result = verify_palendrome(string);
    if (result == 1) {
        printf("Its a palendrome\n");
    } else {
        printf("Not a palendrome\n");
    }
}

