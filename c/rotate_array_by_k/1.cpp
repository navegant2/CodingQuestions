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


void swap_array(vector<int> &input, int start, int end) {

    int i = start; int j = end;
    while (i < j) {
        int temp = input[i];
        input[i] = input[j];
        input[j] = temp;
        i++; j--;
    }
}
void rotate_array(vector<int> &input, int k) {

    int size = input.size();
    swap_array(input, 0, size-k-1);
    swap_array(input, size-k, size-1);
    swap_array(input, 0, input.size()-1);

}

main() {
    int N;
    cin >> N;
    vector<int> input(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> input[i];
    }
    int k;
    cin >> k;
    rotate_array(input, k); 

    for (int i = 0; i < input.size(); i++) {
        cout << input[i] << " ";
    }
    cout << endl;
}
        
