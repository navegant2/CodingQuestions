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


 void letterCasePermutationHelper(string s, int index, string partial_string, vector<string> *result_ptr) {
       

cout << partial_string << " index: " << index << endl;
 
        if (partial_string.size() == s.size()) {
cout << "Here " << endl;
            result_ptr->push_back(partial_string);
            return;
        }
        for (int i = index; i < s.size(); i++) {
            if (isdigit(s[i])) {
                partial_string = partial_string + s[i];
                if (i == s.size() - 1) {
                    result_ptr->push_back(partial_string);
                }
            } else {       
                partial_string = partial_string + (char)toupper(s[i]);
                letterCasePermutationHelper(s, i+1, partial_string, result_ptr);
                partial_string.erase( partial_string.end()-1 );
                partial_string = partial_string + s[i];
            }
        }
    
        
    }
    vector<string> letterCasePermutation(string S) {
        vector<string> result;
        result.push_back(S);
        letterCasePermutationHelper(S, 0, "", &result);
        return result;
    }

main() {
    string s;
    cin >> s;
    vector<string> result = letterCasePermutation(s);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " : ";
    }
    cout << endl;
}
