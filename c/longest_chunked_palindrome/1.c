#include<stdio.h>
#include<string.h>

int string_matches(char *string, int start, int end, int len) {

    int i;    
    for (i = 0; i < len; i++) {
        if (string[start+i] != string[end-len+i+1]) {
            return 0;
        }
    }
    return 1;
}
int get_longest_chunked_palendrome(char *string) {

    int i = 0;
    int count = 1;
    int start = 0; int end = strlen(string) - 1; 
    int len = (end - start);

    if (string == NULL) {
        return 0;
    } else if (end == start) {
        return 1;
    }
    while(len/2 > 1) {
        for (i = 1; i < len/2; i++) {
            printf("Coming with start:%d, end:%d, i:%d\n", start, end, i);
            if (string_matches(string, start, end, i)) {
                printf("match: start:%d, end: %d, len = %d\n", start, end, i);
                start = start + i;
                end = end - i; 
                len = len - 2*i;
                i = 0;
                printf("After match: start:%d, end: %d, len = %d\n", start, end, len);
                count += 2;
                break;
            }
        }
    }
    return count;
}
main() {

    char string[1000];
    scanf("%s", string);
    int result = get_longest_chunked_palendrome(string);
    printf("Result: %d\n", result);
}
