#include<stdio.h>
#include<string.h>
#include<stdlib.h>


/* 
In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a move consists of either replacing one occurrence of "XL" with "LX", or replacing one occurrence of "RX" with "XR". Given the starting string start and the ending string end, return True if and only if there exists a sequence of moves to transform one string to the other.
*/


void swap(char *ch1, char *ch2) {
    char temp = *ch1;
    *ch1 = *ch2;
    *ch2 = temp;
}
int is_transform_possible(char *start, char *end, int index) {
    int start_len = strlen(start);

    printf("%s:%s\n", start, end);
    if (strcmp(start, end) == 0) {
        printf("TRUE\n"); 
        return 1;
    }

    if (index + 1 < start_len) {
        if (start[index] == 'X' && start[index+1] == 'L') {
            swap(&start[index], &start[index+1]);
            if(is_transform_possible(start, end, index-1)) return;
            swap(&start[index], &start[index+1]);
        } else if (start[index] == 'R' && start[index+1] == 'X') {
            swap(&start[index], &start[index+1]);
            if(is_transform_possible(start, end, index-1)) return;
            swap(&start[index], &start[index+1]);
        }
        if(is_transform_possible(start, end, index+1)) return;
    } 
    return 0;
}
 

main() {

    char s[10000];
//    scanf("%s", s);
    char e[10000];
//   scanf("%s", e);


    strcpy(s, "RXXLRXRXL");
    strcpy(e, "XRLXXRRLX");
    int result = is_transform_possible(s, e, 0);

    printf("%s", (result == 1)?"true":"false");

}
