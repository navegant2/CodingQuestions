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
#include<limits>
#include<algorithm>

using namespace std;

string s;
vector<string> vs;
vector<int> vs1;
map<char,int> first;

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    
    while(curr) {
        if (curr->val == val) {
            struct ListNode* temp;
            if (prev == NULL) {
                head = head->next;
            } else {
                prev->next = curr->next; 
            }
            temp = curr;
            curr = curr->next;
            free(temp);
        } else {
            prev = curr;
            curr = curr->next;
        }
    }  
    return head;
}


main() {


}
