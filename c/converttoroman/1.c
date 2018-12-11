#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int numericals[7]={1, 5, 10, 50, 100, 500, 1000};
char romans[7]={'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int size = 7;

void convert_to_roman(int n, int index) {

    if (n <= 0) {
        return;
    }
    if (n >= numericals[index]) {
        printf("%c",romans[index]);
        n = n - numericals[index];
        convert_to_roman(n, index);
    } else if (n >= numericals[index-1]) {
        convert_to_roman(n, index-1);
    } else {
        if (n < numericals[index-1] - numericals[index-2]) {
            convert_to_roman(n, index - 1);
        } else {
            printf("%c%c",romans[index-2], romans[index-1]);
            convert_to_roman(numericals[index-1]-n, index - 1);
        }
    }
    return;
} 
main() {
    
    int n;
    scanf("%d",&n);
    int *array;

    int i;
    array = (int *)malloc(sizeof(int)*n);
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    for (i = 0; i < n; i++) {
        convert_to_roman(array[i], size-1);
        printf("\n");
    }
}
    
