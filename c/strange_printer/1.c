#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int strangePrinter_count(char *s, int l_index, int r_index) {

    char my_char = s[l_index];
    int i;
    int new_l_index = 0, new_r_index = 0, count = 0;

    for (i = l_index; i <= r_index; i++) {
        if (s[i] != my_char) {
            if (new_l_index == 0) {
                new_l_index = i;
            } 
        } else {
            if (new_l_index != 0) {
                new_r_index = i-1;
                count += strangePrinter_count(s, new_l_index, new_r_index);
                new_l_index = new_r_index = 0;
            }
        }
    }
    if (new_l_index != 0) {
        new_r_index = r_index;
        count += strangePrinter_count(s, new_l_index, new_r_index);
    }
    return 1 + count;
}

int strangePrinter(char* s) {

    int len = strlen(s);
    return strangePrinter_count(s, 0, len-1);
    
}
main() {
    char s[101];
    scanf("%s", s);

    int output = strangePrinter(s);
    printf("%d\n", output);
}


    
