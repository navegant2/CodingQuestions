#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void search_contacts(int n, char **contacts, char *query_string) {

    int q_i;
    int i;

    for (q_i = 0; q_i < strlen(query_string); q_i++) {
        int count = 0;
        for (i = 0; i < n; i++) {
            if (strncmp(&query_string[0], contacts[i], q_i+1) == 0) {
                printf("%s ", contacts[i]);
            } else {
                count++;
            }
        }
        if (count == n) {
            printf("0\n");
        } else {
            printf("\n");
        }
    }
}
    
main() {

    int N;
    scanf("%d", &N);

    int i;
    for (i = 0; i < N; i++) {
        int n;
        int j;
        scanf("%d", &n);
        char **contacts;
        char query_string[7];

        contacts = (char **)malloc(sizeof(char *)*n);
        for (j = 0; j < n; j++) {
            contacts[j] = (char *)malloc(sizeof(char) * 51);
            scanf("%s", contacts[j]);
        }
        scanf("%s", query_string);
        search_contacts(n, contacts, query_string);
    } 
}
