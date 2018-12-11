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

int get_max_value(vector<int> values, int m) {
    
    int sum = 0;
    for (int i = 0; i < m && i < values.size(); i++) {
        sum += values[i];
    }
    int max_value = sum;
    int size = values.size();
    if (m >= size) {
        return max_value;
    }
    cout << endl << "----------------------------------------------";
    cout << endl << "m:" << m <<  " size:" << size << " size+m-1:" << size+m-1 << endl;
    for (int i = m; i < size+m-1; i++) {
        cout << "i-m:" << i-m << " i%size:" << i%size << endl;
        sum -= values[i-m];
        sum += values[i%size];
        max_value = max(sum, max_value);
    }
    return max_value;
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
        int result = get_max_value(temp, M);
        results.push_back(result);
    }
    for (int i = 0; i < T; i++) {
        cout << results[i] << endl;
    }
    //code
    return 0;
}

