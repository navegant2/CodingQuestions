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


int mycount(int v, int m, int n) {
        int counter = 0;
        for (int i = 1; i <= m; i++) {
            int temp = min(v / i , n);
            counter += temp;
            cout << "   i:" << i << " temp:" << temp << " counter:" << counter << endl;
        }
        return counter;
    }
    int findKthNumber(int m, int n, int k) {
        
        int low = 1 , high = m * n + 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            cout << "low:" << low << " high:" << high << " mid:" << mid << endl;
            int c = mycount(mid, m, n);
            if (c >= k) high = mid;
            else low = mid + 1;
        }
        
        return high;
    }

main() {

    int m, n, Kth;

    cin >> m;
    cin >> n;
    cin >> Kth;

    cout << "result is:" << findKthNumber(m, n, Kth);
}
