#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int find_right_index(char *s, int len, int left_index, int *sub_str_len) {
    char letter = s[left_index];
    int right_index = left_index;
    int i, j;
    *sub_str_len = 0;

    // First find the right_index where we see the first letter in the entire string.
    for (i = left_index+1; i < len; i++) {
        if (letter == s[i]) {
            right_index = i;
        }
    }
    
    // Second, extend the right_index to accomodate as long as we can stretch to accomodate the elements
    for (i = left_index; i <= right_index; i++) {
        for (j = i+1; j < len; j++) {
            if (s[i] == s[j] && j > right_index) {
                right_index = j;
            }
        }
    }  
    *sub_str_len = right_index - left_index + 1;
    return right_index;
}

void partition_string(char *s, int *count, int *partitions) {

    int len = strlen(s);
    
    if (len <= 0) {
        *count = 0;
        return;
    } else if (len == 1) {
        *count = 1;
        partitions[0] = 1;
        return;
    }
    int left_index = 0;
    int right_index = -1; 
    int counter = 0;
    int i = 0;
    int sub_str_len = 0;

    while (i < len) {
        left_index = i;
        right_index = find_right_index(s, len, i, &sub_str_len);
        if (left_index <= right_index) {
            partitions[counter] = sub_str_len;
            counter++;
        }
        i = right_index+1;
    }
    *count = counter;
} 
main() {
    char s[500];
    int partitions_cnt;
    int partitions[26];

    scanf("%s", s);
    // printf("%s\n", s);
    partition_string(s, &partitions_cnt, partitions);

    int i;
    for (i = 0; i < partitions_cnt; i++) {
        printf("%d ", partitions[i]);
    }
    printf("\n");
}
