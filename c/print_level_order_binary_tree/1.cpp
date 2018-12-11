#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <queue>

typedef struct _tree {
    int val;
    struct _tree *left;
    struct _tree *right;
} Tree;


Tree *createNode (int val) {
    Tree *node = (Tree *)malloc(sizeof(Tree));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

void print_level_order(Tree *head) {

    std::queue<Tree *> my_queue;

    my_queue.push(head);

    while(!my_queue.empty()) {
        printf("%d : ",my_queue.front()->val);
        Tree *temp = my_queue.front();
        my_queue.pop();
        if (temp->left != NULL) {
            my_queue.push(temp->left);
        }
        if (temp->right != NULL) {
            my_queue.push(temp->right);
        }
    }
}

main() {

    int i;
    int N = 15;
    int Numbers[15] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    Tree *head = createNode(Numbers[0]);
    head->left = createNode(Numbers[2]);
    head->right = createNode(Numbers[1]);

    head->left->left = createNode(Numbers[3]);
    head->left->right = createNode(Numbers[4]);
//    head->right->left = createNode(Numbers[5]);
//    head->right->right = createNode(Numbers[6]);

    head->left->left->left = createNode(Numbers[7]);
    head->left->left->right = createNode(Numbers[8]);
    head->left->right->left = createNode(Numbers[9]);
    head->left->right->right = createNode(Numbers[10]);
 //   head->right->left->left = createNode(Numbers[11]);
//    head->right->left->right = createNode(Numbers[12]);
 //   head->right->right->left = createNode(Numbers[13]);
  //  head->right->right->right = createNode(Numbers[14]);

    print_level_order(head);
}
