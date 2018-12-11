#include<stdio.h>

struct tree {
    int value;
    struct tree *left;
    struct tree *right;
};

#if 0
int FindNthElement(Node *node, int &n) 
{ 
    if (node->Left && n > 0) { 
        k = FindNthElement(node->left, n); 
        if (n == 0) return k; 
    } 
    if (n == 0) 
        return node->value; 
    else if (n > 0 && node->right) { 
        k = FindNthElement(node->right, n); 
        if (n == 0) return k; 
        else return -1; 
    } 
}
#endif

int traverse_tree(struct tree *T, int n) {

    if (n == 0) {
            return T->value;
    }
    if(T->left) return traverse_tree(T->left, n-1);
    if(T->right) return traverse_tree(T->right, n-1);
    
}

int inorder_nth_element_in_tree(int n, struct tree *T) {
            
    return traverse_tree(T, n); 

}
main() {

    struct tree *T = NULL;
    


    nth_elem = inorder_nth_element_in_tree(n, T);
    printf("%d\n", nth_elem);
}
