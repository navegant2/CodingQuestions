#include<stdio.h>
#include<stdlib.h>

void print_sequence(int seed, int iterations) {
    int i = 0;
    int array1[1000];
    int array2[1000];
    int *input_array = array1;
    int *output_array = array2;
    int *temp_array_ptr;
    array1[0] = seed;
    int input_len = 1;
    int output_len = 0;
    int j = 0; int index = 0;
    int count;
    int output_index;
    int prev;

    for (i = 0; i < iterations; i++) {
        count = 0;
        output_index = 0;
        prev = -1; 
        for(index = 0; index < input_len; index++) {
            if (prev != input_array[index]) {
                output_array[output_index++] = 1;
                output_array[output_index++] = input_array[index];
                prev = input_array[index];
            } else {
                output_array[output_index-2] += 1;
            }
        }

        output_len = output_index;
        input_len = output_len;
        temp_array_ptr = input_array;
        input_array = output_array;
        output_array = temp_array_ptr;
        for (j = 0; j < input_len; j++) {
            printf("%d ", input_array[j]);
        }
        printf("\n");
    }
}

main() {

    int seed = 0;
    int iterations = 0;
    scanf("%d",&seed);
    scanf("%d",&iterations);

    print_sequence(seed, iterations);

}
