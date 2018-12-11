#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _node {
    char data;
    struct _node *next;
} Node;

Node *createNode(char c) {
    Node *temp = (Node *)malloc(sizeof(struct _node));
    temp->data = c;
    temp->next = NULL;
    return temp;
}

Node *make_ll(char *string) {
    int len = strlen(string);
    int i = 0;

    if (len > 0) {
        Node *root = createNode(string[len-1]);
    }
    for (i = len-2; i >= 0; i--) {
        Node *temp = createNode(string[i]);
        temp->next = root;
        root = temp;
    }
    return root;
}
Node *print_ll(Node *root) {
    while(root != NULL) {
        printf("%c", root->data);
        root = root->next;
    }
}
Node *linked_list_interleave(Node *root) {



}
main() {
    char string[100];
    scanf("%s", string);

    Node *root = make_ll(string);
