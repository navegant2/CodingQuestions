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

void get_subsets_of_sizek(int n, int k, int offset, vector<int> *partial_result, vector<vector<int> >*result) {

    if (partial_result->size() == k) {
        result->push_back(*partial_result);
        return;
    }
    int remaining = k - partial_result->size();
    for (int i = offset; i < n && remaining <= n - i; i++) {
        partial_result->push_back(i);
        get_subsets_of_sizek(n, k, i+1, partial_result, result);
        partial_result->pop_back();
    }
}

main() {

    int n, k;
    cin >> n;
    cin >> k;

    vector<vector<int> > result;
    get_subsets_of_sizek(n, k, 0, new vector<int> , &result);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " : ";
        }
        cout << endl;
    }   
}

