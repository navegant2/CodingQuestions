#include<stdio.h>
#include<stdlib.h>
#include<stack>
using std::stack;

typedef struct _tree {
    int data;
    struct _tree *left;
    struct _tree *right;
    struct _tree *sibling;
} Tree;


Tree *createNode(int data) {
    Tree *node = (Tree *)malloc(sizeof(Tree));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void print_tree(Tree *root) {
    if (root != NULL) {
        print_tree(root->left);
        printf("%d ", root->data);
        print_tree(root->right);
    }
}
void print_siblings(Tree *root) {
    if (root != NULL) {
        print_siblings(root->left);
        printf("%d->%d ",root->data,root->sibling?root->sibling->data:-1);
        print_siblings(root->right);
    }
}
void create_siblings_pointers(Tree *root, Tree *parent) {

    if (parent == NULL) {
        root->sibling = NULL;
        if(root->left) {
            create_siblings_pointers(root->left, root);
        }
        if(root->right) {
            create_siblings_pointers(root->right, root);
        }
    } else {
        if(parent->left) {
            parent->left->sibling = parent->right;
        }
        if (parent->right) {
            parent->right->sibling = parent->left;
        }
        if(root->left) {
            create_siblings_pointers(root->left, root);
        }
        if(root->right) {
            create_siblings_pointers(root->right, root);
        }
    }
}
Tree *insert(Tree *root, int data) {
   
    if (root == NULL) {
        return createNode(data);
    } 
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
} 

Tree *insert_into_tree(int *array, int n) {
    int i;
    Tree *root;

    if (n >= 1) {
        root = createNode(array[0]);
    }
    for (i = 1; i < n; i++) {
        root = insert(root, array[i]);
    }
    return root;
}

main() {

    Tree *root;
    int n;
    int i;
    int *array;
    scanf("%d",&n);

    array = (int *)malloc(sizeof(int)*n);
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    root = insert_into_tree(array, n);
    print_tree(root);
    printf("\n");
    create_siblings_pointers(root, NULL);

    print_siblings(root);
    printf("\n");

}

     
