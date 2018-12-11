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

int findKthNumber(int m, int n, int Kth) {
        
        int lo = 0; 
        int hi = m * n + 1;
        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            int index = 0;
           
            cout << "lo:" << lo << " hi:" << hi << " mid:" << mid << endl; 
            for (int i = 1; i <= m; i++) {
                int j = n;
                while(j >= 1 && i * j > mid) j--;
                index += j;
                cout << "i:" << i << " j:" << j << " index:" << index << endl; 
            }
            
            if (index < Kth) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }

main() {

    int m, n, Kth;

    cin >> m;
    cin >> n;
    cin >> Kth;

    cout << "result is:" << findKthNumber(m, n, Kth);
}
