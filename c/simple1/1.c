#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void execute_command(int command, int value, int **numbers, int *count) {
    int index = *count;
    
    if (command == 1) {
        if (index%100 == 0) {
            *numbers = (int *)realloc( (int *)*numbers, sizeof(int)*(index + 100));
        }   
        (*numbers)[index] = value;
        *count++;
    } else if (command == 2) {
        *count--;
    } else if (command == 3) {
        int i;
        int max_value = 0;
        for (i = 0; i < index; i++) {
            if (max_value < (*numbers)[i]) {
                max_value = (*numbers)[i];
            }
        }
        printf("%d\n", max_value);
    }
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N = 0;
    int command; 
    int value;
    int max_value;
    int i = 0;
    int *numbers;
    int count = 0;
    
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &command);
        if (command == 1) {
            scanf("%d", &value);
        }
        execute_command(command, value, &numbers, &count);
    }
    
    return 0;
}
