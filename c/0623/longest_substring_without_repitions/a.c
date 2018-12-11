#include<stdio.h>
#include<string.h>

int char_exists_in(char *str, int start, int end, int char1) {
    int i;
    for (i = start; i < end; i++) {
        if(char1 == str[i]) {
            return 1;
        } 
    }
    return 0;
}

int
length_of_max(char *str) {

    int max_len = 0, tmp_len = 0;
    int start, end, tmp_start, tmp_end;
    int i; int j;
    int len = 0;
    len = strlen(str);

    start = 0; end = 0; tmp_start = 0; tmp_end = 0;
    for (j = 0; j < len; j++) {
        tmp_len = 0;
        tmp_start = j;
        for (i = j + 1; i < len; i++) {
           if(!char_exists_in(str, tmp_start, i, str[i])) {
                tmp_end = i;
                tmp_len++;
                if (tmp_len > max_len) {
                    max_len = tmp_len;
                    start = tmp_start;
                    end = tmp_end;
                }
            } else {
                break;
            }
        }
    }
    return max_len;


}
            
main() {

    char str[1024];


    printf("Give the string\n");
    scanf("%s", str);

    printf("String is: %s\n", str);
    length_of_max(str);

}
                

 
     
