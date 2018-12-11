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


Node *convertExpression(string str,int x)
{
    int n = str.length();
    if(n==0)return NULL;
    stack<Node *>S;
    Node * root = newNode(str[0]);
    S.push(root);
    for(int i=1;i<n;i++)
    {
        if(i<n-1 && str[i]=='?')
        {
            Node * node = S.top();
            node->left = newNode(str[i+1]);
            S.push(node->left);
        }
        else if(i<n-1 && str[i]==':')
        {
            S.pop();
            Node * node = S.top();
            node->right = newNode(str[i+1]);
            S.pop();
            S.push(node->right);
        }
    }
    return root;
}

main() {


}
