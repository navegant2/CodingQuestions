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
#include<map>
#include<set>

using namespace std;

string s;
vector<string> vs;
vector<int> vs1;
map<char,int> first;

string alienOrder(vector<string>& words) {
    map<char, set<char>> suc, pre;
    set<char> chars;
    string s;
    for (string t : words) {
        chars.insert(t.begin(), t.end());
        for (int i=0; i<min(s.size(), t.size()); ++i) {
            char a = s[i], b = t[i];
            if (a != b) {
                suc[a].insert(b);
                pre[b].insert(a);
     //           break;
            }
        }
        s = t;
    }
    set<char> free = chars;
    for (set<char>::iterator p  = free.begin(); p != free.end(); p++) {
        cout << *p << " ";
    }
    cout << endl;
    for (auto p : pre)
        free.erase(p.first);
    for (set<char>::iterator p  = free.begin(); p != free.end(); p++) {
        cout << *p << " ";
    }
    cout << endl;
    string order;
    while (free.size()) {
        char a = *begin(free);
        free.erase(a);
        order += a;
        for (char b : suc[a]) {
            pre[b].erase(a);
            if (pre[b].empty())
                free.insert(b);
        }
    }
    return order.size() == chars.size() ? order : "";
}

main() {

//    vector<string> dict = { "wrt", "wrf", "er","ett", "rftt" };
    vector<string> dict = { "za","zb","ca","cb" };  
    for (int i = 0; i < dict.size(); i++) {
        cout << dict[i] << " ";
    }
    cout << endl;

    cout << alienOrder(dict) << endl;
  
}
