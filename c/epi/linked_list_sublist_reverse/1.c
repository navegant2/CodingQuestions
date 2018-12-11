#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*

1 -> 2 -> 3 -> 4 ->5 -> 6 -> 7 -> null 
with input of 2, 4
1 -> 4 -> 3 -> 2 -> 5 -> 6 -> 7 -> null

*/


typedef struct _node {
    int val;
    struct _node *next;
} Node;

Node *create_ll_list(int N, int *array) {

    if (N <= 0 ) {
        return NULL;
    }
    Node *head = (Node *)malloc(sizeof(Node));
    head->val = array[0];
    head->next = NULL;
    Node *tail = head;

    int i;
    for (i = 1; i < N; i++) {
        tail->next = (Node *)malloc(sizeof(Node));
        tail->next->val = array[i];
        tail->next->next = NULL;
        tail = tail->next;
    }
    return head;
} 
void print_ll(Node *head) {
    
    while(head) {
        printf("%d ->", head->val);
        head = head->next;
    }
    printf("\n");
    return;
}
    
Node *ll_sublist_reverse(Node *head, int s, int e) {

    Node *dummy = head;
    int count = 1;

    Node *sublist_head = head;
    while (count++ < s - 1) {
        sublist_head = sublist_head->next;
    }
    Node *sublist_iter = sublist_head->next;
    count = s;
    while(count++ < e) {
        Node *temp = sublist_iter->next;
        sublist_iter->next = temp->next;
        temp->next = sublist_head->next;
        sublist_head->next = temp;
        sublist_iter->next = NULL;
        print_ll(head);
    }
    return head;
}

main() {

    int i;
    int N;
    int *array;
    int s, e;

    scanf("%d", &N);

    array = (int *)malloc(sizeof(int)*N);
    for (i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }
    scanf("%d %d", &s, &e);
    
    Node *head = create_ll_list(N, array);
    Node *result = ll_sublist_reverse(head, s, e);
   
    print_ll(result); 
}
