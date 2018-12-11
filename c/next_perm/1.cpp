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

main() {

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }
    int n = 5;
    for (int i = 0; i < n; i++) {
        vector<int> result = get_next_perm(numbers[i]);
        for (int j = 0; j < result.size(); j++) {
            cout << result[j] << " ";
        }
        cout << endl;
    }
}
