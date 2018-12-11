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
#include<unordered_map>

using namespace std;

string s;
vector<string> vs;
vector<int> vs1;
map<char,int> first;

    bool is_palindrome(string& s, int start, int end) {
        cout << "IsPalindrome ? Word: " << s.substr(start, end-start+1) << endl;
        while(start < end) {
            if(s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
        
    }

vector<vector<int> > palindromePairs(vector<string>& words) {
        vector<vector<int> > result;
        unordered_map<string, int> dict;
        for(int i = 0; i < words.size(); i++) {
            dict[words[i]] = i;
        }
        for(int i = 0; i < words.size(); i++) {
            cout << "------------------------------- " << endl;
            cout << "Word: " << words[i] << endl;

            for(int j = 0; j <= words[i].length(); j++) {
                //check the suffix word
                if(is_palindrome(words[i], j, words[i].size() - 1)) {
                  //  the suffix word can be null to all the word
                    string suffix = words[i].substr(0, j);
                    cout << "Suffix Word: " << suffix << endl;
                    reverse(suffix.begin(), suffix.end());
                    cout << "Reverse Suffix Word: " << suffix << endl;
                    if(dict.find(suffix) != dict.end() && i != dict[suffix]) {
                        result.push_back({i, dict[suffix]});
                    }
                }
                cout << "##################" << endl;
                //check the prefix word 
                if(j > 0 && is_palindrome(words[i], 0, j - 1)) {
                    string prefix = words[i].substr(j);
                    cout << "Prefix Word: " << prefix << endl;
                    reverse(prefix.begin(), prefix.end());
                    cout << "Reverse Prefix Word: " << prefix << endl;
                    if(dict.find(prefix) != dict.end() && dict[prefix] != i) {
                        result.push_back({dict[prefix], i});
                    }
                }
            }
        }
        return result;
    }
    
main() {

    int N;
    cin >> N;

    vector<string> words;

    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        words.push_back(temp);
    }
    vector<vector<int> > result = palindromePairs(words);
    for (int i = 0; i < result.size(); i++) {
        cout << "[" << result[i][0] << "," << result[i][1] << "] ";
    }
    cout << endl;
}
