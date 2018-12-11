#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<deque>
#include<map>
#include<set>

using namespace std;

string s;
vector<string> vs;
vector<int> vs1;
map<char,int> first;


struct subarray {
    int start;
    int end;
};

subarray findsmallestsubarrayconverset(const vector<string>& paragraph, const unordered_set<string> &keywords) {

    
    unordered_map<string, int> keywords_to_cover;
    for (const string &keyword: keywords) {
        ++keywords_to_cover[keyword];
    }

    subarray result = subarray{-1, -1};

    for (int left = 0, right = 0; right < paragraph.size(); ++right) {
        if (keywords.count(paragraph[right] &&
                --keywords_to_cover[paragraph[right]] >= 0) {
            --remaining_to_cover;
        }

        while(remaining_to_cover == 0) {
            if (result.start == -1 && result.end == -1 ||
                right - left < result.end - result.start) {

                result = {left, right};
            }
            if (keywords.count(paragraph[left]) && ++keywords_to_cover[paragraph[left]] > 0) {
              ++remaining_to_cover;
            }
            ++left;
        }
    }
    return result;
}
    
main() {


}
