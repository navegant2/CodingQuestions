#include<stdio.h>
#include<stdlib.h>

typedef struct _node {
    int elem;
    struct _node *next;
} Node;

void print_ll(Node *root) {
    Node *lastNode = root;
    while (lastNode != NULL) {
        printf("%d->",lastNode->elem);
        lastNode = lastNode->next;
    }
    printf("\n");
}
Node *reverse_linked_list(Node *root) {
   
    if (root == NULL) {
        return NULL;
    } 
    if (root->next == NULL) {
        return root;
    }
    Node *t1 = root;
    Node *t2 = root->next;
    Node *prev = NULL;
    Node *temp = NULL;

    while(t1 != NULL && t2 != NULL) {
        temp = t2->next;
        t2->next = t1;
        t1->next = prev;
        
        // new t1, t2, prev
        prev = t2;
        t1 = temp;
        if (temp != NULL) {
            t2 = temp->next;
        }
    }
    if (t1 != NULL) {
        t1->next = prev;
        prev = t1;
    } 
    return prev; 
}

Node *findSecondHalf(Node *root) {

    int length = 0;
    Node *temp;
    Node *prev;
    Node *secondHalf;
    int i = 0;

    temp = root;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    if (length %2 == 1) {
        length++;
    }
    length = length/2;
    temp = root;
    while(length > 0) {
        prev = temp;
        temp = temp->next;
        length--;
    }
    secondHalf =  temp;
    prev->next = NULL;
    return secondHalf;
}

Node *interleave(Node *root) {

    Node *firstHalf = root;

    print_ll(root);
    Node *secondHalf = findSecondHalf(root);
    print_ll(root);
    print_ll(secondHalf);
    secondHalf = reverse_linked_list(secondHalf);
    print_ll(secondHalf);

    while (firstHalf != NULL && secondHalf != NULL) {
        Node *fTemp = firstHalf->next;
        Node *sTemp = secondHalf->next;
        firstHalf->next = secondHalf;
        secondHalf->next = fTemp;
        firstHalf = fTemp;
        secondHalf = sTemp; 
    }
        
    return root;
}
int main() {

    int size;
    int elem;
    Node *root = NULL;
    Node *lastNode = NULL;
    int i = 0;

    scanf("%d", &size);
    for (i = 0; i < size;i++) {
        Node *temp;
        temp = (Node *)malloc(sizeof(Node));
        scanf("%d", &temp->elem);
        temp->next = NULL;
        if (lastNode == NULL) {
            root = temp;
            lastNode = temp;
        } else {
            lastNode->next = temp;
            lastNode = temp;
        }
    }
    root = interleave(root);
    print_ll(root);
}
