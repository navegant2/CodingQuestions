#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int max(int m1, int m2) {
    if (m1 > m2) {
        return m1;
    } else {
        return m2;
    }
} 
int expandAroundCenter(char * s, int left, int right, int length) {
    int L = left, R = right;
    while (L >= 0 && R < length && s[L] == s[R]) {
        L--;
        R++;
    }
    return R - L - 1;
}
char * longestPalindrome(char * s) {
    int len = strlen(s);
    char *p = (char *)malloc(sizeof(char)*len);
    int start = 0, end = 0;
    int i;
    for (i = 0; i < len; i++) {
        int len1 = expandAroundCenter(s, i, i, len);
        int len2 = expandAroundCenter(s, i, i + 1, len);
        int len = max(len1, len2);
        if (len > end - start) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    printf("start:%d, end:%d\n", start, end);
    strncpy(p, &s[start], end - start + 1);
}



main() {
    char s[1000];
    scanf("%s", s);

    char *p = longestPalindrome(s);
    printf("%s\n", p);
}
