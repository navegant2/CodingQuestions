#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>

int findMaxLength(int* nums, int numsSize) {
    int i;
    int j;
    int max_len = 0;
    int *alt_nums = (int *)malloc(sizeof(int)*numsSize);
    int counter = 0;

    for (i = 0; i < numsSize; i++) {
        if (nums[0] == 1) {
            counter += 1;
        } else {
            counter += -1;
        }
        alt_nums[i] = counter;
    }

    int max_num = INT_MIN;

    for (i = 0; i < numsSize; i++) {
        for (j = i; j < numsSize; j++) {
            if (alt_nums[j] - alt_nums[i] + 1 == 0) {
                if (max_num < j - i + 1) { 
                    max_num = j - i +1;
                }
            }
        }
    }
    return max_num;
    
}

main() {

    int size;
    scanf("%d", &size);
    int i;
    int *nums;
    nums = (int *)malloc(sizeof(int)*size);
    for (i = 0; i < size; i++) {
        scanf("%d", &nums[i]);
    }
    int max_len = findMaxLength(nums, size);
    printf("%d\n", max_len);

}
