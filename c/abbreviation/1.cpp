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

using namespace std;

string s;
vector<string> vs;
vector<int> vs1;
map<char,int> first;

char to_upper(int ch) {
    if (ch >= 'a' && ch <= 'z') {
        return ch - 'a' + 'A';
    }
    return ch;
}
bool is_abbreviation_possible(string a, string b, int a_start, int a_end, int b_start, int b_end) {
    if (b_start == b_end) {
        if (a_start != a_end && all_lower(a, a_start, a_end) {
            return true;
        } else {
            return false;
        }
    } else if (a_start >= a_end || b_start >= b_end) {
        return false;
    }
// cout << "a_start:" << a_start << " a_end:" << a_end << " b_start:" << b_start << " b_end:" << b_end << endl;
    bool equal_result = false;
    if (to_upper(a[a_start]) == b[b_start]) {
        equal_result = is_abbreviation_possible(a, b, a_start+1, a_end, b_start+1, b_end);
    } 
    bool not_equal_result = is_abbreviation_possible(a, b, 
                                              a_start+1, a_end, b_start, b_end);
    return equal_result || not_equal_result;
}
// Complete the abbreviation function below.
string abbreviation(string a, string b) {
    
    if (is_abbreviation_possible(a, b, 0, a.size(), 0, b.size())) {
        return "YES";
    } else {
        return "NO";
    }
}

main() {

    string a;
    string b;
    cin >> a;
    cin >> b;
    cout << abbreviation(a, b) << endl;


}
