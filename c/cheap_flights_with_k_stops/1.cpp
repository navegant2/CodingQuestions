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

        const int INF = 1e9;

void print_all(vector<vector<int> >ans, int rows, int cols) {

    for (int i = 1; i <= rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (ans[i][j] == INF) {
                cout << "-1 ";
            } else {
                cout << ans[i][j] << "  ";
            }
        }
        cout << endl;
    }
}
int findCheapestPrice(int n, vector<vector<int> >& flights, int src, int dst, int K)
    {
        K++;
        vector<vector<int> > ans(n, vector<int>(K+1));
        cout << "n:" << n << " K+1:" << K+1 << endl;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= K; j++)
            {
                ans[i][j] = INF;
            }
        }
        ans[src][0] = 0;
        for(int i = 1; i <= K; i++)
        {
            cout << "with " << i << " hops" << endl;
            for(int j = 0; j < n; j++)   //To update ans[j][i](using i steps), we copy ans[j][i-1] first
                ans[j][i] = ans[j][i-1];
            for(const vector<int>& f: flights)
            {
                cout << "considering src:" << f[0] << " des:" << f[1] << " with cost:" << f[2] << endl;
                ans[f[1]][i] = min(ans[f[1]][i], ans[f[0]][i-1] + f[2]);
                print_all(ans, K, n); 
            }
        }
        if(ans[dst][K] == INF) return -1;
        return ans[dst][K];
    }

main() {

    int N;
    cin >> N;
    vector<vector<int> > flights;

    for (int i = 0; i < N; i++) {
        vector<int> temp;
        int src, dest, cost;
        cin >> src; 
        cin >> dest; 
        cin >> cost; 

        temp.push_back(src);
        temp.push_back(dest);
        temp.push_back(cost);
    
        flights.push_back(temp);
    }
    int src, dest, max_k;
    cin >> src;
    cin >> dest;
    cin >> max_k;

    cout << "Result: " << findCheapestPrice(N, flights, src, dest, max_k) << endl;
}
