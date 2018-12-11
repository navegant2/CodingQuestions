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


class Solution {
public:
    static void combinationSumHelper(vector<int> candidates, int target, 
                              int partial_target, vector<int> *partial_result_ptr, vector<vector<int> > *result_ptr) {
        vector<vector<int> > &result = *result_ptr;
        vector<int> &partial_result = *partial_result_ptr;
        
        if (partial_target == target) {
            result.push_back(partial_result);
            return;
        }
        
        for (int i = 0; i < candidates.size(); i++) {
            if (partial_target + candidates[i] <= target) {
                partial_result.push_back(candidates[i]);
                combinationSumHelper(candidates, target, partial_target, partial_result_ptr, result_ptr);
            }
        }
    }
    static vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        combinationSumHelper(candidates, target, 0, new vector<int> , &result);
        return result;
    }
};


main() {

    int N;
    cin >> N;
    vector<int> candidates(N,0);

    for (int i  = 0; i < N; i++) {
        cin >> candidates[i];
    }

    int target = 0;
    cin >> target;
    vector<vector<int> > result = Solution::combinationSum(candidates, target);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] ;
        }
        cout << endl;
    }
}
