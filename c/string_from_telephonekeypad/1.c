#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct _num_alpha_map {
    int size;
    char alphabets[4];
} num_alpha_map;

num_alpha_map num_to_alphabet[10] = { {0, { }},
                                      {0, { }},
                                      {3, {'a', 'b', 'c'}}, // 2 => abc
                                      {3, {'d', 'e', 'f'}}, // 3 => def
                                      {3, {'g', 'h', 'i'}}, // 4 => ghi 
                                      {3, {'j', 'k', 'l'}}, // 5 => jkl 
                                      {3, {'m', 'n', 'o'}}, // 6 => mno 
                                      {4, {'p', 'q', 'r' , 's' }}, // 7 => pqrs
                                      {3, {'t', 'u', 'v'}}, // 8 => tuv 
                                      {4, {'w', 'x', 'y', 'z' }}, // 9 => wxyz 
                                };

int to_number(char c) {
    return c - '0';
}
void convert_num_to_list_of_strings(char *string, int index, int size) {
   
    int i = 0;
    int j = 0;

    if (index == size) {
        printf("%s\n", string);
        return;
    }

    for (i = index; i < size; i++) {
        char temp_char = string[i];
        int temp = to_number(string[i]);
        int num_alphabets = num_to_alphabet[temp].size;
        for (j = 0; j < num_alphabets; j++) {
            string[i] = num_to_alphabet[temp].alphabets[j]; 
            convert_num_to_list_of_strings(string, index+1, size);  
            string[i] = temp_char; 
        }
    }
}

main() {
        char string[100];

        scanf("%s", string);
        
        convert_num_to_list_of_strings(string, 0, strlen(string));

}

    
