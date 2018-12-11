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
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *temp = head;
    int carry_fwd = 0;

    while (l1 && l2) {
        int number = carry_fwd + l1->val + l2->val;
        int remainder = number % 10;
        carry_fwd = number / 10;
        temp->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp->next->val = remainder;
        temp->next->next = NULL;
        temp = temp->next;

        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1) {
        int number = carry_fwd + l1->val;
        int remainder = number % 10;
        carry_fwd = number / 10;
        temp->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp->next->val = remainder;
        temp->next->next = NULL;
        temp = temp->next;
        
        l1 = l1->next;
    }
    while (l2) {
        int number = carry_fwd + l2->val;
        int remainder = number % 10;
        carry_fwd = number / 10;
        temp->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp->next->val = remainder;
        temp->next->next = NULL;
        temp = temp->next;
        
        l2 = l2->next;
    }
    temp = head;
    head = head->next;
    free(temp);

    return head;
}

void fill_num(struct ListNode **list, int num) {
  
    if (num <= 0 ) {
        return;
    }
    while (num) {
        *list = (struct ListNode *)malloc(sizeof(struct ListNode));
        (*list)->val = num % 10;
        (*list)->next = NULL; 
        list = &((*list)->next);
        num = num/10;
    }
    return;
}
void print_ll(struct ListNode *ll) {

    while(ll) {
        printf("%d->",ll->val);
        ll=ll->next;
    }
    printf("\n");
}

main() {

    struct ListNode *l1;
    struct ListNode *l2;

    int num1; int num2;
    scanf("%d", &num1); 
    scanf("%d", &num2); 

    fill_num(&l1, num1);
    fill_num(&l2, num2);
    print_ll(l1);
    print_ll(l2);
    
    struct ListNode *result = addTwoNumbers(l1, l2);    
    print_ll(result);

}
