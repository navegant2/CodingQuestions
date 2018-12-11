#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void get_power_set(char *string, char *out_string, int start, int index, int size, int comb_len) {

    if (index == size) {
        return;
    }
    int i;
    for (i = start; i <= size-1; i++) {
        out_string[index] = string[i];
        out_string[index+1]='\0';
        if (index == comb_len - 1) {
            printf("%s\n", out_string);
        }
        get_power_set(string, out_string, i+1,  index+1, size, comb_len);
    }
}
main() {
    char string[100];
    char out_string[100];

    scanf("%s", string);
    memset(out_string, 0, 100);
    get_power_set(string, out_string, 0, 0, strlen(string), 3);
}
