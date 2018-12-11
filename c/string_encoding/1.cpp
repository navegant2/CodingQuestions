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

int overall_count = 0;


char encode(string s, int start, int len) {

    char c;
    int fwd = 0; 
    if (len == 1) {
        fwd = (s[start]-'0') - 1;
    } else if (len == 2) {
        fwd = (s[start]-'0')*10 + (s[start+1]-'0') - 1;
    }
    c = 'a' + fwd;
}
          
    
int get_encodings_helper(string s, int index, string partial_result, vector<string> *result_ptr) {

    overall_count++;
    if (index < 0) {
        result_ptr->push_back(partial_result);
        return 1;
    }
    int count = 0;
    int n_1 = 0;
    int n_2 = 0;

    // cout << "PRE: index:" << index << " count:" << count << endl;
    if (s[index] == '0') {
        if (index > 0 && (s[index-1] == '1' || s [index-1] == '2')) {
            count = get_encodings_helper(s, index-2, encode(s,index-1,2) + partial_result, result_ptr);
        } else {
            return -1;
        }
    } else if (index > 0 && ((s[index-1] == '1') || (s[index-1] == '2' && s[index] > '0' && s[index] <= '6'))) {
       
        n_1 = get_encodings_helper(s, index-1, encode(s,index,1) + partial_result, result_ptr);
        n_2 = get_encodings_helper(s, index-2, encode(s,index-1,2) + partial_result, result_ptr);

        if (n_1 == -1 || n_2 == -1) {
            return -1;
        } 
        count = n_1 + n_2;
    } else {
        n_1 = get_encodings_helper(s,index-1, encode(s,index,1) + partial_result, result_ptr);
        if (n_1 == -1) {
            return -1;
        }
        count = n_1;
    }
    // cout << "POST: index:" << index << " count:" << count << endl;
    return count;
}

int get_encodings(string s, vector<string> *result_ptr) {

    int result = get_encodings_helper(s, s.size()-1, "", result_ptr);
    return result;

}

main() {

    string s;
    cin >> s;

    vector<string> result;
    int count = get_encodings(s, &result);

    // cout << "overall-count:" << overall_count << endl;
    cout << count << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

}
