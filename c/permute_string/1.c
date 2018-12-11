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

main() {
    char string[100];
    int length;
    int i;
    
    scanf("%s", string);
    length = strlen(string);

    printf("-------------------------\n");

    for (i = length; i > 0; i--) {   
        permute_string(string, 0, i);
        string[i-1] = '\0';
    }

}
    

