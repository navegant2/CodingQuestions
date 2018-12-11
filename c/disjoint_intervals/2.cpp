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
#include<iostream>
#include<limits>
#include<algorithm>
#include<list>

using namespace std;

string s;
vector<string> vs;
vector<int> vs1;
map<char,int> first;


struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
};

class SummaryRanges {

public:
    /** Initialize your data structure here. */
    void addNum(int val) {

        int start = val, end = val;
        list<Interval>::iterator it = st.begin();
        while (it != st.end()){
            if (val > it->end + 1) {
                it++;
                continue;
            } else if (val < it->start-1) {
                break;
            } 
            while (val >= it->start + 1 || val <= it->end-1) {
                start = min(it->start, val);
                end = max(it->end, val);
                st.erase(it);
            }
        }
        st.insert(it, Interval(start, end));
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> result;
        for (auto it = st.begin(); it != st.end(); it++) {
            result.push_back(Interval(it->start, it->end));
        }
        return result;
    }

    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
private:
    struct Cmp{
        bool operator()(Interval a, Interval b){ return a.start < b.start; }
    };

    list<Interval> st;
};

main() {

    SummaryRanges *r = new SummaryRanges();
    int total = 10;
    
    while(total) {
   
        int temp;
        cin >> temp; 
        r->addNum(temp);
        vector<Interval> output = r->getIntervals(); 
        for (int i = 0; i < output.size(); i++) {
            cout << "[" << output[i].start << ":" << output[i].end << "]";
        }
        cout << endl;
        total--;
    }
}
