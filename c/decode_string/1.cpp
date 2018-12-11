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


int numDecodings(string s) {
         if (!s.size() || s[0] == '0') return 0;
         // r2: decode ways of s[i-2] , r1: decode ways of s[i-1] 
         int r1 = 1, r2 = 1;
    
        for (int i = 1; i < s.size(); i++) {
            // zero voids ways of the last because zero cannot be used separately
    // cout << "Being: i:" << i << " r1:" << r1 << " r2:" << r2 << endl; 
            if (s[i] == '0') r1 = 0;

            // possible two-digit letter, so new r1 is sum of both while new r2 is the old r1
            if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') {
                int temp = r1;
                r1 = r1 + r2;
                r2 = temp;
            }

            // one-digit letter, no new way added
            else {
                r2 = r1;
            }
    cout << "End: i:" << i << " r1:" << r1 << " r2:" << r2 << endl; 
        }

        return r1;
    }

main() {

    string str;
    cin >> str;
    
    cout << numDecodings(str) << endl;

}
