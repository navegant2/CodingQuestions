#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<deque>
#include<map>
#include<iostream>

using namespace std;

string s;
vector<string> vs;
vector<int> vs1;
map<char,int> first;


struct _double_ll {
    int val;
    struct _double_ll *next;
    struct _double_ll *prev;
};

typedef struct _double_ll double_ll;

double_ll *create_node(int val) {
    double_ll *temp = (double_ll *)malloc(sizeof(double_ll));
    temp->val = val;
    temp->prev = temp->next = NULL;
    return temp;
}
void print_double_ll(double_ll *root) {

    double_ll *temp = root;
    while(temp) {
        printf("%d->", temp->val);
        temp = temp->next;
    }
}
double_ll *rotate_double_ll_by_n(double_ll *root, int n) {

    double_ll *temp = root;
    while(n > 0 && temp != NULL) {
        temp = temp->next;
        n--;
    }
    if (temp == NULL) {
        return NULL;
    }
    // Find new root, break ties from its previous node
    double_ll *new_root = temp;
    new_root->prev->next = NULL;
    new_root->prev = NULL;
   
    // Goto end and attach the first half 
    double_ll *last= NULL; 
    while(temp !=  NULL) {
        last = temp;
        temp = temp->next;
    }
    last->next = root;
    last->next->prev = last;
    return new_root;
}
main() {

    int N;
    scanf("%d", &N);
    int i = 0;

    double_ll *root = create_node(0);
    double_ll *tail = root;

    while (i < N) {
        int val;
        scanf("%d", &val);
        double_ll *temp = create_node(val);
        tail->next = temp;
        temp->prev = tail;
        tail = tail->next;
        i++;
    }
    int rotate_n;
    scanf("%d", &rotate_n);
//    print_double_ll(root->next);
    root = rotate_double_ll_by_n(root->next, rotate_n);
    print_double_ll(root);
}
