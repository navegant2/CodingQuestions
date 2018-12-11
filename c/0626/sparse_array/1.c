#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int get_output_for_string(char *string, char **string_array, int N) {
    int count = 0;
    int i;

    for (i = 0; i < N; i++) {
        if(strcmp(string, string_array[i]) == 0) {
            count++;
        }
    }
    return count;
} 
void get_output() {

    int N;
    char **N_Strings;
    int Q;
    char **Q_Strings;
    int i;
    
    scanf("%d",&N);
    N_Strings = (char **)malloc(sizeof(char *)*N);
    for( i = 0; i < N; i++) {
        N_Strings[i] = (char *)malloc(20);
        scanf("%s", N_Strings[i]);
    }
    scanf("%d",&Q);
    Q_Strings = (char **)malloc(sizeof(char *)*Q);
    for( i = 0; i < Q; i++) {
        Q_Strings[i] = (char *)malloc(20);
        scanf("%s", Q_Strings[i]);
    }
    for (i = 0; i < Q; i++) {
        printf("%d\n", get_output_for_string(Q_Strings[i], N_Strings, N));
    }
}


main() {

    get_output();

}

