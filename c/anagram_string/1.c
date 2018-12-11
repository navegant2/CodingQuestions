#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void set_bit_on(int *index, char c) {
    index[c-'a']++; 
}
void set_alphabet_index(char *string, int *alphabet_index) {

    int i = 0;
    for (i = 0; i < strlen(string); i++) {
        char c = tolower(string[i]);
        set_bit_on(alphabet_index, c);
    }
}

void print_anagrams(char **string, int n) {

    int **alphabet_index;
    int i, j, z;
    alphabet_index = (int **)malloc(sizeof(int *)*n);
    for (i = 0; i < n;i++) {
        alphabet_index[i] = (int *)malloc(sizeof(int)*26);
    }
        

    for (i = 0; i < n; i++) {
        set_alphabet_index(string[i], alphabet_index[i]); 
    }

    for (i = 0; i < n; i++) {
        printf("%s -> ", string[i]);
        for (j = i+1; j < n; j++) {
            int result = 0;
            for (z = 0; z < 26; z++) {
                if ( alphabet_index[i][z] != alphabet_index[j][z]) {
                    result = -1; 
                }
            }
            if (result == 0) {
                printf("%s: ", string[j]);
            }
        }
        printf("\n");
    }
}

main() {

    int n;
    int i = 0;
    char **string;

    scanf("%d", &n);

    string = (char **)malloc(sizeof(char *)*n);
    for (i = 0; i < n; i++) {
        string[i] = (char *)malloc(sizeof(char)*100);
        scanf("%s",string[i]);
    }
    for (i = 0; i < n; i++) {
        printf("%s\n",string[i]);
    }
    printf("-------------------------\n");

    print_anagrams(string, n);


}
