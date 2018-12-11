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

    if (s == e) {
        return head;
    }
    Node *dummy_head = (Node *)malloc(sizeof(Node));
    dummy_head->next = head;

    int count = 1;
    Node *sublist_head = dummy_head;
    while (count++ < s) {
        sublist_head = sublist_head->next;
    }
    printf("sublist_head:%d\n", sublist_head->val);

    //Reverse sublist
    Node *sublist_iter = sublist_head->next;
    printf("sublist_iter:%d\n", sublist_iter->val);
    while (s++ < e) {
        printf("s:%d, e:%d\n", s, e); 
        printf("sublist_iter->next:%d (temp = sublist_iter->next)\n", sublist_iter->next->val);
        Node *temp = sublist_iter->next;
        printf("sublist_iter->next:%d, temp->next:%d, (sublist_iter->next = temp->next)\n", sublist_iter->next->val, temp->next->val);
        sublist_iter->next = temp->next;
        printf("temp->next:%d, sublist_head->next:%d, (temp->next = sublist_head->next)\n", temp->next->val, sublist_head->next->val);
        temp->next = sublist_head->next;
        printf("sublist_head->next:%d,temp:%d (sublist_head->next = temp)\n", sublist_head->next->val, temp->val);
        sublist_head->next = temp;
        printf("--------------------------------------------------\n\n");
        print_ll(head);
        printf("--------------------------------------------------\n\n");
    }
    return dummy_head->next;
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
