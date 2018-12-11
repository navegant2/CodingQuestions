#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int get_index_for_same_letter_from_back(char *s, char c, int start, int end) {

    int i = 0;
    for (i = end; i >= start; i--) { 
        if (s[i] == c) {
            return i;
        }
    }
}
int check_if_palendrome(char *s, int start, int end) {

    int i;
    int j;

    for (i = start,j = end; i <= j; i++, j--) {
        if (s[i] != s[j]) {
            return 0;
        }
    }
    return 1;
}
             

char* longestPalindrome(char* s) {
    int len = strlen(s);
    char *p = (char *)malloc(sizeof(char)*len);
    int start = -1, end = -1, palendrome_len = 0;
    int max_palendrome_len = 0;
    int is_palendrome;

    int i;

    for (i = 0; i < len; i++) {
        int get_index = get_index_for_same_letter_from_back(s, s[i], i, len-1);
        palendrome_len = get_index - i + 1;
        if (palendrome_len > max_palendrome_len) {
            is_palendrome = check_if_palendrome(s, i, get_index);
            if (is_palendrome) {
                max_palendrome_len = palendrome_len;
                start = i;
                end = get_index;
            }
        }
    }
    if (start != -1 && end != -1 && max_palendrome_len != 0) { 
        strncpy(p, &s[start], max_palendrome_len);
    }
    return p;
}

main() {
    char s[1000];
    scanf("%s", s);

    char *p = longestPalindrome(s);
    printf("%s\n", p);
}
