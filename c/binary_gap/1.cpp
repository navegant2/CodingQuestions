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


int get_max_binary_gap_count(int N) {

    int max_count = 0;
    int prev = -1;
    int idx = 0;
    
    while(N) {  
        int value = N & 0x1;
//        cout << N << endl;
//        cout << value << endl;
        if (value == 1) {
            if (prev != -1) {
                max_count = max(max_count, idx-prev-1);
            }
            prev = idx;
        }
        idx++;
        N = N >> 1;
    }
    return max_count;
}

main() {
    int N;
    cin >> N;
    
    cout << get_max_binary_gap_count(N) << endl;


}
