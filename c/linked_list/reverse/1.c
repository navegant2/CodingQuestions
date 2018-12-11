#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct _node {
    int val;
    struct _node *next;
} Node;

void print_ll(Node *head) {

    while(head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}
Node *createNode(int val) {

    Node *temp = (Node *)malloc(sizeof(Node));
    temp->val = val;
    temp->next = NULL;
    return temp;
}
Node *reverse(Node *head) {

    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node *ptr_1 = head;
    Node *prev = NULL;

    while(ptr_1) {
        Node *temp = ptr_1->next;
        ptr_1->next = prev;
        prev = ptr_1;
        
        ptr_1 = temp;
    }
    return prev;
}

main() {

    int N;
    scanf("%d", &N);
    int i;
    Node *head = NULL;
    int val;

    for (i = 0; i < N; i++) {
        scanf("%d", &val);
        if (head == NULL) {
            head = createNode(val);
        } else {
            Node *node = createNode(val);
            node->next = head;
            head = node;
        }
    }
    print_ll(head);
//    head = reverse(head); 
//    print_ll(head);
}
