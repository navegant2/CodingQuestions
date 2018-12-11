#include<stdio.h>
#include<stdlib.h>

typedef struct _node {
    int element;
    struct _node *next;
} Node;

Node *create_node(int element) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->element = element;
    new_node->next = NULL;
    return new_node;
}

Node *add_node(Node *orig, Node *new_node) {
    if (orig == NULL) {
        return new_node;
    } else {
        new_node->next = orig;
        return new_node;
    }
}
void add_node_to_the_end(Node *orig, Node *new_node) {

    if (orig == NULL) {
        return ;
    }
    while(orig->next) {
        orig = orig->next;
    }
    orig->next = new_node;
    return;
}
void print_ll(Node *root) {

    while (root) {
        printf("%d(%p)->", root->element, root);
        root = root->next;
    }
    printf("\n");
}
    
Node *deep_copy_ll(Node *orig) {

    Node *copy = NULL;
    while(orig) {
        if (copy == NULL) {
            copy = create_node(orig->element);
        } else {
            Node *temp = create_node(orig->element);
            add_node_to_the_end(copy, temp);
        }
        orig = orig->next;
    } 
    return copy;
}
         

main() {

    int n;
    Node *orig = NULL;
    Node *copy = NULL;
    int i;

    scanf("%d",&n);
    for(i = 0; i < n; i++) {
        int element;
        scanf("%d",&element);
        Node *temp = create_node(element);
        orig = add_node(orig, temp);
    }
    print_ll(orig);
    copy = deep_copy_ll(orig);
    print_ll(copy);
}

    
