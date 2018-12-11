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
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *get_middle_ptr(ListNode *head) {
        ListNode *slow_ptr = head;
        ListNode *fast_ptr = head;
        
        while(fast_ptr && fast_ptr->next) {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
        }
        return slow_ptr;
}
ListNode *reverse_linked_list(ListNode *mPtr) {
        
        ListNode *prev = NULL;
        ListNode *curr = mPtr;
        
        while(curr) {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
}
void revert_back_linked_list(ListNode *head, ListNode *reverse_head) {
        ListNode *orig_mid = reverse_linked_list(reverse_head);
/*
cout << "(Reverse) orig mid:" << orig_mid->val << endl;
cout << "(Reverse) orig mid->next:" << orig_mid->next->val << endl;
cout << "(Reverse) orig mid->next->next:" << orig_mid->next->next->val << endl;
cout << "Main head: " << head->val << endl;
cout << "Main head->next: " << head->next->val << endl;
cout << "Main head->next->next: " << head->next->next->val << endl;
*/

}
bool isPalindrome(ListNode* head) {
    
        bool result;
        ListNode *middle_ptr = get_middle_ptr(head);

cout << "Middle-Ptr:" << middle_ptr->val << endl;

        ListNode *reverse_head = reverse_linked_list(middle_ptr);

        ListNode *fwd_ptr = head;
        ListNode *back_ptr = reverse_head;
        while(fwd_ptr && back_ptr) {
            if (fwd_ptr->val != back_ptr->val) {
                result = false;
                revert_back_linked_list(head, reverse_head);
                return result;
            }
            fwd_ptr = fwd_ptr->next;
            back_ptr = back_ptr->next;
        }
        revert_back_linked_list(head, reverse_head);
        return true;
}
void print_ll(ListNode *head) {
    ListNode *temp = head;
    while(temp) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

main() {

    int N;
    cin >> N;
    ListNode head(0);
    ListNode *tail = &head;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        tail->next = new ListNode(temp);
        tail = tail->next;
    }
    print_ll(head.next);
    cout << "result is " << isPalindrome(head.next);
    print_ll(head.next);
    

} 

