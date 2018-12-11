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

string get_min_window(string s, string t) {
    int start = 0;
    int r_start = -1;
    int r_end = -1;

    unordered_map<char,int> dict;
    for(char c : t) {
        dict[c]++;
    }
    int i = 0;
    int tobe_matched = t.size();



    while ( i < s.size() ) {
        if (dict.find(s[i]) != dict.end() && dict[s[i]] > 0) {
            tobe_matched--;
            dict[s[i]]--;

            while(tobe_matched == 0) {
                if ((r_start == -1 && r_end == -1) || 
                        (i - start < r_end - r_start)) {
                    r_start = start;
                    r_end = i;
                     cout << "r-s:" << r_start << " r-e:" << r_end << endl;
                }
                if (dict.find(s[start]) != dict.end()) {
                    cout << "s[start]:" << s[start] << " start:" << start << endl;
                    ++dict[s[start]];
                    tobe_matched++;
                }
                start++;
            }
        }
        i++;
    }
    return s.substr(r_start, r_end-r_start+1);
}
main() {
    string s;
    string t;
    cin >> s;
    cin >> t;
    string result = get_min_window(s, t);
    cout << result << endl;


}
