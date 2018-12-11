#include<stdio.h>
#include<stdlib.h>

typedef struct _tree {
    int element;
    struct _tree *left;
    struct _tree *right;
} Tree;

int verify_bst(Tree *t) {

    int result = 0;
    if (t == NULL) {
        return 1;
    }
    if (t->left && t->element < t->left->element) {
        return 0; 
    } 
    if (t->right && t->element > t->right->element ) {
        return 0; 
    }
    if ( verify_bst(t->left) == 1 || verify_bst(t->right) == 1) {
        return 1;
    }
    return 0;
}
    
main() {
    Tree *t;
    int result;

    result = verify_bst(t);
    if (result == 0) {
        printf("Its binary search tree\n");
    } else {
        printf("Its not binary search tree\n");
    }

}
    


