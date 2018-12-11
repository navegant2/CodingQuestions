#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<deque>
#include<map>
#include<iostream>
#include<limits>
#include<algorithm>

using namespace std;

string s;
vector<string> vs;
vector<int> vs1;
map<char,int> first;

struct ll {
    int val;
    struct ll *next;
};

ll *newNode(int val) {
    
    ll *temp = (ll *)malloc(sizeof(ll));
    temp->val = val;
    temp->next = NULL;
    return temp;
}
void print_ll(ll *node) {
    while (node) {
        cout << node->val << "->";
        node = node->next;
    }
    cout << endl;
}
ll *pairwise_swap(ll *head) {
    
    if (!head->next) {
        return head;
    }
    ll *new_head = head->next;
    ll *curr = head;
    ll *prev = NULL;
   
    while(curr && curr->next) {
        ll *temp = curr->next;
        ll *new_pair = temp->next;
        temp->next = curr;
        curr->next = new_pair;
        if (prev) {
            prev->next = temp;
        }
        prev = curr;
        curr = new_pair;
    }
    return new_head;

}
         


main() {

    ll head;
    ll *tail = &head;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        tail->next = newNode(temp);
        tail = tail->next;
    }
    print_ll(head.next);
    ll *new_head = pairwise_swap(head.next);
    print_ll(new_head);
}
