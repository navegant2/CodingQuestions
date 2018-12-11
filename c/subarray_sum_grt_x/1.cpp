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


#include <iostream>
#include <vector>
using namespace std;

int get_min_subarray_size_with_sum(vector<int> values, int m) {

    int sum = 0;
    int cnt = 0;
    int left = 0;
    int min_cnt = values.size();
    for (int i = 0; i < values.size(); i++) {
        sum += values[i];
        cnt++;
        while (sum > m) {
            min_cnt = min(min_cnt, cnt);
            sum -= values[left];
            left++;
            cnt--;
        }
    }
    return min_cnt;
}
int main() {
    int T;
    
    cin >> T;
    vector<int> results;
    
    for (int i = 0; i < T; i++) {
        int M, N;
        vector<int> temp;
        cin >> N;
        cin >> M;
        for (int j = 0; j < N; j++) {
            int value;
            cin >> value;
            temp.push_back(value);
        }
        int result = get_min_subarray_size_with_sum(temp, M);
        results.push_back(result);
    }
    for (int i = 0; i < T; i++) {
        cout << results[i] << endl;
    }
    //code
    return 0;
}

