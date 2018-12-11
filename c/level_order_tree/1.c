#include<stdio.h>
#include<stdlib.h>
#include <math.h>

typedef struct _tree {
    int element;
    struct _tree *left, *right;
} Tree;


Tree *create_node(int element) {
    Tree *temp = (Tree *)malloc(sizeof(Tree));
    temp->element = element;
    temp->left = temp->right = NULL;
    return temp;
}

void insert_node(Tree *root, int element) {

    while(root != NULL) {
        if (root->element < element) {
            if (root->right) {
                root = root->right;
            } else {
                root->right = create_node(element); 
                return;
            }
        } else {
            if (root->left) {
                root = root->left;
            } else {
                root->left = create_node(element); 
                return;
            }
        }
    }
}

void insert_node_level_order(Tree *tree, int *array, int *index, int height, int n) {
    if (*index >= n) {
        return;
    } 
    if (height == 1) {
        tree->left = create_node(array[*index]);
        tree->right = create_node(array[(*index)+1]);
    } else {
        int temp = (*index) +2;
        insert_node_level_order(tree->left, array, &temp, height - 1, n);
        int temp2 = (*index) +4;
        insert_node_level_order(tree->left, array, &temp2, height - 1, n);
    }
}

Tree *Build_tree(int *array, int n) {
  
    Tree *temp; 
    int i;
    int index = 1;

    if (n <= 0 ) {
        return NULL;
    }
    Tree *root = create_node(array[0]);

    for (i = 1; i <= log2(n); i++) {
        insert_node_level_order(root, array, &index, i, n );
    }
    return root;
}

/* Print nodes at a given level */
void printGivenLevel(Tree * root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->element);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}
 
/* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
int height(Tree * node)
{
    if (node==NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        /* use the larger one */
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}
    
/* Function to print level order traversal a tree*/
void printLevelOrder(Tree * root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
        printGivenLevel(root, i);
}
 

main() {

    int n;
    int i;
    int *array;
    scanf("%d", &n);

    array = (int *)malloc(sizeof(int)*n);
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    Tree *root = Build_tree(array, n);
    
    printLevelOrder(root); 
}

    
