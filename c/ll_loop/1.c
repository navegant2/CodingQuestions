#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct _node {
    int val;
    struct _node *next;
} Node;

Node *create_node(int val) {

    Node *temp = (Node *)malloc(sizeof(Node));
    temp->val = val;
    temp->next = next;
    return temp;
}


int check_if_circular(Node *head) {

    Node *fast_ptr = head;
    Node *slow_ptr = head;

    while(slow_ptr != NULL && fast_ptr != slow_ptr) {
    
        slow_ptr = slow_ptr->next;
        if (fast_ptr && fast_ptr->next) {
            fast_ptr = fast_ptr->next->next;
        } else {
            fast_ptr = NULL;
        }
    }
    if (slow_ptr != NULL && fast_ptr != NULL && slow_ptr == fast_ptr) {
        return 1;
    } else {
        return 0;
    }
}

main() {

    Node head;
    head.val = 1;
    head.next = create_node(2);
    head.next.next = create_node(3);
    head.next.next.next = create_node(4);
    head.next.next.next.next  = create_node(5);
    head.next.next.next.next.next  = create_node(6);

    printf("Is circular:%d\n", check_if_circular(head));
}
