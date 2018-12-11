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


int minCostClimbingStairs(vector<int>& cost) {
        int n=(int)cost.size();
        vector<int> dp(n);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for (int i=2; i<n; ++i)
            dp[i]=cost[i]+min(dp[i-2],dp[i-1]);
        return min(dp[n-2],dp[n-1]);
}
main() {

    int N;
    cin >> N;
    vector<int> costs;
    for (int i = 0; i < N; i++) {
        int temp = 0;
        cin >> temp;
        costs.push_back(temp);
    }
    int result = minCostClimbingStairs(costs);
    cout << result << endl;
}
