#include<stdio.h>
#include<string.h>

int my_strstr(char *haysack, char *needle) {
    if (needle == NULL || haysack == NULL) {
        return -1;
    }
    int haysack_len = strlen(haysack);
    int needle_len = strlen(needle);
    int i = 0; int j = 0;

    for (i = 0; i < haysack_len; i++) {
        for (j = 0; j < needle_len; j++) {
            if (haysack[i+j] != needle[j]) {
                break;
            }
        }
        if (j == needle_len) {
            return i;
        }
    }
    return -1;

}
main() {
    char substr[100];
    char mainstr[1000];

    scanf("%s", mainstr);
    scanf("%s", substr);

    int result = my_strstr(mainstr, substr);
    if (result != -1) {
        printf("matches \n");
    } else {
        printf("do not matche\n");
    }
}
