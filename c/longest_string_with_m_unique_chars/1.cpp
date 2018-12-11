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

using namespace std;

string s;
vector<string> vs;
vector<int> vs1;
map<char,int> first;

int get_longest_substring_with_m_unique_chars(string A, int m) {

    int i;
    int last_index_in_substr = 0;
    char curr_char = A[0];
    int longest_substr = numeric_limits<int>::min();
    int distinct_count = 0;
    int over_all_distinct_count = 0;

    for (i = 1; i < A.size(); i++) {
        if (curr_char != A[i]) {
            curr_char = A[i];
            distinct_count++;
            over_all_distinct_count++;
            if (distinct_count >= m ){ 
                longest_substr = max(longest_substr, i - last_index_in_substr);
                last_index_in_substr = i;
                distinct_count--;
            }
        }
    }
    if (m == 0 || over_all_distinct_count +1 < m) {
        return -1;
    } else {
        return max(longest_substr, i - last_index_in_substr);
    }
}
main() {

    string A;
    int m;

    cin >> A;
    cin >> m;
    int result = get_longest_substring_with_m_unique_chars(A, m);
    cout << result << endl;
}
