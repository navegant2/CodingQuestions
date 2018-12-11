#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int detectCapitalUse(char* word) {

    int len = strlen(word);
   
    if (len <= 1) {
        return 1;
    }
    int small = 0;
    int capital = 0;
    int i = 0;

    for (i = 0; i < len; i++) {
        if (word[i] >= 'a' && word[i] <= 'z') {
            small++;
        } else if (word[i] >= 'A' && word[i] <= 'Z') {
            capital++;
        }
    }
    printf("small:%d, capital:%d\n", small, capital);
    if (small == len || capital == len) {
        return 1;
    }
    if (word[0] >= 'A' && word[0] <= 'Z' && small == len-1) {
        return 1;
    }
    return 0;
}

main() {

    int result;
    char string[1000];
    
    scanf("%s", string);

    if (detectCapitalUse(string)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
}
