#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _list {
    int element;
    struct _list *next;
} List;

void print_ll(List *root) {
    List *temp = root;
    while (temp != NULL) {
        printf("%d->", temp->element);
        temp = temp->next;
    }
    printf("\n");
}
List *reverse_ll(List *root) {
    List *t1;
    List *t2;
    List *prev = NULL;
    List *new_root = NULL;

    if (root == NULL) {
        return NULL;
    } 
    if (root->next == NULL) {
        return root;
    } 
    t1 = root;
    t2 = root->next;

    while (t1 && t2) {
        List *temp;
        temp = t2->next;
        t2->next = t1;
        t1->next = prev;
        prev = t2;
        new_root = t2;

        t1 = temp;
        if (t1) {
            t2 = t1->next;
        } else {
            t2 = NULL;
        }
    }
    if (t1) {
        t1->next = prev;
        new_root = t1;
    }
    return new_root;
}
    
main() {
    int n; int i;
    List *root = NULL;
    List *node;
    List *prev;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        node = (List *)malloc(sizeof(List));
        scanf("%d", &node->element);
        node->next = NULL;
        if (root == NULL) {
            root = node;
        } else {
            prev->next = node;
        }
        prev = node;
    }
    print_ll(root);
    root = reverse_ll(root);
    print_ll(root);
}
