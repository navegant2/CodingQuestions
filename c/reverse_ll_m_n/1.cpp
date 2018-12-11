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

typedef struct LNode {
      int val;
      LNode *next;
//      LNode(int x) : val(x), next(NULL) {}
}LNode;


LNode* reverseBetween(LNode* head, int m, int n) {
        LNode *m_1th_node = nullptr; 
        LNode *mNode = head;
        int orig_m = m;
        
        if (head == nullptr || m >= n) {
            return head;
        }
        /* rhead_prev is prev pointer of m */
        while(m-1 > 0) {
            m_1th_node = mNode;
            mNode = mNode->next;
            m--;
        }
        cout << "mNode:" << mNode->val << endl;
       if (m_1th_node) {
             cout << "m_1th_node:" << m_1th_node->val << endl;
        }
        
        /* mNode is mth node */
        LNode *curr = mNode;
        LNode *prev = nullptr;
        int diff = n-orig_m+1;
        while(diff) {   
            LNode *next = curr->next;
            curr->next = prev;
            prev = curr;
        cout << "cur:" << curr->val << " diff:" << diff << endl;
            curr = next;
            diff--;
        }     
        cout << "prev:" << prev->val << endl;
        if (curr) {
            cout << "curr:" << curr->val << endl;
        }
        if (m_1th_node) {
            m_1th_node->next = prev;
        } else {
            head = prev;
        }
        mNode->next = curr;
        return head;
    }

void print_ll(LNode *head) {
    while(head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << endl;
}

main() {

    int N;
    int val;
    cin >> N;
    LNode head;
    LNode *temp = &head;
    
    for (int i = 0; i < N; i++) {
        cin >> val;
        LNode *node = new LNode();
        node->val = val;
        node->next = nullptr;
        temp->next = node;
        temp = temp->next;
    }
    int m, n;
    cin >> m;
    cin >> n;

    temp = reverseBetween(head.next, m, n);
    print_ll(temp);
}
