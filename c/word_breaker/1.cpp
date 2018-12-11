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
#include<unordered_set>

using namespace std;

string s;
vector<string> vs;
vector<int> vs1;
map<char,int> first;

 void wordBreakHelper(string s, unordered_set<string> &wordDict, int start_idx,
                         string partial_result, vector<string> *result_ptr, unordered_map<string, vector<string> > &m) {

        vector<string> &result = *result_ptr;

// cout << "start_idx:" << start_idx << " partial_result: " << partial_result << endl;
 
        if (start_idx == s.size()) {
            result.push_back(partial_result);
            return;
        }
        for (int i = start_idx; i < s.size(); i++) {
            string str = s.substr(start_idx, i-start_idx+1);
            if (m[str]) {
                return m[str];
            }
            // cout << "str:" << str << "  start:end:" << start_idx << ":" << i << endl;
            if (wordDict.find(str) != wordDict.cend()) {
                wordBreakHelper(s, wordDict, i+1,  partial_result + str + " ", result_ptr);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        vector<string> result;
        string partial_result;
        for (int i = 0; i < wordDict.size(); i++) {
            dict.insert(wordDict[i]);
        }
        unordered_map<string, vector<string> > m;
        wordBreakHelper(s, dict, 0, partial_result, &result, m);
        return result;
    }

main() {

    string s;
    cin >> s;
    vector<string> wordDict;

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;
        wordDict.push_back(input);
    }
    vector<string> result = wordBreak(s, wordDict);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
}
