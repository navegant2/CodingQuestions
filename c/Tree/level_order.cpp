#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>

typedef struct _tree {
    int val;
    struct _tree *left;
    struct _tree *right;
    struct _tree *parent;
} Tree;

Tree *createNode(int val) {

    Tree *temp = (Tree *)malloc(sizeof(Tree));
    temp->val = val;
    temp->left = temp->right = temp->parent = NULL;
    return temp;
}

Tree *insert_tree(Tree *root, int val) {

    if (root == NULL) {
        return createNode(val);
    }
    if (val < root->val) {
        root->left = insert_tree(root->left, val);
        root->left->parent = root;
    } else {
        root->right = insert_tree(root->right, val);
        root->right->parent = root;
    }
    return root;
}

void PreOrder(Tree *root) {

    if (root != NULL) {
        printf("%d ", root->val);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
void InOrder(Tree *root) {

    if (root != NULL) {
        InOrder(root->left);
        printf("%d ", root->val);
        InOrder(root->right);
    }
}

void LevelOrder(Tree *root) {

    std::queue<Tree *> queue;
   
    if (root != NULL) {
        queue.push(root);
    }
    while(!queue.empty()) { 
        Tree *temp = queue.front();
        printf("%d ", temp->val);
        if (temp->left) {
            queue.push(temp->left);
        }
        if (temp->right) {
            queue.push(temp->right);
        }
        queue.pop();
    }
}
Tree *find_min(Tree *root) {

    if (root->left) {
        find_min(root->left);
    } else {
        return root;
    }
}
Tree *find_max(Tree *root) {

    if (root->right) {
        find_max(root->right);
    } else {
        return root;
    }
}
Tree *DeleteNode(Tree *root, int val) {

    if (root == NULL) {
        return NULL;
    }
    if (val < root->val) {
        root->left = DeleteNode(root->left, val);
    } else if (val > root->val) {
        root->right = DeleteNode(root->right, val);
    } else { // Equal
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL; 
        } else if (root->right == NULL) {
            Tree *maxLeft = find_max(root->left);
            root->val = maxLeft->val;
            maxLeft->val = val; 
            root->left =  DeleteNode(root->left, val);
        } else if (root->left == NULL) {
            Tree *minRight = find_min(root->right);
            root->val = minRight->val;
            minRight->val = val; 
            root->right = DeleteNode(root->right, val);
        } else { // Both are not null
            Tree *minRight = find_min(root->right);
            root->val = minRight->val;
            minRight->val = val; 
            root->right = DeleteNode(root->right, val);
        }
    } 
    return root;
}

main() {

    Tree *root;

    root = insert_tree(root, 10);
    root = insert_tree(root, 5);
    root = insert_tree(root, 15);
    root = insert_tree(root, 3);
    root = insert_tree(root, 8);
    root = insert_tree(root, 12);
    root = insert_tree(root, 21);
    root = insert_tree(root, 1);
    root = insert_tree(root, 9);

    InOrder(root);
    printf("\n");
    PreOrder(root);
    printf("\n");
    LevelOrder(root);
    printf("\n");
/*
    printf("max: %d\n", find_min(root->left)->val);
    printf("min: %d\n", find_max(root->left)->val); 
    printf("max: %d\n", find_min(root->right)->val);
    printf("min: %d\n", find_max(root->right)->val); 
*/

    DeleteNode(root, 1);
    InOrder(root);
    printf("\n");
    LevelOrder(root);
    printf("\n");
    DeleteNode(root, 8);
    InOrder(root);
    printf("\n");
    LevelOrder(root);
    printf("\n");
    DeleteNode(root, 5);
    InOrder(root);
    printf("\n");
    LevelOrder(root);
    printf("\n");
    DeleteNode(root, 10);
    InOrder(root);
    printf("\n");
    LevelOrder(root);
    printf("\n");

}
    
