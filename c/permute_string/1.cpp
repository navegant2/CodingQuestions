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
    char temp = a;
    a = b;
    b = temp;
}

void permuteHelper(string s, int offset, int end) {
    
    if (offset == end) {
        cout << s << endl;
        return;
    }
    for (int i = offset; i < end; i++) {
        swap(s[i], s[offset]);
        permuteHelper(s, offset+1, end);
        swap(s[i], s[offset]);
    }
}


void permute(string s) {
    permuteHelper(s, 0, s.size());
}

main() {

    string s;
    cin >> s;

    permute(s);

}
