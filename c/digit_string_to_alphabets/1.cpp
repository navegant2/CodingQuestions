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

bool is_valid (string s, int prev_idx, int curr_idx) {

    if ((s[prev_idx] == '0' || s[prev_idx] == '1' ) && (s[curr_idx] <= '6')) {
        return true;
    }
    return false;
}

char get_valid_character(string s, int prev_idx, int curr_idx) {

    int number = (int)(s[prev_idx]-'0')*10 + (int)(s[curr_idx]-'0');
    return 'a' + number;
}
void get_possible_alphabet_strings(string s, string partial_string, int offset, vector<string> *result_ptr) {

    if (offset == s.size()) {
        result_ptr->push_back(partial_string);
        return;
    }
    get_possible_alphabet_strings(s, partial_string + ('a' + s[offset]-'0'), offset+1, result_ptr);
    if (offset > 0 && is_valid(s, offset-1, offset)) {
        char ch = get_valid_character(s, offset-1, offset);
        get_possible_alphabet_strings(s, partial_string + ch, offset+1, result_ptr);
    }  
}
int get_count_possible_alphabet_strings(string s) {
    int count = 1;

    for (int i = 1; i < s.size(); i++) {
        if ((s[i-1] == '1' || s[i-1] == '2') && s[i] <= '6') {
            count++;
        }
    }
    return count;
}

    
main() {

    string s;
    cin >> s;

    int count = get_count_possible_alphabet_strings(s);
    vector<string> result;
    get_possible_alphabet_strings(s, "", 0, &result);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    cout << "Count:" << count << endl;
}
