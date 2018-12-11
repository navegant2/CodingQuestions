#include<stdio.h>
#include<stdlib.h>

typedef struct _tree {
    int data;
    struct _tree *left;
    struct _tree *right;
} Tree;


Tree *createNode(int data) {
    Tree *node = (Tree *)malloc(sizeof(Tree));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void print_preorder(Tree *root) {
    
    if (root != NULL) {
        printf("%d ", root->data);
        print_preorder(root->left);
        print_preorder(root->right);
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
    print_preorder(root);

}

     
