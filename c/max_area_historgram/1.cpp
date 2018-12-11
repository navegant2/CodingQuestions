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

int largestRectangleArea(vector<int>& height) {
    height.push_back(0);
    const int size_h = height.size();
    stack<int> stk;
    int i = 0, max_a = 0;
    while (i < size_h) {
        if (stk.empty() || height[i] >= height[stk.top()]) {
            cout << "Pushing i:" << i << " value:" << height[i] << endl;
            stk.push(i);
            i++;
        }
        else {
            int h = stk.top();
            stk.pop();
            cout << "top index:" << h << " value:" << height[h] << " i:" << i << endl; 
            int temp = stk.empty()?i:i - stk.top() - 1;
            int is_empty = stk.empty() == true;
            int temp2 = stk.empty()?i:stk.top();
            cout << "empty?" << is_empty << " top-i: " << temp2 << "-" << i << " x value:" << temp << " " <<  endl;
            max_a = max(max_a, height[h] * (stk.empty() ? i : i - stk.top() - 1));
            cout << "max_a: " << max_a << endl;
        }
    }
    return max_a;
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
    cout << "Result is : " << largestRectangleArea(nums) << endl;
}
