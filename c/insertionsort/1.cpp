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

main() {
    int N;
    cin >> N;
    vector<int> array;

    for (int i = 0; i < N; i++) {
        int temp = 0;
        cin >> temp;
        array.push_back(temp);
    }
    insertion_sort(&arary); 


}
