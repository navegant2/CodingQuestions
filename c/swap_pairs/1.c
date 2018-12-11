#include<stdio.h>
#include<string.h>
#include<stdlib.h>


/**
 * Definition for singly-linked list.
 */
struct ListNode {
      int val;
      struct ListNode *next;
};
struct ListNode* swapPairs(struct ListNode* head) {

    struct ListNode *one_ptr = head;
    struct ListNode *prev = NULL;

    if (one_ptr->next) {
        head = one_ptr->next;
    }
    while (one_ptr && one_ptr->next) {
        struct ListNode *two_ptr = one_ptr->next;
        struct ListNode *temp = one_ptr->next->next;

        two_ptr->next = one_ptr;
        one_ptr->next = temp;
        if (prev != NULL) {
            prev->next = two_ptr;
        }

        prev = one_ptr;
        one_ptr = temp;
    }
    return head; 
}

struct ListNode* createNode(int val) {
    struct ListNode* temp = (struct ListNode* )malloc(sizeof(struct ListNode));
    temp->val = val;
    temp->next = NULL;
    return temp;
}

void printNodes(struct ListNode* head) {
    struct ListNode* temp = head;
    while(temp != NULL) {
        printf("%d->",temp->val);
        temp = temp->next;
    }
    printf("\n");
}

main() {

    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);
    head->next->next->next->next->next->next = createNode(7);
    head->next->next->next->next->next->next->next = createNode(8);
    head->next->next->next->next->next->next->next->next = createNode(9);
    printNodes(head);
    head = swapPairs(head);
    printNodes(head);
}
