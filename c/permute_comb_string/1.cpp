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
#include<cmath>

using namespace std;

vector<string> vs;
vector<int> vs1;
map<char,int> first;

void print_bit_based_string(string s, unsigned int bit_array) {

    int i = 0;
    if (bit_array == 0) {
        cout << "{}" << endl;
        return;
    }
    while(bit_array) {
        if (bit_array & 0x1) {
            cout << s[i];
        }
        i++; 
        bit_array = bit_array >> 1;
    }
    cout << endl;
}


void print_combinations(string s) {

    int len = s.size();

    for (unsigned int i = 0; i < pow(2, len); i++) {
        print_bit_based_string(s, i);
    }
}

main() {

    string s;
    cin >> s;

    print_combinations(s);
}
