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

void swap(char &a, char &b) {
    char tmp = a;
    a = b;
    b = tmp;
}
string reverse_every_k(string s, int k) {
    int num_sets = s.size()/k;

    for(int i = 0; i <= num_sets; i+=2) {
        int start = i * k;
        int end = (i+1) * k - 1;
        if (end > s.size() - 1) {
            end = s.size()-1;
        }
        while (start < end && start < s.size() && end < s.size()) {
            swap(s[start++],s[end--]); 
        }
    }
    return s;
}
main() {

    string s;
    cin >> s;
    int k;
    cin >> k;

    string result = reverse_every_k(s, k);
    cout << result << endl;
}
