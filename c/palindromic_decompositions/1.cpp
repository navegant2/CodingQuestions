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

using namespace std;

string s;
vector<string> vs;
vector<int> vs1;
map<char,int> first;

bool isPalindrome(string str1) {
    int len = str1.size();
    int i, j;
    for (i = 0, j = len - 1; i < j; ++i, --j) {
        if (str1[i] != str1[j]) {
            return false;
        }
    }
    return true;
}
void get_palindromic_substrings_helper(string input, int offset, vector<string> *partial_result, 
                                    vector<vector<string> >*result) {

    if (offset == input.size()) {
        result->push_back(*partial_result);
        return;
    }
    for (int a = offset+1; a <= input.size(); a++) {

        string prefix = input.substr(offset, a - offset);
        if (isPalindrome(prefix)) {
            partial_result->push_back(prefix);
            get_palindromic_substrings_helper(input, a, partial_result, result);
            partial_result->pop_back();
        }
    }
}
void get_palindromic_substrings(string input, vector<vector<string> > *result) {
    get_palindromic_substrings_helper(input, 0, new vector<string>, result);
}

main() {

    string input;
    vector<vector<string> > result;

    cin >> input;
    get_palindromic_substrings(input, &result);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " : ";
        }
        cout << endl;
    }   
}
