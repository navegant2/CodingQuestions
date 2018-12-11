#include<stdio.h>
#include<string.h>
#include<math.h>

void util_convert_string_to_alphanumeric(char *string, int bit_index) {
    int i = 0;
    int count = 0; 
    int len = strlen(string);

    for (i = 0; i < len; i++) {
        if ( bit_index & (int)(pow(2, i))) {
            if (count != 0) {
                printf("%d", count); 
                count = 0;
            }
            printf("%c", string[i]);
        } else { 
            count++;
        }
    }
    if (count != 0) {
        printf("%d", count); 
    }
    printf("\n");
}
void convert_string_to_alphanumeric(char *string) {
    int len = strlen(string);
    int i = 0;

    for (i = 0; i < pow(2,len); i++) {
        util_convert_string_to_alphanumeric(string, i);
    }
} 
main() {

    char string[100];
    
    scanf("%s", string);
    convert_string_to_alphanumeric(string);

}
