#include<stdio.h>
#include<string.h>

int is_vowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
         c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ) {
        return 1;
    }
    return 0;
}

int find_hardness(char *string, int start, int end) {
    int vowel_count = 0, constonent = 0, contants_4 = 0;
    int i;

    if (end < start) {
        return 0;
    }
    for (i = start; i <= end; i++) {
        if (is_vowel(string[i])) {
            vowel_count++;
            contants_4 = 0;
        } else {
            contants_4++;
            constonent++;
        }
        if (contants_4 == 4) {
            return 5;
        }
    }
    if (constonent > vowel_count) {
        return 5;
    }
    return 3;
}
int get_difficulty_of_sentence(char *string) {

    int len = strlen(string);
    int word_count = 0;
    int hardness = 0;
    int result = 0;
    int start = 0;
    int i;

    for (i = 0; i < len; i++) {
        if (string[i] == ' ') {
            hardness = find_hardness(string, start, i-1);
            result = result + hardness;
            word_count++;
            start = i+1;
        }
    }
    hardness = find_hardness(string, start, i-1);
    result = result + hardness;
    return result;
}
main() {
    char string[1000];

    fgets(string, 1000, stdin);
    int output = get_difficulty_of_sentence(string);
    printf("%d\n", output);
}
