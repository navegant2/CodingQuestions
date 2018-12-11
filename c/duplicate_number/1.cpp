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

int get_duplicate(vector<int> nums) {

    int slow = nums[0];
    int fast = nums[nums[0]];

    cout << "slow:" << slow << " fast:" << fast << endl;
    
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
        cout << "slow:" << slow << " fast:" << fast << endl;
    }
    fast = 0;
    while (slow != fast) {
        cout << "slow:" << slow << " fast:" << fast << endl;
        slow = nums[slow];
        fast = nums[fast];
    }
        cout << "slow:" << slow << " fast:" << fast << endl;
    return slow;
}

main() {
    int N;
    cin >> N;
    vector<int> nums;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    cout << "Dup:" << get_duplicate(nums) << endl;
}
