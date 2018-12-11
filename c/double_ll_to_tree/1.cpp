#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<deque>
#include<map>

using namespace std;

string s;
vector<string> vs;
vector<int> vs1;
map<char,int> first;



typedef struct _d_list {
    int val;
    struct _d_list *previous; // left for tree
    struct _d_list *next;  // right for tree

} d_list;
typedef struct _d_list tree;

d_list *make_node(int val) {

    d_list *node = (d_list *)malloc(sizeof(d_list));
    node->val = val;
    node->next = node->previous = NULL;
    return node;
}

d_list *make_double_linked_list(int *array, int len) {

    int i;
    if (len <= 0) {
        return NULL;
    }
    d_list *head= make_node(array[0]);
    d_list *tail = head;
    for (i = 1; i < len; i++) {
        tail->next = make_node(array[i]);
        tail->next->previous = tail;
        tail = tail->next;
    }
    return head;
}

void print_dd_list(d_list *head) {
    d_list *tail = head;
    d_list *prev = NULL;

    while(tail) {
        printf("%d->",tail->val);
        prev = tail;
        tail = tail->next;
    }
    printf("\n");
    while(prev) {
        printf("%d:",prev->val);
        prev = prev->previous;
    }
    printf("\n");
}   

tree *convert_double_linked_list_to_tree_helper(d_list **list, int start, int end) {

    if (*list == NULL || start >= end) {
        return NULL;
    }

    int mid = start + ((end - start) / 2 );
    printf("First: mid:%d, start:%d, end:%d , list:%d\n",mid, start, end, (*list)->val);
    d_list *left_ptr = convert_double_linked_list_to_tree_helper(list,  start, mid);
    d_list *curr = (*list);
    curr->previous = left_ptr;
    printf("Second: mid:%d, list:%d, curr:%d\n",mid, (*list)->val, curr->val);
    (*list) = (*list)->next;
    curr->next = convert_double_linked_list_to_tree_helper(list,  mid + 1, end);
    printf("Final Node: curr:%d, left:%d, right:%d\n", curr->val, curr->previous?curr->previous->val:-1, curr->next?curr->next->val:-1);
    return curr;

}
tree *convert_double_linked_list_to_tree(d_list **list, int len) {

    return convert_double_linked_list_to_tree_helper(list, 0, len);
}
void print_tree_levelorder(d_list *root) {

    std::queue<d_list*> queue;
    printf("\n printing tree \n");

    if (root == NULL) {
        return;
    }
    queue.push(root);
    while(!queue.empty()) {
        d_list *curr = queue.front();
        queue.pop();

        printf("%d ", curr->val);
        if (curr->previous) {
            queue.push(curr->previous);
        }
        if (curr->next) {
            queue.push(curr->next);
        }
    }
    printf("\n");
}
 
main() {

    int *array;
    int N;

    scanf("%d", &N);
    int i;
    array = (int *)malloc(sizeof(int)*N);
    for (i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }

    d_list *list = make_double_linked_list(array, N); 
    print_dd_list(list);
    tree *root = convert_double_linked_list_to_tree(&list, N);
    print_tree_levelorder(root);
    printf("\n");
}
