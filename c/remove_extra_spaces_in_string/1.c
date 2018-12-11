#include<stdio.h>
#include<string.h>

void remove_extra_spaces(char *string) {
    int len = strlen(string);
    int i = 0;
    int index = 0;
    int space_counter = 1;
    int space_index = 0;

    for (i = 0; i < len; i++) {
        if (string[i] == ' '){
            if( space_counter == 0) {
                string[index++] = ' ';
            }
            space_counter++;
        } else {
            space_counter = 0;
            string[index++] = string[i];
        }
    }
    string[index] = '\0';
}
main() {

    char string[1000];
    fgets (string, 1000, stdin);

    remove_extra_spaces(string);
    printf("%s\n", string);

}
