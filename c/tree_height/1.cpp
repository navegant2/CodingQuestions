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
int max(int l, int r) {
    
    return l > r? l:r;
}
int height_tree(Tree *root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + max(height_tree(root->left), height_tree(root->right));
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
    int h = height_tree(root);
    printf("%d\n", h);

}

     
