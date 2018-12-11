#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void swap(char *string, int start, int end) {
    if (end > start) {
        int i;
        while (start < end) {
            char temp = string[start];
            string[start] = string[end];
            string[end] = temp;
            start++; end--;
        }
    }
}

reverse_words(char *string) {
    int len = strlen(string);
    int i;
    int start = 0, end = 0;

    swap(string, 0, len-1);
    for (i = 0; i < len; i++) {
        if (string[i] == ' ') {
            swap(string, start, i-1);
            start = i+1;
        }
    }
    swap(string, start, len-1);
}
main() {
    char string[1000];
   
    fgets(string, 1000, stdin); 
    string[strlen(string)-1] = '\0';
    reverse_words(string);
    printf("%s\n", string);

}
