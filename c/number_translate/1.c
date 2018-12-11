#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int convert_to_number(char a, char b) {

    if ((a == '1' || a == '2' ) && b >= '0' && b <= '6') {
        int number = 0;
        number = 10 * (a - '0');
        number = number + (b - '0');
        return number - 1;
       
    } else {
        printf("---------ERROR -----------\n");
        exit(1);
    }
} 

void convert_to_alphabet_strings(char *string, int n_index, char *alpha_string, int a_index, int len) {
    int i;

    if (n_index == len) {
        printf("%s\n", alpha_string);
        return;
    }
    alpha_string[a_index] = string[n_index]-'1' + 'a';
    convert_to_alphabet_strings(string, n_index+1, alpha_string, a_index+1, len);
    if (n_index < len-1) {
        if (string[n_index+1] >= '0' && string[n_index+1] <= '6' && (string[n_index] == '1' || string[n_index] == '2')) {
            char *temp ;
            temp = (char *)malloc(1000);
            memset(temp, 0, 1000); 
            strncpy(temp, alpha_string, a_index);
            temp[a_index] = convert_to_number(string[n_index], string[n_index+1]) + 'a';
            convert_to_alphabet_strings(string, n_index+2, temp, a_index+1, len);
        }
    }
}
main() {
    char string[1000];
    scanf("%s",string);
    char *alpha_string = (char *)malloc(1000);
    memset(alpha_string, 0, 1000); 

    convert_to_alphabet_strings(string, 0, alpha_string, 0, strlen(string));

}
