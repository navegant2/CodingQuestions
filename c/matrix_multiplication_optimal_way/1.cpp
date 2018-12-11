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


int get_min_multiplications_helper(int start, int end, vector<int> array) {

    cout << "start: " << start << " end:" << end << endl;
    if (start == end) {
        return 0;
    }
    int res = numeric_limits<int>::max();
    for (int i = start; i < end; i++) {
        int value = get_min_multiplications_helper(start, i, array) +
                    get_min_multiplications_helper(i+1, end, array) +
                    array[start-1] * array[i] * array[end];
       
        res = min(res, value);
    }
    cout << "result:" << res << endl;
    return res;
} 

int get_min_multiplications(vector<int> array) {

    return get_min_multiplications_helper(1, array.size()-1, array);

} 

main() {

    int N;
    cin >> N;
    vector<int> array;

    for (int i = 0; i <= N; i++) {
        int temp;
        cin >> temp;
        array.push_back(temp);
    }

    cout << "Min: " << get_min_multiplications(array) << endl;
         


}
