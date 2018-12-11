#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int ELEM;
ELEM *stack;
int stack_index;

void push(ELEM a) {
    if (stack_index < 5000 - 1) {
        stack[++stack_index] = a;
    }
}
ELEM pop() {
    ELEM tmp = 0;
    if (stack_index >= 0) {
        tmp = stack[stack_index];
        stack_index--;
    }
    return tmp; 
}

void initialize() {
    stack_index = -1;
    stack = (ELEM *)malloc(sizeof(ELEM)*5000);
}
main() {

    ELEM tmp;
    initialize();
    push(5);
    push(7);
    tmp = pop();
    printf("%d\n", tmp);
    tmp = pop();
    printf("%d\n", tmp);
}
