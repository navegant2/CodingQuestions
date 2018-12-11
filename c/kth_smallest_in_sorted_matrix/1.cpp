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

int kthSmallest(vector<vector<int> >& matrix, int k) {
        int lo = matrix[0][0];
        int hi = matrix[matrix.size() - 1][matrix[0].size() - 1] + 1;//[lo, hi)
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            cout << "lo:" << lo << " hi:" << hi << " mid:" << mid << endl;
            int count = 0,  j = matrix[0].size() - 1;
            for(int i = 0; i < matrix.size(); i++) {
                while(j >= 0 && matrix[i][j] > mid) j--;
                count += (j + 1);
                cout << "i:" << i << " j:" << j << " count:" << count << endl;
            }
            if(count < k) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }

main() {
    vector<vector<int> > m(7, vector<int>(6));

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> m[i][j];
        }
    }
    cout << kthSmallest(m, 14) << endl;
}
