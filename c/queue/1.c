#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int ELEM;
#define MAX 2 
ELEM *queue;
int queue_index;
int dequeue_index;
int total_elements;

void enqueue(ELEM a) {
    if (total_elements < MAX) {
        ++queue_index;
        if (queue_index == MAX) {
            queue_index = 0;
        }
        queue[queue_index] = a;
        total_elements++;
    }
}
ELEM dequeue() {
    ELEM tmp = 0;
    if (total_elements != 0 ) {
        tmp = queue[dequeue_index];
        dequeue_index++;
        if (dequeue_index == MAX) {
            dequeue_index = 0;
        }
        total_elements--;
    }
    return tmp; 
}

void initialize() {
    queue_index = -1;
    dequeue_index = 0;
    total_elements = 0;
    queue = (ELEM *)malloc(sizeof(ELEM)*MAX);
}
main() {

    ELEM tmp;
    initialize();
    enqueue(5);
    enqueue(7);
    tmp = dequeue();
    printf("%d\n", tmp);
    enqueue(3);
    tmp = dequeue();
    printf("%d\n", tmp);
    tmp = dequeue();
    printf("%d\n", tmp);
    enqueue(1);
    tmp = dequeue();
    printf("%d\n", tmp);
}
