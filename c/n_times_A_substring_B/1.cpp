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

bool check_substring(string A, string B, int start, int *slide_count) {

    int i = 0; 
    int j = start; 
    *slide_count = 1;
    for (i = 0; i < B.size(); i++) {
        if (j == A.size()) {
            j = j % A.size();
            (*slide_count)++;
        }
        if (A[j] == B[i]) {
            j++;
        } else {
            break;
        }
    }
    if (i == B.size()) {
        return true;
    }
    return false;

}
int get_n_times_A_substring_of_B(string A, string B) {

    int z = 0;
    int slide_count = 1;
    bool found;

    for (z = 0; z < A.size(); z++) {
        if (A[z] != B[0]) {
            continue;
        }
        found = check_substring(A, B, z, &slide_count); 
        if (found == true) {
            break;
        }
    }
    return found ? slide_count : -1;
}
    


main() {

    string A, B;
    cin >> A;
    cin >> B;

    int result = get_n_times_A_substring_of_B(A, B);
    cout << result << endl;
}
