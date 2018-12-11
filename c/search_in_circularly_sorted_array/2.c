#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct _list {
    int value;
    struct _list *next;
};

typedef struct _list list;

list *create_node(int value) {

    list *node = (list *)malloc(sizeof(list));
    node->value = value;
    node->next = NULL;
    return node;

}

list *make_circular_list(int *array, int N) {

    if (N <= 0 ) {
        return NULL;
    }
    list *head = create_node(array[0]);
    list *tail = head;
    int i;

    for (i = 1; i < N; i++) {
        tail->next = create_node(array[i]);
        tail = tail->next;
    }
    tail->next = head;
    return head;
}
void print_circular_list(list *head) {

    list *tail = head;

    do {
        printf("%d->", tail->value);
        tail = tail->next;
    } while (tail != head);
       
    printf("\n");
} 

int search_circular_list(list *head, int value) {

             

main() {

    int N;
    int *array1;
    int i;

    scanf("%d", &N);
    array1 = (int *)malloc(sizeof(int)*N);
    for(i = 0; i < N; i++) {
        scanf("%d", &array1[i]);
    }

    list *head = make_circular_list(array1, N);
    print_circular_list(head);
    int value;
    scanf("%d",&value);
    int result = search_circular_list(head, value);
    printf("%s", result==1?"found":"not-found");

}
