#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int isMatch(char *string, char *pattern) {
   int str_len = strlen(string);
   int pattern_len = strlen(pattern);
   int i = 0, j = 0;

    while(i < str_len && j < pattern_len) {

        if(string[i] == pattern[j]) {
            i++;
            j++;
        } else if (pattern[j] == '*') {
            i++;
        } else if (pattern[j] == '.') {
            i++;
            j++;
        } else {
            j++; 
        }
    } 
    while (j < pattern_len) {
        if(pattern[j] == '*') {
            j++;
        } else {
            break;
        }
    }
        
    if (i == str_len) {
        return 1;
    }
    return 0;

} 

main() {

    char string[200], pattern[200];
    scanf("%s", string);
    scanf("%s", pattern);
    int out = isMatch(string, pattern);
    if (out == 0) {
        printf("false\n");
    } else {
        printf("true\n");
    }
}
