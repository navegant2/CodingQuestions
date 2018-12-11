#include<stdio.h>
#include<string.h>

void left_rotate_string_by_k(char *string, int k) {

    int len = strlen(string);
    int i;
    int j;

    for (i = 0; i < k; i++) {
        char temp = string[0];
        for (j = 0; j < len-1; j++) {
            string[j] = string[j+1];
        }
        string[len-1] = temp;
    }

}
main() {
    
    char string[1000];
    scanf("%s", string);
    printf("%lu :%s\n", strlen(string), string);

    left_rotate_string_by_k(string, 6);
    printf("%s\n", string);

}
