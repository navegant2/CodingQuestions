#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char to_alphabet(int num) {
    return '0' + num;
}

char *get_string_of(int num) {

    int temp = num;
    char *string;
    int len = 0;

    while (temp != 0) {
        temp = temp / 10;
        len++;
    }
    string = (char *)malloc(sizeof(char)*len);
    memset(string, 0, sizeof(char)*len);
    temp = num;
    while (len != 0) {
        int remainder = temp % 10;
        temp = temp / 10;
        string[len-1] = to_alphabet(remainder);
        len--;
    }
    return string;
}

void add_counter_to_string(char *string, int *index, int count) {
    char *count_string = get_string_of(count);
    int len = strlen(count_string);
    int i;

    for (i = 0; i < len; i++) {
        string[*index + i] = count_string[i]; 
    }
    *index = *index + len;
}

void string_compression(char *string) {
    int size = strlen(string);
    int i;
    char prev = string[0];
    int count = 1;
    int z = 0;

    for (i = 0; i < size; i++) {
        if (i == 0 || prev != string[i]) {
            if (prev != string[i] ) {
                add_counter_to_string(string, &z, count);
            }
            string[z++] = string[i];
            count = 1;
            prev = string[i];
        } else {
            count++;
        }
    }
    add_counter_to_string(string, &z, count);
    string[z++] = '\0';
    return;
}

main() {
    
    char string[100];
    scanf("%s", string);
    string_compression(string);
    printf("%s\n", string);
}
