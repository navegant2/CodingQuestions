#include<stdio.h>
#include<string.h>

void swap(char *string, int i, int j) {
    char tmp = string[i];
    string[i] =  string[j];
    string[j] = tmp;
}

void permute_string(char *string, int index, int length) {
   
    int i = 0;
 
    if (index+1 == length) {
        printf("%s\n", string);
        return;
    }
    for (i = index; i < length; i++) {
        swap(string, index, i);
        permute_string(string, index+1, length);
        swap(string, i, index);
    }
}

void permute_comb_string(char *string, char *new_string, int index, int length) {
    int i;

    if (index == length) {
        return;
    }

    for (i = 0; i < length; i++) {
        new_string[index++] = string[i];
        printf("%s\n", new_string);
        permute_comb_string(string, new_string, i+1, length);
        new_string[index--] = '\0';
    } 
}
main() {
    char string[100];
    char new_string[100];
    int length;
    int i;
    
    scanf("%s", string);
    length = strlen(string);
    memset(new_string, 0, sizeof(new_string));

    printf("-------------------------\n");

    permute_comb_string(string, new_string, 0, length);

}
    

