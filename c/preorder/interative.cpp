#include<stdio.h>
#include<stdlib.h>
#include<stack>
using std::stack;

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
    stack<Tree *> tree_stack;
   
    if (root != NULL) { 
        tree_stack.push(root);
    }

    while(!tree_stack.empty()) {
        Tree *node = tree_stack.top();
        tree_stack.pop();
        printf("%d ", node->data);
        if(node->right) {
            tree_stack.push(node->right);
        }
        if(node->left) {
            tree_stack.push(node->left);
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
    print_preorder(root);

}

     
