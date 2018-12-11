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

vector<string> number_comb = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

void get_combinations_of_phone_helper(string number, int offset, vector<string> &output, string partial_result) {

    if (offset == number.size()) {
        output.push_back(partial_result);
        return;
    }

    for (int i = 0; i < number_comb[number[offset]-'0'].size(); i++) {
        get_combinations_of_phone_helper(number, offset+1, output, partial_result + number_comb[number[offset]-'0'][i]);
    }
}

    

vector<string> get_combinations_of_phone(string number) {

    vector<string> output;
    get_combinations_of_phone_helper(number, 0, output, "");
    return output;
}
main() {

    string numbers;
    cin >> numbers;

    vector<string> output = get_combinations_of_phone(numbers);
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << endl;
    }
}
