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

void union1(int v1, int v2) {
            if (!parents.count(v1)) {
                parents[v1] = v1;
                sizes[v1] = 1;
            }
            
            if (!parents.count(v2)) {
                parents[v2] = v2; 
                sizes[v2] = 1;
            }
            
            int p1 = find1(v1), p2 = find1(v2);
            if (p1 == p2) return;
            int s1 = sizes[p1], s2 = sizes[p2];
            if (s1 < s2) {
                parents[p1] = p2;
                sizes[p2] = s1 + s2;
                if (s1 + s2 > max1) max1 = s1 + s2;
            }else {
                parents[p2] = p1;
                sizes[p1] =  s1 + s2;
                if (s1 + s2 > max1) max1 = s1 + s2;
            }
        }
        
        int find1(int v) {
            while (parents[v] != v) {
                parents[v] =  parents[parents[v]];
                v = parents[v];
            }
            return v;
        }
        int max1;
         
         private:
        map<int, int> parents;
        map<int, int> sizes;
         
    };

// Complete the maxCircle function below.
vector<int> maxCircle(vector<vector<int>> queries) {
        UnionFind *uf = new UnionFind();
        vector<int> result;
        for (int i = 0; i < queries.size(); i++) {
            uf->union1(queries[i][0], queries[i][1]);
            result.push_back(uf->max1);
        }
        return result;


main() {


}
