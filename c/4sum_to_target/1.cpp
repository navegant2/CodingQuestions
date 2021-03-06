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

 vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) {
            return result;
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            if (nums[i] + nums[n-1] + nums[n-2] + nums[n-3] < target) continue;
            if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
            for (int j = i+1; j < n-2; j++) {
                if (j > i+1 && nums[j] == nums[j-1] ) continue;
                if (nums[i] + nums[j] + nums[n-2] + nums[n-1] < target) continue;
                if (nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
                int start = j+1;
                int end = n-1;
                while(start < end) {
                    int sum_4 = nums[i] + nums[j] + nums[start] + nums[end];
                    if (sum_4 < target) {
                        start++;
                    } else if (sum_4 > target) {
                        end--;
                    } else {
                        result.push_back(vector<int>{nums[i], nums[j], nums[start], nums[end]});
                        do { start++; } while(nums[start] == nums[start-1] && start < end);
                        do { end--; } while(nums[end] == nums[end+1] && start < end);
                    }
                    
                }
            }
        }
        return result;
    }

main() {


}
