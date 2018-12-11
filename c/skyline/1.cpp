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

 struct point {
        int x;
        int h;
        bool is_end;
        
        point(int x1, int h1, bool is_end1) {
            x = x1;
            h = h1;
            is_end = is_end1;
        }
        bool operator() (const point *a, const point *b) {
            if (a->x == b->x) {
                if (a->is_end && b->is_end) {
                    return a->h < b->h; 
                } else if (!a->is_end && !b->is_end) {
                    return a->h > b->h; 
                } else if (!a->is_end) {
                    return true; 
                } else {
                    return false;
                }
            }
            return a->x < b->x;
        }
    };

    struct myCompare {
        bool operator()(const point *a, const point *b) {
            return a->h < b->h;
        }
    };
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
        vector<point *> points(buildings.size()*2);
        for (int i = 0; i < buildings.size(); i++) {
            points.push_back(new point(buildings[i][0], buildings[i][2], true));
            points.push_back(new point(buildings[i][1], buildings[i][2], false));
        }
        sort(points.begin(), points.end());
        vector<pair<int,int> > result;
        priority_queue<point *, vector<point *>, myCompare> heights_order; 
        
        for (int i = 0; i < points.size(); i++) {
            int prev_top = heights_order.top()->h;
            if (points[i]->is_end) {
                heights_order.pop(points[i]);
            } else {
                heights_order.push(points[i]);
            }
            if (prev_top != heights_order.top()->h) {
                result.push_back({points[i]->x, points[i]->h});
            }
        }
        return result;
    }

main() {


}
