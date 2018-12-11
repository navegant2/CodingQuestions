#include<stdio.h>
#include<string.h>

void swap(char *s, char *d) {
    char tmp = *s;
    *s = *d;
    *d = tmp;
}

void permutations(char *string, int j, int n) {
    int i = 0;

    if (j == n) {
        printf("%s\n", string);
        return;
    } else {
        for (i = j; i < n; i++) {
            swap(&string[j], &string[i]);
            permutations(string, j+1, n);
            swap(&string[i], &string[j]);
        }
    }
}

main() {

    char string[200];

    scanf("%s", string);
    permutations(string, 0, strlen(string));

}
