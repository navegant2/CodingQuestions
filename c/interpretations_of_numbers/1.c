#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct _interpretor {
    char from_string[3];
    int len;
    char to_string[2];
} Interpretor;

Interpretor convertor[27] = { {"", 0, ""},
                              {"1", 1, "a"},
                        {"2", 1, "b"},
                        {"3", 1, "c"},
                        {"4", 1, "d"},
                        {"5", 1, "e"},
                        {"6", 1, "f"},
                        {"7", 1, "g"},
                        {"8", 1, "h"},
                        {"9", 1, "i"},
                        {"10", 2, "j"},
                        {"11", 2, "k"},
                        {"12", 2, "l"},
                        {"13", 2, "m"},
                        {"14", 2, "n"},
                        {"15", 2, "o"},
                        {"16", 2, "p"},
                        {"17", 2, "q"},
                        {"18", 2, "r"},
                        {"19", 2, "s"},
                        {"20", 2, "t"},
                        {"21", 2, "u"},
                        {"22", 2, "v"},
                        {"23", 2, "w"},
                        {"24", 2, "x"},
                        {"25", 2, "y"},
                        {"26", 2, "z"}};
            



char *get_number_interpretation(char *s, int index, int len) {
    int i; 
    for (i = 1; i <= 26; i++) {
        if ( len == convertor[i].len && !(strncmp(convertor[i].from_string,&s[index],len))) {
            // printf("%s", convertor[i].to_string);
            return convertor[i].to_string;
        }
    }
    return convertor[0].to_string;
}

void
print_all_possible_interpretations_of_numbers(char *string, int start, int end, char *new_string, int *index) {

    if (start == end) {
        new_string[*index] = '\0';
        printf("%s\n", new_string);
        return;
    }
    char *temp = get_number_interpretation(string, start, 1);
    copy_strings(new_string, temp, *index, 1);
    *index += 1;
    print_all_possible_interpretations_of_numbers(string, start+1, end, new_string, *index);
    clear_copied_strings(new_string, *index - 1, 1);
    *index -= 1;
    if (start > 0) {
        char *temp = get_number_interpretation(string, start-1, 2);
        if (temp == NULL) {
            return;
        }
        copy_strings(new_string, temp, *index, 1);
        *index += 1;
        print_all_possible_interpretations_of_numbers(string, start+1, new_string, *index);   
    }
} 

main() {

    char string[100];
    scanf("%s", string);
    char new_string[100];
    int index = 0;

    print_all_possible_interpretations_of_numbers(string, 0, strlen(string), new_string, &index);
    printf("\n");
}
