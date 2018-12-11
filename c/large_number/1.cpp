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

 string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](string a, string b) {
            int a_len = a.size();
            int b_len = b.size();
            int i = 0, j = 0;
            while(i < a_len && j < b_len) {
                if (a[i] == b[j]) {
                    i++; j++;
                } else {
                    return a[i] > b[j];
                }
            }
            if (i != a_len) {
                return true;
            }
            return false;
        });
        
        string result;
        for(int i = 0; i < nums.size(); i++) {
            result += nums[i];
        }
        return result;
}

main() {
    int N;
    cin >> N;

    vector<string> nums(N);
    for (int i = 0; i < N;i++) {
        cin >> nums[i];
    }
    string result = largestNumber(nums);
    cout << result << endl;
}
