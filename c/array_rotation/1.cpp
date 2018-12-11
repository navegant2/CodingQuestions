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

void rotate_array(vector<int> &array, int k) {

    if (k == array.size()) {
        return;
    }
    int saved = array[0];
    int count = 0;
    int curr_idx = 0;
    int size = array.size();
    k = k % size;

    while(count <= size) {
        int next_idx = (curr_idx + k) % size;
        int next_value = array[next_idx];
        array[next_idx] = saved; 
        saved = next_value; 
        curr_idx = next_idx;
        count++;
    }
}

main() {

    int N;
    cin >> N;
    vector<int> array;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        array.push_back(temp);
    }
    int k;
    cin >> k;

    rotate_array(array, k);

    for (int i = 0; i < N; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}
