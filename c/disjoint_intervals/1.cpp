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
        auto it = st.lower_bound(Interval(val, val));
        int start = val, end = val;

        cout << "Befor lower:" << it->start << "-" << it->end << endl;
        if(it != st.begin() && (--it)->end+1 < val) it++;
        cout << "After lower:" << it->start << "-" << it->end << endl;
        while(it != st.end() && val+1 >= it->start && val-1 <= it->end)
        {
            start = min(start, it->start);
            end = max(end, it->end);
            it = st.erase(it);
        }
        st.insert(it,Interval(start, end));
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> result;
        for(auto val: st) result.push_back(val);
        return result;
    }

    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
private:
    struct Cmp{
        bool operator()(Interval a, Interval b){ return a.start < b.start; }
    };
    set<Interval, Cmp> st;
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
