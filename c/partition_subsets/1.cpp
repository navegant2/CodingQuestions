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

bool canPartition(vector<int>& nums) {
       
        int sum = 0;
    
        for (int num : nums) {
            sum += num;
        }
    
        if ((sum & 1) == 1) {
            return false;
        }
        sum /= 2;
   
        cout << "sum:" << sum << endl;
 
        int n = nums.size();
        vector<bool> dp(sum+1, false);
        dp[0] = true;
    
        for (int num : nums) {
            for (int i = sum; i >= 0; i--) {
                cout << dp[i] << " ";
            }
            cout << endl;
            for (int i = sum; i > 0; i--) {
                if (i >= num) {
                    dp[i] = dp[i] || dp[i-num];
                }
            }
        }
        return dp[sum];
    }

main() {

    vector<int> input = { 5, 23 };

    if (canPartition(input)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}
