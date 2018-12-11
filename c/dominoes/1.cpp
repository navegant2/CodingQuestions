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

 void fill_new_dominoes(int prev_i, int i, string& dominoes) {
      

cout << "prev_i:" << prev_i << " i:" << i << " dominoes:" << dominoes << endl;
 
        if (prev_i == -1) {
            if (dominoes[i] == 'R') {
                return;
            } else {
                for (int j = 0; j < i; j++) {
                    dominoes[j] = 'L';
                }
            }
        } else {
            if (prev_i + 1 == i) {
                return;
            }
            if (dominoes[prev_i] == 'L' && dominoes[i] == 'L') {
                for (int j = prev_i+1; j < i; j++) {
                    dominoes[j] = 'L';
                }
            } else if (dominoes[prev_i] == 'L' && dominoes[i] == 'R') {
                // do nothing
            } else if (dominoes[prev_i] == 'R' && dominoes[i] == 'R') {
                // do nothing
            } else { // R & L on either sides
                int left = prev_i + 1;
                int right = i-1;
                while(left < right) {
                    dominoes[left++] = 'R';
                    dominoes[right--] = 'L';
                }
            }
        }
        
    }
    string pushDominoes(string dominoes) {
        int prev_i = -1;
        int idx = 0;
        string new_dominoes = dominoes;

        for (int i = 0; i < new_dominoes.size(); i++) {
            if (new_dominoes[i] != '.') {
                fill_new_dominoes(prev_i, i, new_dominoes);
                prev_i = i;
            }
        }
        if (prev_i == 'R' && prev_i < new_dominoes.size()) {
            for (int j = prev_i+1; j < new_dominoes.size(); j++) {
                new_dominoes[j] = 'R';
            }
        }
        return new_dominoes;
    }
main() {

    string s;
    cin >> s;

    cout << pushDominoes(s) << endl;
}
