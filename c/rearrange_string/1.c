#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void rearrange_string(char *string, char *new_string) {

    int alphabets[26];
    int i;
    int count = 0;
    memset(alphabets, 0, sizeof(int)*26);

    for (i = 0; i < strlen(string); i++) {
        if (string[i] >= 'A' && string[i] <= 'Z') {
            alphabets[string[i]-'A']++;
        } else if (string[i] >= '0' && string[i] <= '9') {
            count = count + (string[i] - '0'); 
        } else {
            exit;
        }
    }
    int index = 0;
    int j;
    for (i = 0; i < 26; i++) {
        for (j = 0; j < alphabets[i]; j++) {
            new_string[index++] = i + 'A';
        }
    }
    if (count > 0) {
        char count_string[100];
        int new_index = 0;
        while (count > 0) {
            count_string[new_index] = '0' + (count % 10);
            count = count/10;
            new_index++;
        }
        new_index--;
        while (new_index >= 0) {
            new_string[index++] = count_string[new_index];
            new_index--;
        }
    }
    new_string[index] = '\0';
}
main() {
    char string[100];
    scanf("%s", string);
    char new_string[100];

    rearrange_string(string, new_string);
    printf("%s\n", new_string);

}  
    
