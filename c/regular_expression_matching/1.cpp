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


bool isMatchHere(const string &regex, int regex_offset, const string &s, int s_offset) 
{
    cout << "regex is " << regex << " string is " << s <<  "regex_offset is" << regex_offset << " s_offset is" << s_offset << endl;
    if (regex_offset == regex.size()) {
        return true;
    }
    if (regex_offset == regex.size() - 1 && regex[regex_offset] == '$') {
        return s_offset == s.size();
    }
    if (regex.size() - regex_offset >= 2 && regex[regex_offset+1] == '*') {
        for (int i = s_offset+1; i < s.size() && (regex[regex_offset] == '.' || regex[regex_offset] == s[i-1]); ++i) {
            if (isMatchHere(regex, regex_offset+2, s, i)) {
                return true;
            }
        }
        return isMatchHere(regex, regex_offset+2, s, s_offset);
    }
    return s_offset < s.size() && (regex[regex_offset] == '.' || regex[regex_offset] == s[s_offset]) && isMatchHere(regex, regex_offset+1, s, s_offset+1); 
}

bool isMatch(const string &regex, const string &s) {

cout << "regex is " << regex << " string is " << s << endl;

    if (regex.front() == '^') {
        return isMatchHere(regex, 1, s, 0);
    }
    for (int i = 0; i <= s.size(); i++) {
        cout << "regex is " << regex << " string is " << s <<  " i is" << i << endl;
        if (isMatchHere(regex, 0, s, i)) {
            return true;
        }
    }
    return false;
}
    
main() {

    string regex;
    string s;

    cin >> regex;
    cin >> s;

    cout << "Output is " << isMatch(regex, s) << endl; 

}

    
