#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct _list {
    char ch;
    struct _list *next;
} List;

List *createNode(char ch) {
    List *temp;

    temp = (List *)malloc(sizeof(List));
    temp->ch = ch;
    temp->next = NULL;
    return temp;
}
void make_linked_list(char *s, List **head) {
    int len = strlen(s);
    int i;

    if (len <= 0 ) {
        return;
    }
    *head = createNode(s[0]);
    List *node = *head;
    for (i = 1; i < len; i++) {
        node->next = createNode(s[i]);
        node = node->next;
    }
}

void print_list(List *head) {

    List *node = head;

    while(node) {
        printf("%c->", node->ch);
        node = node->next;
    }
    printf("\n");
}

List *reverse_ll_recursive(List *A, List *B) {

    List *head = NULL;

    if (A != NULL) {
        head = reverse_ll_recursive(A->next, A);
        A->next = B;
    } else {
        return B; 
    }
    return head;
    
}

main() {

    char s[1000];
    scanf("%s", s);
    List *head = NULL;

    make_linked_list(s, &head);
    print_list(head);

    head = reverse_ll_recursive(head, NULL);
    print_list(head);
}
