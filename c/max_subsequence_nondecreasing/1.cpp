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

int max_subsequence_nondecreasing(vector<int> array) {

    int i, j;
    vector<int> max_subsequence(array.size(),1);

    for (i = 1; i < array.size(); i++) {
        for (j = 0; j < i; j++) {
            if (array[j] <= array[i]) {
                max_subsequence[i] = max(1 + max_subsequence[j], max_subsequence[i]);
            }
        }
    }
    return *max_element(max_subsequence.begin(), max_subsequence.end());
}


main() {
    
    int N;
    cin >> N;
    vector<int> array(N);
    int i;
 
    for (i = 0; i < N; i++) {
        cin >> array[i];
    }
    int result = max_subsequence_nondecreasing(array);
    cout << result << endl;


}
