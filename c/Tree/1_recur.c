#include<stdio.h>
#include<stdlib.h>

typedef struct _tree {
    int element;
    struct _tree *left;
    struct _tree *right;
    struct _tree *parent;
} Tree;

int max (int l, int r) {
    return (l>r)?l:r;
}
Tree *new_node(int element) {
    Tree *temp = (Tree *)malloc(sizeof(Tree));
    temp->element = element;
    temp->parent = temp->left = temp->right = NULL;
}
Tree *get_minimum(Tree *root) {
    if (root->left) {
        return get_minimum(root->left);
    }
    return root;
}
Tree *get_maximum(Tree *root) {
    if (root->right) {
        return get_maximum(root->right);
    }
    return root;
}

int get_height(Tree *root) {
    
    if (root == NULL) {
        return 0;
    }
    int left_height = get_height(root->left);
    int right_height = get_height(root->right);
    return 1 + max(left_height, right_height); 
}

Tree *get_successor(Tree *root) {

    Tree *parent;
    if (root->right) {
        return get_minimum(root->right);
    } else {
        parent = root->parent;
        while (parent && parent->right == root) {
            root = parent;
            parent = root->parent;
        }
    }
    return parent;
}
Tree *get_predecessor(Tree *root) {

    Tree *parent;
    if (root->left) {
        return get_maximum(root->left);
    } else {
        parent = root->parent;
        while (parent && parent->left == root) {
            root = parent;
            parent = root->parent;
        }
    }
    return parent;
}

void print_levelorder_util(Tree *root, int height) {
    if (height == 0) {
        printf("%d ", root->element);
        return;
    }
    print_levelorder_util(root->left, height-1);
    print_levelorder_util(root->right, height-1);
}

void print_levelorder(Tree *root) {
    int i;
    int height = get_height(root);

    for (i = 0; i < height; i++) {
        print_levelorder_util(root, i);
    }
}
 
void print_inorder(Tree *root) {
    if (root == NULL) {
        return;
    }
    print_inorder(root->left);
    printf ("%d ", root->element);
    print_inorder(root->right);
}
void print_postorder(Tree *root) {
    if (root == NULL) {
        return;
    }
    print_postorder(root->left);
    print_postorder(root->right);
    printf ("%d ", root->element);
}
void print_preorder(Tree *root) {
    if (root == NULL) {
        return;
    }
    printf ("%d ", root->element);
    print_preorder(root->left);
    print_preorder(root->right);
}

Tree *insert_node(Tree *root, int element) {

    if (root == NULL) {
        Tree *temp = new_node(element);
        return temp;
    }
    if (element < root->element) {
        root->left = insert_node(root->left, element);
        root->left->parent = root;
    } else {
        root->right = insert_node(root->right, element);
        root->right->parent = root;
    }
    return root;
}
Tree *delete_node(Tree *root, int element) {

    Tree *temp;

    if (element < root->element) {
        root->left = delete_node(root->left, element);
    } else if (element > root->element) {
        root->right = delete_node(root->right, element);
    } else { // element to be removed
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        } else if (root->left == NULL) {
            temp = root;
            root = get_minimum(root->right);
            root->parent = temp->parent;
            delete_node(root->right, element);
        } else if (root->right == NULL) {
            temp = root;
            root = get_maximum(root->left);
            root->parent = temp->parent;
            delete_node(root->left, element);
        } else {
            temp = root;
            root = get_minimum(root->right);
            root->parent = temp->parent;
            delete_node(root->right, element);
       } 
    }
    return root;
}

Tree *search_node (Tree *root, int element) {
    if (root == NULL) {
        return NULL;
    }
    if (element < root->element) {
        return search_node(root->left, element);
    } else if (element > root->element) {
        return search_node(root->right, element);
    } else {
        return root;
    }
}

void Build_tree(Tree **root, int *array, int n) {

    int i;
    if (*root == NULL) {
        *root = new_node(array[0]); 
    }
    for (i = 1; i < n; i++) {
        *root = insert_node(*root, array[i]);
    }
}
main() {
    Tree *root;
    int *array;
    int n;
    int i;

    scanf("%d", &n);
    array = (int *)malloc(sizeof(int)*n);
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    Build_tree(&root, array, n);

    printf("in-order:");
    print_inorder(root);
    printf("\n");
    printf("pre-order:");
    print_preorder(root);
    printf("\n");
    printf("post-order:");
    print_postorder(root);
    printf("\n");
    printf("level-order:");
    print_levelorder(root);
    printf("\n");
    
    Tree *s1 = search_node(root, array[1]);
    if (s1 != NULL) {
        printf("found: %d\n", s1->element);
    } 
    s1 = search_node(root, array[5]);
    if (s1 != NULL) {
        printf("found: %d\n", s1->element);
    } 
    s1 = search_node(root, -1);
    if (s1 != NULL) {
        printf("found: %d\n", s1->element);
    } else {
        printf("not-found\n"); 
    }
    s1 = search_node(root, array[2]);
    Tree *s2 = get_successor(s1);
    if (s2 != NULL) {
        printf("successor of %d is : %d\n", array[2], s2->element);
    } else {
        printf("successor of %d not-found\n", array[2]); 
    }
    s1 = search_node(root, array[4]);
    s2 = get_successor(s1);
    if (s2 != NULL) {
        printf("successor of %d is : %d\n", array[4], s2->element);
    } else {
        printf("successor of %d not-found\n", array[4]); 
    }
    s1 = search_node(root, array[1]);
    Tree *p1 = get_predecessor(s1);
    if (p1 != NULL) {
        printf("predessor of %d is : %d\n", array[1], p1->element);
    } else {
        printf("predecessor of %d not-found\n", array[1]); 
    }
    s1 = search_node(root, array[3]);
    p1 = get_predecessor(s1);
    if (p1 != NULL) {
        printf("predessor of %d is : %d\n", array[3], p1->element);
    } else {
        printf("predecessor of %d not-found\n", array[3]); 
    }
    printf("Height of tree is : %d\n", get_height(root));
}
