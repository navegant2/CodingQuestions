#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct _list {
    int val;
    struct _list *next;
} List;

List *createNode(int val) {
    List *temp = (List *)malloc(sizeof(List));

    temp->val = val;
    temp->next = NULL;
    return temp;
}

void InsertNode(List **root, int val) {

    List *node = createNode(val);

    if (*root == NULL) {
        *root = node;
        return;
    } else {
        node->next = *root;
        *root = node;
        return;
    }
}    
void printList(List *root) {
    
    List *node = root;
    while(node) {
        printf("%d->", node->val);
        node = node->next;
    }
    printf("\n");
}

List *find_middle(List *root) {

    List *slow_ptr = root;
    List *fast_ptr = root;

    while(fast_ptr != NULL && fast_ptr->next != NULL) {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }
    return slow_ptr;
} 
void make_circular(List *root) {

    List *temp = root;
    int i = 0;
    List *save;

    if (temp == NULL) {
        return;
    }
    while(temp->next) {
        temp = temp->next;
        i++;
        if (i == 5) {
            save = temp;
        }
    }
    temp->next = save;
    return;
}
int is_circular(List *root) {
    
    List *slow_ptr = root;
    List *fast_ptr = root;

    while(fast_ptr != NULL && fast_ptr->next != NULL) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;

        if (slow_ptr == fast_ptr) {
            return 1;
        }
    }
    return 0;
}
         
main() {

    int N;
    scanf("%d",&N);
    List *root = NULL;
    int i;

    for (i = 0; i < N; i++) {
        InsertNode(&root, i+1);
    }
    printList(root);
    make_circular(root);

    printf("Is circular:%d\n", is_circular(root));

//    List *node = find_middle(root);
//    printf("%d\n", node->val);
}
