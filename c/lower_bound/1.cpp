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

struct myObj {
    int index;
    int val;
};

int get_val(vector<myObj> &input, int index) {

    int start = 0;
    int end = input.size()-1;

    while (start <= end) {

    
        if (start == end && index <= input[start].index) {
            return input[start].val;
        }

        int mid = start + (end-start)/2;
        cout << "s:" << start << " e:" << end << " m:" << mid << " val-mid:" << input[mid].index << endl;
        if (input[mid].index == index) {
            return input[mid].val;
        } else if (index > input[mid].index) {
            start = mid+1;
        } else {    // input[mid].index <= index
            end = mid; 
        }
    }
    return -1;
}

main() {

    // 0:2 1:2 2:2 3:2 4:3 5:3 6:3 7:4 8:4 9:5 10:6 11:8 12:8 13:8 
    vector<myObj> input = { {3, 2}, {6, 3}, {8, 4}, {9, 5}, {10, 6}, {13, 8}};

    int prev = 0;
    for(int i = 0; i < input.size(); i++) {
        for (int j = prev; j <= input[i].index; j++) {
            cout << j << ":" << input[i].val << " ";
            prev = j+1;
        }
    }
    cout << endl;

    cout << "10:" << get_val(input, 10) << endl;
    cout << "1:" << get_val(input, 1) << endl;
    cout << "5:" << get_val(input, 5) << endl;
    cout << "6:" << get_val(input, 6) << endl;
    cout << "0:" << get_val(input, 0) << endl;
    cout << "15:" << get_val(input, 15) << endl;
}
